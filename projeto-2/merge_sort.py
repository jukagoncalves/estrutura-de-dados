# merge_sort.py

def _merge_sort_recursivo(arr, stats):
    """ Função recursiva principal do Merge Sort. """
    if len(arr) > 1:
        meio = len(arr) // 2
        metade_esquerda = arr[:meio]
        metade_direita = arr[meio:]

        # Chamadas recursivas para dividir
        _merge_sort_recursivo(metade_esquerda, stats)
        _merge_sort_recursivo(metade_direita, stats)

        # --- Etapa de Mesclagem (Merge) ---
        i = j = k = 0 # Índices para esquerda, direita e principal
        
        while i < len(metade_esquerda) and j < len(metade_direita):
            stats["comparacoes"] += 1
            if metade_esquerda[i] < metade_direita[j]:
                arr[k] = metade_esquerda[i]
                stats["movimentos"] += 1
                i += 1
            else:
                arr[k] = metade_direita[j]
                stats["movimentos"] += 1
                j += 1
            k += 1

        # Copia os elementos restantes da metade_esquerda (se houver)
        while i < len(metade_esquerda):
            arr[k] = metade_esquerda[i]
            stats["movimentos"] += 1
            i += 1
            k += 1

        # Copia os elementos restantes da metade_direita (se houver)
        while j < len(metade_direita):
            arr[k] = metade_direita[j]
            stats["movimentos"] += 1
            j += 1
            k += 1

def merge_sort(arr_in):
    """
    Função 'wrapper' para o Merge Sort.
    Ordena a lista e retorna estatísticas.
    """
    arr = list(arr_in)
    stats = {"comparacoes": 0, "movimentos": 0}
    _merge_sort_recursivo(arr, stats)
    return arr, stats