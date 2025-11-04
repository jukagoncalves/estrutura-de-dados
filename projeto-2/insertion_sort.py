# insertion_sort.py

def insertion_sort(arr_in):
    """
    Ordena uma lista usando Insertion Sort.
    Retorna a lista ordenada e um dicionário de estatísticas.
    Usa "movimentos" em vez de "trocas" para maior precisão.
    """
    arr = list(arr_in)
    stats = {"comparacoes": 0, "movimentos": 0}

    # Começa do segundo elemento (índice 1)
    for i in range(1, len(arr)):
        chave = arr[i]
        j = i - 1
        
        # Comparação inicial (pode não entrar no while)
        stats["comparacoes"] += 1 
        
        # Move elementos da sub-lista ordenada que são maiores que a chave
        while j >= 0 and chave < arr[j]:
            stats["comparacoes"] += 1 # Conta comparações dentro do loop
            arr[j + 1] = arr[j] # Deslocamento
            stats["movimentos"] += 1
            j -= 1
        
        # Insere a chave na sua posição correta
        arr[j + 1] = chave
        stats["movimentos"] += 1 # Conta a inserção final
        
    return arr, stats