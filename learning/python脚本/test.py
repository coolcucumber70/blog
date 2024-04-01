
sample example
## 策略迭代
import numpy as np
import pprint
import sys
if "../" not in sys.path:
    sys.path.append("../")
from lib.envs.gridworld import GridworldEnv # 这个Gridworld环境是构建好的，直接导入
pp = pprint.PrettyPrinter(indent=2)
env = GridworldEnv()
# First, do the policy evaluation 首先进行随机策略的评估
def policy_eval(policy, env, discount_factor=1.0, theta=0.00001):
    # Evaluate a policy given an environment and a full description of the environment's dynamics.环境信息已知
    # Args:
    #     policy:[S,A] shaped matrix representing the policy. 策略就是从状态到行动的映射，随机策略的话这里每个方向都是1/4
    #     env. OpenAI env. env.P represents the transition probabilities of the environment.
    #         env.P[s][a] is a (prob, next_state, reward, done) tuple
    #     thetha: We stop evaluation once our value function change is less than theta for all states.如果前后两次的变化很小，小于这个门槛，那么认为已经收敛了
    # Returns:
    #     Vector of length env.nS representing the value function.返回一个价值函数列表
    V = np.zeros(env.nS)
    #print ("env.nS is", env.nS) 哪里不清楚的就print一下看看
    #print V
    #i = 0
    while True:
        delta = 0
        # For each state, perform a "full backup"
        for s in range(env.nS):
            v = 0
            # Look at the possible next actions
            for a, action_prob in enumerate(policy[s]):
                #print a, action_prob 这里print出来就是上下左右，概率都是1/4
                # For each action, look at the possible next states..
                for prob, next_state, reward, done in env.P[s][a]:
                    #print env.P[s][a]
                    # Calculate the expected value 计算该策略下的价值函数
                    v += action_prob * prob * (reward + discount_factor * V[next_state])
                    #i = i + 1
            # How much our value function changed (across any states)
            #print i, delta, v, V[s]
            delta = max(delta, np.abs(v , V[s])) #整体来讲，这个delta是先变大，后来经过不断迭代逐渐变小，理论上趋于零的时候就是收敛的时候
            #delta = np.abs(v - V[s])
            #print v,V[s]
            V[s] = v 
        # Stop evaluating once our value function change is bellow a threshold 
        if delta < theta:
            break
    return np.array(V) # 最终，随机策略下的价值函数出炉

random_policy = np.ones([env.nS, env.nA]) / env.nA
v = policy_eval(random_policy, env)

print ("Value Function")
print (v)
print ("")
print ('Reshaped Grid Value Function:')
print (v.reshape(env.shape))
print ("")

# Second, do the policy improvement 接下来通过策略迭代实现策略提升
def policy_impr(env, policy_eval_fn=policy_eval, discount_factor=1.0):
    # policy Improvement Algorithm. Iteratively evaluates and improves a policy until an optimal policy is found.
    # Args:
    #     env: The OpenAI environment.
    #     policy_eval_fn: Policy Evaluation function that takes 3 arguments: policy, env, discount_factor. 这里要用到我们上边策略评估的结果
    #     discount_factor: Lambda discount factor
    # Returns:
    #     A tuple(policy, V) 返回最优策略和最优价值函数
    #     policy is the optimal policy, a matrix of shape [S,A],
    #         where each state s contains a valid probability distribution over actions.
    #     V is the value function for the optimal policy.
    # start with a random policy
    policy = np.ones([env.nS, env.nA])/env.nA # 随机策略的产生
    while True:
        # Evaluate the current policy
        V = policy_eval_fn(policy, env, discount_factor)
        # Will be set to false if we make any changes to the policy
        policy_stable = True
        # For each state ...
        for s in range(env.nS):
            # The best action we would take under the current policy
            chosen_a = np.argmax(policy[s])
            # Find the best action by one-step lookahead 
            # Ties are resolved arbitarily
            action_values = np.zeros(env.nA)
            for a in range(env.nA):
                for prob, next_state, reward, done in env.P[s][a]:
                    action_values[a] += prob * (reward + discount_factor * V[next_state])
            best_a = np.argmax(action_values)
            # Greedily update the policy
            if chosen_a != best_a:
                policy_stable = False
            policy[s] = np.eye(env.nA)[best_a] #这里的思想就是我开始先选一个行动（chosen_a），如果这个行动和我经过计算得到的这个能产生最大价值函数的best_a一致的话，那就是它啦！如果不是，那就是不稳定，那就再继续循环找，直到找到后break
            # print "env.nA:", env.nA
            # print np.eye(env.nA)
            # print best_a
            # print policy[s]
        # If the policy is stable, we've found an optimal policy , return it
        if policy_stable:
            return policy, V
policy, v = policy_impr(env)
print ("Policy Probability Distribution")
print (policy)
print ("")
print ("Reshaped Grid policy (0=up, 1=right, 2=down, 3=left):")
print (np.reshape(np.argmax(policy, axis=1), env.shape))
#print np.argmax(policy, axis=1)
print ("")
print ("Value Function:")
print (v)
print ("")
print ("Reshaped Grid Value Function:")
print (v.reshape(env.shape))
print ("")

##值迭代

def value_iteration(env, theta=0.0001, discount_factor=1.0):
    # Value Iteration Algorithm.
    #
    # Args:
    #     env: OpenAI environment. env.P represents the transition probabilities of the environment.
    #     theta: Stopping threshold. If the value of all states changes less than theta in one iteration we are done.
    #     discount_factor:lambda time discount factor.
    #
    # Returns:
    #     A tuple (policy, V) of the optimal policy and the optimal value function.
    def one_step_lookahead(state, V):
        # Helper function to calculate the value for all action in a given state.
        #
        # Args:
        #     state: The state to consider(int)
        #     V: The value to use as an estimator, Vector of length env.nS
        #
        # Returns:
        #     A vector of length env.nA containing the expected value of each action.
        A = np.zeros(env.nA)
        # print "env.nA:",env.nA
        # print "A:", A
        for a in range(env.nA):
            for prob, next_state, reward, done in env.P[s][a]:
                A[a] += prob * (reward + discount_factor * V[next_state])            
        return A

    V = np.zeros(env.nS)
    while True:
        # Stopping condition
        delta = 0
        # Update each state...
        for s in range(env.nS):
            # Do a one-step lookahead to find the best action
            A = one_step_lookahead(s,V)
            best_action_value = np.max(A)
            # Calculate delta across all states seen so far
            delta = max(delta, np.abs(best_action_value - V[s]))
            # Update the value function
            V[s] = best_action_value #迭代找到最优行动的价值函数，这是直接把Q给了V了
        # Check if we can stop
        if delta < theta:
            break

    # Creat a deterministic policy using the optimal value function
    policy = np.zeros([env.nS, env.nA])
    for s in range(env.nS):
        # One step lookahead to find the best action for this state
        A = one_step_lookahead(s,V)
        best_action = np.argmax(A)
        # Always take the best action
        policy[s, best_action] = 1.0 #往哪走最好就把其赋值1
    return policy, V

policy, v = value_iteration(env)

print ("Policy Probability Distribution:")
print (policy)
print ("")
print ("Reshaped Grid Policy (0=up, 1=right, 2=down, 3=left):")
print (np.reshape(np.argmax(policy,axis=1), env.shape))
print ("")
print ("Reshaped Grid Value Function:")
print (v.reshape(env.shape))
print ("")