import random

size = random.randint(0, 500)
#size = 5

nb_list = random.sample(range(1, size + 1), size)
print(str(' '.join(str(e) for e in nb_list)))
