# bubble_sort.py

def bubble_sort(arr_in):
    """
    Ordena uma lista usando Bubble Sort otimizado (para cedo se já ordenado).
    Retorna a lista ordenada e um dicionário de estatísticas.
    """
    arr = list(arr_in) # Copia para não modificar o original
    stats = {"comparacoes": 0, "trocas": 0}
    n = len(arr)

    for i in range(n):
        trocou = False
        # A última i posições já estão no lugar
        for j in range(0, n - i - 1):
            stats["comparacoes"] += 1
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                stats["trocas"] += 1
                trocou = True
        
        # OTIMIZAÇÃO: Se não houve trocas na passagem interna, 
        # a lista já está ordenada e podemos parar.
        if not trocou:
            break
            
    return arr, stats