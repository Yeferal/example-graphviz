#include <iostream>
#include<string>
#include <fstream>

using namespace std;

int main() {
    string code = "digraph G {\n"
                  "    node [shape=circle, style=filled, fillcolor=lightblue, fontcolor=black]; // Configuración de nodos\n"
                  "    \n"
                  "    // Definición de nodos y conexiones\n"
                  "    1 [label=\"1\"];\n"
                  "    2 [label=\"2\"];\n"
                  "    3 [label=\"3\"];\n"
                  "    4 [label=\"4\"];\n"
                  "    5 [label=\"5\"];\n"
                  "    6 [label=\"6\"];\n"
                  "    7 [label=\"7\"];\n"
                  "\n"
                  "    1 -> 2;\n"
                  "    1 -> 3;\n"
                  "    2 -> 4;\n"
                  "    2 -> 5;\n"
                  "    3 -> 6;\n"
                  "    3 -> 7;\n"
                  "}";

    ofstream file("../graph.dot"); // Crea un archivo DOT
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    file << code << endl; // Comienza la definición del gráfico

    file.close(); // Cierra el archivo

    // Ejecuta Graphviz para generar la imagen del gráfico
    system("dot -Tpng ../graph.dot -o ../graph.png");

    cout << "Gráfico generado correctamente." << endl;

    return 0;
}
