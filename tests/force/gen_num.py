import random

# size = random.randint(0, 500)
size = 5


size += 1
nb_list = random.sample(range(1, size), size - 1)
print(str(' '.join(str(e) for e in nb_list)))
