// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

// 4. Median of Two Sorted Arrays

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

// Constraints:
// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106


/*
Notas: la idea es llevar dos punteros, uno apuntando al valor más grande de los dos arrays y otro al más pequeño. 
Pero haciendo esto, y desplazandonos nos queda un orden de O(n+m), pero nos dicen que se puede hacer en O(log(n+m))
Esto nos hace pensar que puede que los punteros apunten al valor medio de los arrays. 
La mediana no es mas que el punto medio de los dos arrays juntos. Si el numero de elementos es par, entonces será la suma de los dos valores medios entre dos

Vale pero como conchas el orden es log(n+m)
Que tenga orden log significa que tenemos que usar divide y venceras o alguna forma de eliminar la mitad de los casos de forma rapida

Vamos a probar con dos punteros, en el centro de cada array. 
Podemos comparar ambos valores, y ver cual es menor y cual es mayor. Imaginemos ptr1 y ptr2:
    Si ptr1 > ptr2, todo lo que esté a la derecha de ptr1 y todo lo que esté a la izquierda de ptr2 se puede eliminar, ya que sabemos que ahí están los valores mas grandes y mas pequeños
    Si ptr1 < ptr2: hacemos lo mismo pero al reves. 
    Y si ptr1 == ptr2?

De momento me voy a centrar en intentar resolver el problema en orden n+m (exactamente en (n+m)/2)
Si tenemos longitudes n+m, podemos dar (n+m)/2
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // La idea es crear dos particiones del array mergeado entre los dos
        // Pero nosotros no queremos mergear (orden nlogn), entonces vamos a crear estas particiones a pelo
        // Para ello vamos a empezar fijando uno de los dos arrays, en mi caso fijo nums1
        int n = nums1.size(), m = nums2.size();
        if (n > m) return findMedianSortedArrays(nums2, nums1);

        int len = n + m;
        int halfLen = len / 2;
        
        // Vamos a coger dos punteros, uno apuntando al inicio y otro al final de nums1
        int left = 0, right = n;
        while (left <= right) {
            // Con ello vamos a crear una particion del array en dos, dividiendo por el punto medio de los punteros
            int p1Size = (right + left) / 2;
            // Entonces, ya podemos calcular el tamaño de la particion 2
            int p2Size = halfLen - p1Size;
            
            // Ahora nos quedamos con el valor máximo de la partición izquierda y el valor mínimo de la partición derecha
            int left1 = p1Size > 0 ? nums1[p1Size - 1] : INT_MIN;
            int right1 = p1Size < n ? nums1[p1Size] : INT_MAX; 
            int left2 = p2Size > 0 ? nums2[p2Size - 1] : INT_MIN;
            int right2 = p2Size < m ? nums2[p2Size] : INT_MAX;
            
            // Entonces tenemos que comparar
            if (left1 <= right2 && left2 <= right1) {
                // Hemos ganao, las particiones están bien escogidas
                // Solo tenemos que quedarnos con las cosas que nos beneficien, pero para eso tenemos que distinguir dos casos
                if (len % 2 == 0) {
                    // Si la suma de las longitudes es par, entonces tenemos que hacer la media
                    return (min(right1, right2) + max(left1, left2)) / 2.0;
                } else {
                    // Si la suma de las longitudes es impar, tenemos que quedarnos con el minimo de la particicion derecha unicamente
                    return min(right1, right2);
                }
            } else { 
                // Tenemos que cambiar los punteros left y right y recalcular 
                if (left1 > right2) {
                    // Nos hemos pasado al estimar el medio, tenemos que hacer p1 mas pequeña
                    // Entonces, dejamos left quieto y movemos right a la posicion mid - 1
                    right = p1Size - 1;
                } else if (left2 > right1) {
                    // Nos hemos quedado cortos con la estimacion, tenemos que hacer p1 mas grande
                    // Entonces, dejamos right quieto y movemos left a la posicion mid + 1
                    left = p1Size + 1;
                }
            }
        }
        return 0.0;
    }
};

int main() {
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    double median = Solution::findMedianSortedArrays(nums1, nums2);
    std::cout << "Median: " << median << std::endl;
}