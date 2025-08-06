// https://leetcode.com/problems/regular-expression-matching/

// 10. Regular Expression Matching

// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

// Example 1:
// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".

// Example 2:
// Input: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

// Example 3:
// Input: s = "ab", p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".

// Constraints:
// 1 <= s.length <= 20
// 1 <= p.length <= 20
// s contains only lowercase English letters.
// p contains only lowercase English letters, '.', and '*'.
// It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

/*
Casos que se pueden dar:
a*b y aab -> En este caso haces:
    a - a -> tienes que mirar si el siguiente caracter es un asterisco, y como es así, no avanzas el puntero del patron
    a - a -> tienes que mirar si el siguiente caracter es un asterisco, y como es así, no avanzas el puntero del patron
    b - a -> aqui no coinciden, pero tienes que mirar si el siguiente caracter es un asterisco, y como es así, tienes que avanzar hasta el caracter de la derecha del asterisco. Entonces avanzas hasta b y comparas b - b
    Entonces llegas al final y chim pun

a*aab y aaab -> En este caso haces
    a - a -> miras asterisco y no avanzas, pero validas una a, osea que te guardas en una variable el caracter que se ha validado y los caracteres que ha validado el asterisco (c = 'a', var = 1)
    a - a -> miras asterisco y no avanzas, ¿c == 'a'?, si es así, var = 2. Si no, c = "nuevo", var = 1
    a - a -> miras asterisco y no avanzas, ¿c == 'a'?, si es así, var = 3. Si no, c = "nuevo", var = 1
    b - a -> no coincide, pero asterisco, avanzas dos. Entonces comparas c == "sig" && var >= 0. Mientras esto se cumpla, haces var-- y avanzas. Ahora, si te sales del bucle porque c != "sig", comparas "sig" == b, y si esto es verdad, entonces has validado b y chill. Si no es así, es porque te has salido por var < 0, lo que significa que no has llegado al minimo de caracteres después del asterisco (en este caso no has puesto dos a's)

Logica del punto: valida cualquier caracter, osea que realmente solo nos tenemos que preocupar cuando hay un asterisco, porque toda la lógica de var no se cumple aquí. De hecho, cuando hay un .*, eso entra en un bucle infinito, y si hay cosas a la derecha, entonces tenemos miedo.

Esto me da a entender que podemos tener dos punteros, uno apuntando al inicio y otro al final. 

Pero este approach tampoco me sirve, porque a nada que tengamos dos cosas de estas en el patron ("a.*b.*c") se nos rompe la cosa

¿Y si empezasemos por el final? ¿Puede que los ".*" sean como checkpoints que tengamos en el patron?


Vale, la idea es usar recursion para una solucion NO optima, y luego intentar optimizarla con programacion dinamica (tablita para recordar casos anteriores)
La idea recursiva es tener un caso base de cadenas vacías (if pattern.size() == 0 return text.size() == 0) y un caso recursivo

El caso recursivo se compone de dos subcasos dependiendo de si estamos con una clausura o no. 
Si en el siguiente caracter tenemos un asterisco entonces:
    - Puede que el asterisco funcione, por lo que no tendremos que avanzar el puntero
    - O puede que el asterisco no valide nada, por lo que tendremos que avanzar el puntero dos posiciones (saltando el *)
En otro caso:
    - Avanzamos el puntero y chill
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> visitado;
vector<vector<bool>> res;

class Solution {
private:
    static bool dp(int i, int j, string s, string p) {
        if (visitado[i][j]) {
            return res[i][j];
        }
        visitado[i][j] = true;
        bool ans;
        if (j == p.length()) {
            ans = i == s.length();
        } else {
            bool match = (i < s.length() && (p[j] == s[i] || p[j] == '.'));
            if (j + 1 < p.length() && p[j+1] == '*') {
                ans = (dp(i, j + 2, s, p) || (match && dp(i + 1, j, s, p)));
            } else {
                ans = match && dp(i + 1, j + 1, s, p);
            }
        }
        res[i][j] = ans;
        return ans;
    }
public:
    static bool isMatch(string s, string p) {
        int n = s.size(), m = p.size(); 
        res = vector(n+1, vector(m+1, false));
        visitado = vector(n+1, vector(m+1, false));
        return dp(0, 0, s, p);
    }

    // static bool isMatch(string s, string p) {
    //     // Caso base
    //     if (p.size() == 0) return s.size() == 0;
    //     if (s.size() == 0) return p.size() == 0;

    //     // Caso recursivo a*, aa
    //     bool match = s[0] == p[0] || p[0] == '.';
    //     if (p.size() >= 2 && p[1] == '*') {

    //         return isMatch(s, p.substr(2)) || (match && isMatch(s.substr(1), p));
    //     }
    //     else
    //         return match && isMatch(s.substr(1), p.substr(1));
    // }
};

int main() {
    cout << Solution::isMatch("123abc", ".*abc") << endl;
}