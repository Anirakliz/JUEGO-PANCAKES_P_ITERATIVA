#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_DEPTH = 15;

// Función para voltear los pancakes en la posición i y j
void flip(vector<int>& pancakes, int i, int j) {
    while (i < j) {
        swap(pancakes[i], pancakes[j]);
        i++;
        j--;
    }
}

// Función que verifica si el conjunto de pancakes está ordenado de forma ascendente
bool is_sorted(const vector<int>& pancakes) {
    for (int i = 1; i < pancakes.size(); i++) {
        if (pancakes[i] < pancakes[i-1]) {
            return false;
        }
    }
    return true;
}

// Función de búsqueda de profundidad iterativa
bool dfs_iterative(vector<int>& pancakes, int depth, int max_depth) {
    if (is_sorted(pancakes)) {
        return true;
    }
    if (depth == max_depth) {
        return false;
    }
    int n = pancakes.size();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            flip(pancakes, i, j);
            if (dfs_iterative(pancakes, depth+1, max_depth)) {
                return true;
            }
            flip(pancakes, i, j);
        }
    }
    return false;
}

// Función principal
int main() {
    int n;
    cout << "Ingrese el número de pancakes: ";
    cin >> n;
    vector<int> pancakes(n);
    cout << "Ingrese el tamaño de cada pancake: ";
    for (int i = 0; i < n; i++) {
        cin >> pancakes[i];
    }
    bool found_solution = false;
    for (int max_depth = 0; max_depth < MAX_DEPTH && !found_solution; max_depth++) {
        found_solution = dfs_iterative(pancakes, 0, max_depth);
    }
    if (found_solution) {
        cout << "Se puede ordenar los pancakes en " << MAX_DEPTH << " movimientos o menos." << endl;
    } else {
        cout << "No se puede ordenar los pancakes en " << MAX_DEPTH << " movimientos o menos." << endl;
    }
    return 0;
}
