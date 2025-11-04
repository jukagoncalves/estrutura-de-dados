# Seminário de Estrutura de Dados I: Análise de Algoritmos de Ordenação
## Disciplina de Estrutura de Dados I (Prof. Dr. Johnatan Oliveira)

Este projeto contém as implementações em Python dos cinco algoritmos de ordenação solicitados para o seminário, instrumentados para análise de performance.

### Algoritmos Implementados
1.  **Bubble Sort** (Otimizado)
2.  **Selection Sort**
3.  **Insertion Sort**
4.  **Quick Sort** (Partição de Lomuto, pivô no final)
5.  **Merge Sort**

### Estrutura dos Arquivos

O projeto está dividido em 6 arquivos Python, seguindo uma abordagem modular:

* `bubble_sort.py`: Contém a implementação instrumentada do Bubble Sort.
* `selection_sort.py`: Contém a implementação instrumentada do Selection Sort.
* `insertion_sort.py`: Contém a implementação instrumentada do Insertion Sort.
* `quick_sort.py`: Contém a implementação instrumentada do Quick Sort.
* `merge_sort.py`: Contém a implementação instrumentada do Merge Sort.
* `run_experiment.py`: Este é o **script principal** (runner). Ele importa os 5 algoritmos e executa o mini-experimento com $N=1000$, gerando a Tabela Comparativa e os Insights Analíticos.

### Requisitos

* Python 3.x

### Instruções de Execução

Para rodar o mini-experimento e gerar a análise de performance:

1.  Certifique-se de que todos os 6 arquivos Python (`bubble_sort.py`, `selection_sort.py`, `insertion_sort.py`, `quick_sort.py`, `merge_sort.py` e `run_experiment.py`) estejam no **mesmo diretório**.
2.  Abra um terminal ou prompt de comando.
3.  Navegue até o diretório onde os arquivos estão localizados.
4.  Execute o script principal `run_experiment.py`:

    ```bash
    python run_experiment.py
    ```

5.  O script levará alguns segundos para processar todos os algoritmos (especialmente os $O(n^2)$) e, em seguida, imprimirá no console:
    * A **Tabela Comparativa** com os resultados de $N=1000$.
    * Os **Insights Analíticos** para cada algoritmo.