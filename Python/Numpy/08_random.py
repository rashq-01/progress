import numpy as np

# rng = np.random.default_rng()

# print(rng.integers(low=1,high=100,size=(3,2)))

# rng = np.random.default_rng(seed=1)
# print("\n\n\n")

# print(rng.integers(low=1,high=100,size=(3,2)))

# np.random.seed(seed=1)

# print(np.random.uniform(low=-1,high=1,size=(3,2)))


rng = np.random.default_rng()


arr = np.array([1,2,3,4,5])
rng.shuffle(arr)
print(arr)


fruit = np.array(["Apple","Orange","Banana","Coconut","Pineapple"])

fruit = rng.choice(fruit,size=(2,3))
print(fruit)