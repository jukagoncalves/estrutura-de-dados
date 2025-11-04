# selection_sort.py

def selection_sort(arr_in):
    """
    Ordena uma lista usando Selection Sort.
    Retorna a lista ordenada e um dicionário de estatísticas.
    """
    arr = list(arr_in)
    stats = {"comparacoes": 0, "trocas": 0}
    n = len(arr)

    for i in range(n):
        # Encontra o índice do menor elemento restante
        min_idx = i
        for j in range(i + 1, n):
            stats["comparacoes"] += 1
            if arr[j] < arr[min_idx]:
                min_idx = j
        
        # Realiza a troca (apenas se um novo mínimo foi encontrado)
        if min_idx != i:
            arr[i], arr[min_idx] = arr[min_idx], arr[i]
            stats["trocas"] += 1
            
    return arr, stats