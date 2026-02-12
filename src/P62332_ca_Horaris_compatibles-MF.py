from yogi import tokens, read
"""
Observació:
Una possible solució O(n log n) ordena els intervals
per inici i després només cal comprovar que cada
interval no es solapa amb l'anterior
"""
def compatibles(L):
    for i in range(len(L) - 1):
        if L[i][1] > L[i + 1][0]:
            return False
    return True
for n in tokens(int):
    L = [(read(int), read(int)) for _ in range(n)]
print('si' if compatibles(sorted(L)) else 'no')