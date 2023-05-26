// A) Qual é o resultado do percurso Pre-Order (VLR) na árvore?
// Resposta: 10 5 3 7 20 15 24

// B) Explique quais são os passos realizados pelo algoritmo de Morris - Percurso PRE-ORDER:
// Resposta:
// 1. Inicialize um ponteiro "p" apontando para a raiz da árvore.
// 2. Enquanto "p" não for nulo, execute os seguintes passos:
//     3. Verifique se "p->left = 0".
//         - Se for nulo, significa que não temos mais nós à esquerda para percorrer. Portanto, imprima o conteúdo do nó "p" e faça "p = p->right" para continuar o algoritmo.
//         - Se não for nulo, siga para o próximo passo.
//     4. Faça o ponteiro temporário "tmp" apontar para "p->left".
//     5. Enquanto "tmp->right != 0" e "tmp->right != p", percorra os nós à direita de "tmp".
//         Obs: Este passo é realizado para encontrar o nó mais à direita, que posteriormente apontará para a "raiz atual" e também restaurará a estrutura da árvore.
//     6. Verifique se "tmp->right" é nulo.
//         - Se for nulo, significa que ainda não visitamos o nó atual. Portanto, imprima o conteúdo de "p" (raiz atual), faça "tmp->right" apontar para "p" (raiz atual) e faça "p" ir para o seu nó esquerdo.
//             Obs: Esta etapa conecta o nó mais à direita à "raiz atual", que será usado para restaurar a estrutura da árvore, encerrando a conexão entre "tmp->right" e a "raiz atual".
//         - Se não for nulo, faça "tmp->right = 0" e faça "p = p->right".
//             Obs: Esta etapa indica que o nó atual já foi percorrido, já está conectado à "raiz atual" e podemos imprimi-lo. Em seguida, encerramos a conexão entre o nó atual e a "raiz atual" para restaurar a estrutura da árvore.

// C) Aplique a árvore no algoritmo e verifique se o resultado está correto.
// Resposta: O algoritmo funcionou corretamente.