# quick_sort.py

def _partition(arr, inicio, fim, stats):
    """
    Função de partição (usando esquema de Lomuto).
    O pivô é escolhido como o último elemento.
    """
    pivo = arr[fim]
    i = inicio - 1 # Índice do menor elemento

    for j in range(inicio, fim):
        stats["comparacoes"] += 1
        if arr[j] < pivo:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
            stats["trocas"] += 1
    
    # Coloca o pivô na posição correta
    arr[i + 1], arr[fim] = arr[fim], arr[i + 1]
    stats["trocas"] += 1
    return i + 1

def _quick_sort_recursivo(arr, inicio, fim, stats):
    """ Função recursiva principal do Quick Sort. """
    if inicio < fim:
        # Encontra o pivô
        pivo_idx = _partition(arr, inicio, fim, stats)
        # Ordena as duas sub-listas
        _quick_sort_recursivo(arr, inicio, pivo_idx - 1, stats)
        _quick_sort_recursivo(arr, pivo_idx + 1, fim, stats)

def quick_sort(arr_in):
    """
    Função 'wrapper' para o Quick Sort.
    Ordena a lista e retorna estatísticas.
    """
    arr = list(arr_in)
    stats = {"comparacoes": 0, "trocas": 0}
    _quick_sort_recursivo(arr, 0, len(arr) - 1, stats)
    return arr, stats