import gym
 
 
def main():
    env = gym.make('CartPole-v1',render_mode="rgb_array")
    for i_episode in range(20):
        observation = env.reset()
        for t in range(100):
            env.render()
            print(observation)
            action = env.action_space.sample()
            observation, reward, terminated, truncated, info  = env.step(action)
            if  terminated:
                print("Episode finished after {} timesteps".format(t + 1))
                break
 
 
if __name__ == "__main__":
    main()