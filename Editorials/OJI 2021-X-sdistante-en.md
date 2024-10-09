

Let $N$ be the length of the string $s$.

### Solution in $O(N^4)$ – 11-16 points depending on implementation
For this solution, it is enough to find a simple algorithm for calculating the distance between two subsequences and apply it to all pairs of subsequences. We observe that $\text{dist}(a, b)$ is the number of positions $i$ for which $a(i)$ is different from $b(i)$ ($0 \leq i < \text{len}(a)$). With this observation, we obtain a linear algorithm that will be applied to $O(N^3)$ pairs of strings (all pairs $(i, i + \text{len})$; $(j, j + \text{len})$, $0 < i < j < \text{len}(s)$; $i + \text{len} < \text{len}(s)$), resulting in a $O(N^4)$ complexity algorithm.

#### Algorithm 1: Brute-force Solution
```text
N = length(s)
answer = 0
for i = 0 to N - 1 do
    for j = i + 1 to N - 1 do
        for len = 1 to N - j do
            for index = 0 to len do
                if s(i + index) != s(j + index) then
                    answer = (answer + 1) mod 1,000,000,007
```

### Solution in $O(N^3)$ – 31 points
We try to optimize the previous solution. We observe that a triplet $(i, j, \text{index})$ contributes multiple times to the answer. More precisely, if $s(i + \text{index}) \neq s(j + \text{index})$, then we add 1 to the answer for all values of $\text{len}$ greater than or equal to $\text{index}$. Thus, we can skip the iteration with the variable $\text{len}$ and instead add to the answer the number of values of $\text{index}$ for which 1 is added when verifying $s(i + \text{index}) \neq s(j + \text{index})$. By calculating precisely, we add $N - (j + \text{index})$ to the answer for each triplet that satisfies the previous property, thus obtaining a $O(N^3)$ complexity algorithm.

### Solution in $O(N^2)$ – 67 points
Similarly to the previous step, we will attempt to fix a particular pair of indices with different characters and observe their contribution to the result. To do this, we will rewrite the conditions based on the positions we are comparing and the conditions under which the rest of the variables are valid.

Let $a$ and $b$, where $a < b$, be the positions we compare at each step. We write the conditions so that $i, j, \text{len}, \text{index}$ are valid:

$$
\begin{aligned}
    a &= i + \text{index} \\
    b &= j + \text{index} \\
    i &\geq 0 \\
    j + \text{len} < N
\end{aligned}
$$

We rewrite the indices in terms of the positions we are comparing:

$$
\begin{aligned}
    i &= a - \text{index} \\
    j &= b - \text{index} \\
    a - \text{index} &\geq 0 \\
    N - \text{len} < b - \text{index}
\end{aligned}
$$

We notice that $i$ and $j$ are uniquely determined if we know all values of $a, b, \text{len}, \text{index}$, so it is not necessary to keep the first two equations to check the validity of a solution. Thus, if we fix $a$ and $b$, the conditions that $\text{len}$ and $\text{index}$ must satisfy for validity are:

$$
\begin{aligned}
    \text{index} &\leq a \\
    \text{len} - \text{index} &< N - b
\end{aligned}
$$

This system has $(a + 1) \times (N - b)$ solutions, which are pairs of natural numbers (any value from 0 to $a$ is valid for $\text{index}$, and for $\text{len} - \text{index}$, we can choose any value from 0 to $N - b - 1$, uniquely determining a valid value of the variable $\text{len}$ for any fixed value of the variable $\text{index}$). Thus, the pair $(a, b)$ contributes with $(a + 1) \times (N - b)$ to the answer.

### Solution in $O(N \times \sigma)$, where $\sigma$ is the size of the alphabet – 82 points
We will fix only the position $b$ and attempt to find its contribution to the answer. This will be $(a_1 + 1) \times (N - b) + (a_2 + 1) \times (N - b) + \dots + (a_k + 1) \times (N - b)$, where $a_1, a_2, \dots, a_k$ are the indices for which $s(b) \neq s(a_i)$ and $a_i < b$. If we factor out $(N - b)$, we get:

$$
[(a_1 + 1) + (a_2 + 1) + \dots + (a_k + 1)] \times (N - b)
$$

Thus, the problem reduces to efficiently calculating the sum $(a_1 + 1) + (a_2 + 1) + \dots + (a_k + 1)$. To compute the sum of these indices, we will use the property that they contain a value different from $s(b)$. We can maintain an array of sums $\text{sum}(c)$, which contains the sum of $i + 1$ for indices $i$ smaller than the current $b$ for which $s(i) = c$. This array can be updated in $O(1)$ at each step by adding $b + 1$ to $\text{sum}(s(b))$. When we want to obtain the sum of the $a$ values from the above expression, we simply sum all the values $\text{sum}(c)$, where $c \neq s(b)$, which can be done in $O(\sigma)$.

### Solution in $O(N)$ – 100 points
We observe that the sum $a_1 + a_2 + \dots + a_k$ is actually $1 + 2 + 3 + \dots + (b - 1) - (b_1 + b_2 + \dots + b_l)$, where $b_1, b_2, \dots, b_l$ are all the positions with the property $b_i < b$ and $s(b_i) = s(b)$ (we can subtract the sum of all previous positions with the same character as $s(b)$, and we are left with the sum of those that are different). Similarly:

$$
(a_1 + 1) + (a_2 + 1) + \dots + (a_k + 1) = (0 + 1) + (1 + 1) + (2 + 1) + \dots + ((b - 1) + 1) - ((b_1 + 1) + (b_2 + 1) + \dots + (b_l + 1))
$$

The previous sum can be rewritten, using the sum array, as:

$$
\frac{b \times (b + 1)}{2} - \text{sum}(b)
$$

This expression can be calculated in $O(1)$, leading to a final complexity of $O(N)$.

Alternatively, we can initially calculate how much the answer would be if all characters in the string were different and then subtract the number of "matches" (equal characters in the same position in two subsequences) between pairs of subsequences, using a similar implementation that employs the same sum array.
