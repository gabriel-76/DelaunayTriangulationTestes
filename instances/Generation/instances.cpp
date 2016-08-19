#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void Create_Aleatorio(int NUM_VERTICES) {
    int i = 0;
    cout << NUM_VERTICES << endl;
    while (i < NUM_VERTICES) {
        cout << drand48() << " "
                << drand48() << " "
                << drand48() << endl;
        i++;
    }
}

void Create_Cilindro(int NUM_VERTICES) {
    double t, r;
    int i = 0;
    cout << NUM_VERTICES << endl;
    while (i < NUM_VERTICES) {
        r = drand48() / 2;
        t = rand();

        cout << r * cos(t) + 0.5 << " "
                << r * sin(t) + 0.5 << " "
                << drand48() << endl;
        i++;
    }
}

void Create_Disco(int NUM_VERTICES) {
    double t, r;
    int i = 0;
    cout << NUM_VERTICES << endl;
    while (i < NUM_VERTICES) {
        r = drand48() / 2;
        t = rand();

        cout << r * cos(t) + 0.5 << " "
                << r * sin(t) + 0.5 << " "
                << drand48() / 10 << endl;
        i++;
    }
}

void Create_Eixos(int NUM_VERTICES) {
    const double large_axes = 30;
    int i = 0, cont = 0;

    cout << NUM_VERTICES << endl;
    while (i < NUM_VERTICES) {

        if (cont == 0) {
            cout << drand48() << " "
                    << drand48() / large_axes << " "
                    << drand48() / large_axes << endl;

        } else if (cont == 1) {
            cout << drand48() / large_axes << " "
                    << drand48() << " "
                    << drand48() / large_axes << endl;

        } else {

            cout << drand48() / large_axes << " "
                    << drand48() / large_axes << " "
                    << drand48() << endl;

            cont = -1;
        }
        i++;
        cont++;

    }
}

void Create_Espiral(int NUM_VERTICES) {
    double t, f, r;
    int i = 0;

    f = 100.0;

    cout << NUM_VERTICES << endl;
    while (i < NUM_VERTICES) {

        t = drand48();
        r = drand48() / 2;

        // //~ f = 100 + (rand() % 10);

        r = 0.45 + drand48() / 15;

        cout << ((1 - t) * r) * cos(t * f) + 0.5 << " "
                << ((1 - t) * r) * sin(t * f) + 0.5 << " "
                << t << endl;

        i++;
    }
}

void Create_Paraboloide(int NUM_VERTICES) {
    double x, y, z, a, b;
    int i = 0, cont = 0;
    cout << NUM_VERTICES << endl;
    while (i < NUM_VERTICES) {

        a = 0.4 + drand48() / 10;
        b = 0.4 + drand48() / 10;
        do {
            x = drand48();
            y = drand48();
            z = ((pow(x, 2) / pow(a, 2)) + (pow(y, 2) / pow(b, 2)));
        } while (z > 1.0);

        x += 0.5;
        y += 0.5;

        if (cont == 0) {
            cout << x << " "
                    << y << " "
                    << z << endl;
        } else if (cont == 1) {
            cout << 1 - x << " "
                    << y << " "
                    << z << endl;
        } else if (cont == 2) {
            cout << x << " "
                    << 1 - y << " "
                    << z << endl;

        } else {
            cout << 1 - x << " "
                    << 1 - y << " "
                    << z << endl;
            cont = -1;
        }
        i++;
        cont++;
    }
}

void Create_Planos(int NUM_VERTICES) {
    const double large_axes = 30;
    int i = 0, cont = 0;

    cout << NUM_VERTICES << endl;
    while (i < NUM_VERTICES) {

        if (cont == 0) {
            cout << drand48() / large_axes << " "
                    << drand48() << " "
                    << drand48() << endl;

        } else if (cont == 1) {
            cout << drand48() << " "
                    << drand48() / large_axes << " "
                    << drand48() << endl;

        } else {

            cout << drand48() << " "
                    << drand48() << " "
                    << drand48() / large_axes << endl;

            cont = -1;
        }
        i++;
        cont++;

    }
}

void Create_Sela(int NUM_VERTICES) {
    srand48(time(NULL));
    double x, y, z, a, b;
    int i = 0, cont = 0;
    cout << NUM_VERTICES << endl;

    while (i < NUM_VERTICES) {

        a = 0.4 + drand48() / 10;
        b = 0.4 + drand48() / 10;

        do {
            x = drand48();
            y = drand48();
            z = ((pow(x, 2) / pow(a, 2)) - (pow(y, 2) / pow(b, 2)));
        } while (z >= 0.5 || z <= -0.5 || x >= 0.5 || y >= 0.5);

        x += 0.5;
        y += 0.5;
        z += 0.5;

        if (cont == 0) {
            cout << x << " "
                    << y << " "
                    << z << endl;
        } else if (cont == 1) {
            cout << 1 - x << " "
                    << y << " "
                    << z << endl;
        } else if (cont == 2) {
            cout << x << " "
                    << 1 - y << " "
                    << z << endl;

        } else {
            cout << 1 - x << " "
                    << 1 - y << " "
                    << z << endl;
            cont = -1;
        }
        i++;
        cont++;

    }
}

void Create_All(int num) {
    Create_Aleatorio(num);
    Create_Planos(num);
    Create_Paraboloide(num);
    Create_Espiral(num);
    Create_Disco(num);
    Create_Cilindro(num);
    Create_Eixos(num);
    Create_Sela(num);
}

void menu(int op, int num) {
    switch (op) {
        case 1: Create_Aleatorio(num);
            break;
        case 2: Create_Planos(num);
            break;
        case 3: Create_Paraboloide(num);
            break;
        case 4: Create_Espiral(num);
            break;
        case 5: Create_Disco(num);
            break;
        case 6: Create_Cilindro(num);
            break;
        case 7: Create_Eixos(num);
            break;
        case 8: Create_Sela(num);
            break;
    }
}

int main(int argc, char** argv) {
    srand48(time(NULL));
    if (argc < 3) exit(0);
    menu(atoi(argv[1]), atoi(argv[2]));
    return 0;
}
