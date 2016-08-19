#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef struct {
    double x, y, z;
} Generator;

Generator getGenerator(double x, double y, double z) {
    Generator g;
    g.x = x;
    g.y = y;
    g.z = z;

    return g;
}

Generator Create_Aleatorio() {
    return getGenerator(drand48(), drand48(), drand48());
}

Generator Create_Cilindro() {
    double t, r;
    r = drand48() / 2;
    t = rand();
    return getGenerator(r * cos(t) + 0.5, r * sin(t) + 0.5, drand48());

}

Generator Create_Disco() {
    double t, r;
    r = drand48() / 2;
    t = rand();
    return getGenerator(r * cos(t) + 0.5, r * sin(t) + 0.5, drand48() / 10);
}

Generator Create_Eixos() {
    const double large_axes = 30;
    int cont = rand() % 3;

    if (cont == 0) {
        return getGenerator(drand48(), drand48() / large_axes, drand48() / large_axes);
    } else if (cont == 1) {
        return getGenerator(drand48() / large_axes, drand48(), drand48() / large_axes);
    } else {
        return getGenerator(drand48() / large_axes, drand48() / large_axes, drand48());
    }
}

Generator Create_Espiral() {
    double t, f, r;
    int i = 0;
    f = 100.0;
    t = drand48();
    r = drand48() / 2;
    // //~ f = 100 + (rand() % 10);
    r = 0.45 + drand48() / 15;
    return getGenerator(((1 - t) * r) * cos(t * f) + 0.5, ((1 - t) * r) * sin(t * f) + 0.5, t);

}

Generator Create_Paraboloide() {
    double x, y, z, a, b;
    int cont = rand() % 4;
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
        return getGenerator(x, y, z);
    } else if (cont == 1) {
        return getGenerator(1 - x, y, z);
    } else if (cont == 2) {
        return getGenerator(x, 1 - y, z);
    } else {
        return getGenerator(1 - x, 1 - y, z);
    }
}

Generator Create_Planos() {
    const double large_axes = 30;
    int cont = rand() % 3;

    if (cont == 0) {
        return getGenerator(drand48() / large_axes, drand48(), drand48());
    } else if (cont == 1) {
        return getGenerator(drand48(), drand48() / large_axes, drand48());
    } else {
        return getGenerator(drand48(), drand48(), drand48() / large_axes);
    }

}

Generator Create_Sela() {
    double x, y, z, a, b;
    int cont = rand() % 4;


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
        return getGenerator(x, y, z);
    } else if (cont == 1) {
        return getGenerator(1 - x, y, z);
    } else if (cont == 2) {
        return getGenerator(x, 1 - y, z);
    } else {
        return getGenerator(1 - x, 1 - y, z);
    }

}
