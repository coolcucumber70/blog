import numpy as np
import random

# 建立 Q 表
q = np.zeros((6, 6))
q = np.matrix(q)

# 建立 R 表

r = np.array([[-1, -1, -1, -1, 0, -1], [-1, -1, -1, 0, -1, 100], [-1, -1, -1, 0, -1, -1], [-1, 0, 0, -1, 0, -1],
              [0, -1, -1, 0, -1, 100], [-1, 0, -1, -1, 0, 100]])
r = np.matrix(r)

# 贪婪指数
gamma = 0.8

# 训练

for i in range(100000):
    # 对每一个训练,随机选择一种状态
    state = random.randint(0, 5)
    while state != 5:
        # 选择r表中非负的值的动作
        actions = []
        for a in range(6):
            if r[state, a] >= 0:
                actions.append(a)
        action = actions[random.randint(0, len(actions) - 1)]

        R = r[state, action]
        next_state = action
        actions = []
        for a in range(6):
            if r[next_state, a] >= 0:
                actions.append(a)

        next_action = actions[random.randint(0, len(actions) - 1)]
        q[state, action] = R + gamma * q[next_state, next_action]//每走一步,就算一遍q,全程确实是值迭代呀

        state = next_state
        action = next_action

print(q)
# 验证

for i in range(10):
    print("第{}次验证".format(i + 1))

    state = random.randint(0, 2)
    print('机器人处于{}'.format(state))
    count = 0
    while state != 5:
        if count > 20:
            print('fail')
            break
        # 选择最大的q_max
        q_max = q[state].max()

        q_max_action = []
        for action in range(6):
            if q[state, action] == q_max:
                q_max_action.append(action)

        next_state = q_max_action[random.randint(0, len(q_max_action) - 1)]
        print("the robot goes to " + str(next_state) + '.')
        state = next_state
        count += 1
##Q学习方法
for i in range(10):
    print("第{}次验证".format(i + 1))

    state = random.randint(0, 2)
    print('机器人处于{}'.format(state))
    count = 0
    while state != 5:
        if count > 20:
            print('fail')
            break
        # 选择最大的q_max
        q_max = q[state].max()

        q_max_action = []
        for action in range(6):
            if q[state, action] == q_max:
                q_max_action.append(action)

        next_state = q_max_action[random.randint(0, len(q_max_action) - 1)]
        print("the robot goes to " + str(next_state) + '.')
        state = next_state
        count += 1