// Kernel includes
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>

// Spatial Sort includes
#include <CGAL/hilbert_sort.h>
#include <CGAL/spatial_sort.h>
#include "../../../SourceCode/BRIO/Brio.cpp"
//#include "./../../KDtree/KDTree.cpp"

// Delaunay Triangulation include
#include <CGAL/Delaunay_triangulation_3.h>

// I/O includes
#include <iostream>
#include <fstream>

// Build includes
#include <vector>
#include "./../../Utils/utils.cpp"
#include "../../../instances/Generation/dinamicInstances.cpp"

typedef CGAL::Exact_predicates_exact_constructions_kernel EK;
typedef CGAL::Triangulation_vertex_base_3 <EK> Vb;
typedef CGAL::Triangulation_data_structure_3<Vb> Tds;
typedef CGAL::Delaunay_triangulation_3<EK, Tds> Delaunay;
typedef Delaunay::Point Point;
typedef Delaunay::Vertex_handle Vertex_handle;
typedef Delaunay::Cell_handle Cell_handle;

std::vector<Point> points;
std::vector<Vertex_handle> pointsReference;

//std::vector<Ponto> pontos;

Delaunay delaunay_triangulation;

unsigned int number_of_points;

Memory memory_before, memory_after;
clock_t clock_first, clock_second;
time_t time_first, time_second;

void Print_Time() {
    std::cout << (double) (clock_second - clock_first) / ((double) CLOCKS_PER_SEC) << ","
            << difftime(time_second, time_first) << ",";
}

void Print_Memory() {
    std::cout << memory_after - memory_before << ",";
}

bool is_numeric(const char *str) {
    bool res = true;
    while (*str) {
        if ((!isdigit(*str)) and (*str != ',')) {
            res = false;
            break;
        }
        str++;
    }
    return res;
}

void Check_Nunber_Of_Points_In_Triangulation() {

    assert(delaunay_triangulation.is_valid());
    unsigned int full = delaunay_triangulation.number_of_vertices();

    if (full == number_of_points) {
        std::cout << "success" << std::endl;
    } else {
        std::cout << "warning contais " << full
                << " expected " << number_of_points << std::endl;
    }

}

void Read_Instance(char *name) {

    std::ifstream file_points;
    file_points.open(name);

    if (!file_points) {
        std::cout << "file not exist" << std::endl;
        exit(1);
    }
    double coords[3];


    file_points >> number_of_points;

    points.reserve(number_of_points);
    pointsReference.reserve(number_of_points);

    int i = 0;

    while (i < number_of_points/*!file_points.eof()*/) {
        file_points >> coords[0];
        file_points >> coords[1];
        file_points >> coords[2];
        //std :: cout << x << " " << y << " " << z << std :: endl;
        points.push_back(Point(coords[0], coords[1], coords[2]));
        i++;
    }
    file_points.close();
}

void Read_Dinamic_Instance(int id, int num_vertices) {
    Generator g;
    number_of_points = num_vertices;
    points.reserve(number_of_points);
    switch (id) {
        case 1:
            for (int i = 0; i < number_of_points; i++) {
                g = Create_Aleatorio();
                points.push_back(Point(g.x, g.y, g.z));
            };
            break;
        case 2:
            for (int i = 0; i < number_of_points; i++) {
                g = Create_Planos();
                points.push_back(Point(g.x, g.y, g.z));
            };
            break;
        case 3:
            for (int i = 0; i < number_of_points; i++) {
                g = Create_Paraboloide();
                points.push_back(Point(g.x, g.y, g.z));
            };
            break;
        case 4:
            for (int i = 0; i < number_of_points; i++) {
                g = Create_Espiral();
                points.push_back(Point(g.x, g.y, g.z));
            };
            break;
        case 5:
            for (int i = 0; i < number_of_points; i++) {
                g = Create_Disco();
                points.push_back(Point(g.x, g.y, g.z));
            };
            break;
        case 6:
            for (int i = 0; i < number_of_points; i++) {
                g = Create_Cilindro();
                points.push_back(Point(g.x, g.y, g.z));
            };
            break;
        case 7:
            for (int i = 0; i < number_of_points; i++) {
                g = Create_Eixos();
                points.push_back(Point(g.x, g.y, g.z));
            };
            break;
        case 8:for (int i = 0; i < number_of_points; i++) {
                g = Create_Sela();
                points.push_back(Point(g.x, g.y, g.z));
            };
            break;
    }
    //    for (int i = 0; i < 10; i++){
    //        g = Create_Aleatorio();
    //        std :: cout << g.x << " " << g.y << " " << g.z << " " << std::endl;
    //    }
}

void Check_Entries(int num_args, char **args) {
    if (num_args < 3) {
        std::cout << "Read the manual" << std::endl;
        exit(1);
    } else {
        switch (atoi(args[1])) {
            case 1: Read_Instance(args[2]);
                break;
            case 2: Read_Dinamic_Instance(atoi(args[2]), atoi(args[3]));
                break;
        }
    }
}

/*
 * void Read_Pontos(char *name) {

    std::ifstream file_points;
    file_points.open(name);

    if (!file_points) {
        std::cout << "FILE_NOT_EXIST" << std::endl;
        exit(1);
    }
    double coords[3];


    file_points >> number_of_points;
    pontos.reserve(number_of_points);

    int i = 0;

    while (i < number_of_points) {
        file_points >> coords[0];
        file_points >> coords[1];
        file_points >> coords[2];
        //std :: cout << x << " " << y << " " << z << std :: endl;
        pontos.push_back(Ponto((int) (coords[0]*1000000000), (int) (coords[1]*1000000000), (int) (coords[2]*1000000000), -1));
        i++;
    }
    file_points.close();
}
 */

void Compute_Delaunay() {
    pointsReference[0] = delaunay_triangulation.insert(points[0]);
    for (int i = 1; i != number_of_points; ++i)
        pointsReference[i] = delaunay_triangulation.insert(points[i], pointsReference[i - 1]->cell());
}

void Compute_Delaunay_Reverse() {
    for (int i = number_of_points - 1; i >= 0; --i)
        delaunay_triangulation.insert(points[i]);
}

void Compute_Aleatory() {
    std::cout << "Aleatory,";
    clock_first = clock();
    time_first = time(0);
    BRIO(0, number_of_points - 1, points);
    Compute_Delaunay();
    clock_second = clock();
    time_second = time(0);
    memory_after = Utils::current_mem_usage();
    Print_Time();
    Print_Memory();
    Check_Nunber_Of_Points_In_Triangulation();
    delaunay_triangulation.clear();
}

void Compute_Brio() {
    std::cout << "BRIO Puro,";
    clock_first = clock();
    time_first = time(0);
    BRIO(0, number_of_points - 1, points);
    Compute_Delaunay();
    clock_second = clock();
    time_second = time(0);
    memory_after = Utils::current_mem_usage();
    Print_Time();
    Print_Memory();
    Check_Nunber_Of_Points_In_Triangulation();
    delaunay_triangulation.clear();
}

void Compute_Reverse_Brio() {
    std::cout << "Reverse BRIO,";
    clock_first = clock();
    time_first = time(0);
    //BRIO(0, number_of_points-1, points);
    Compute_Delaunay_Reverse();
    clock_second = clock();
    time_second = time(0);
    memory_after = Utils::current_mem_usage();
    Print_Time();
    Print_Memory();
    Check_Nunber_Of_Points_In_Triangulation();
    delaunay_triangulation.clear();
}

void Compute_Hilbert_Median() {
    std::cout << "Hilbert Median,";
    clock_first = clock();
    time_first = time(0);
    CGAL::hilbert_sort(points.begin(), points.end(), CGAL::Hilbert_sort_median_policy());
    Compute_Delaunay();
    clock_second = clock();
    time_second = time(0);
    memory_after = Utils::current_mem_usage();
    Print_Time();
    Print_Memory();
    Check_Nunber_Of_Points_In_Triangulation();
    delaunay_triangulation.clear();
}

void Compute_Reverse_Hilbert_Median() {
    std::cout << "Reverse Hilbert Median,";
    clock_first = clock();
    time_first = time(0);
    CGAL::hilbert_sort(points.begin(), points.end(), CGAL::Hilbert_sort_median_policy());
    Compute_Delaunay_Reverse();
    clock_second = clock();
    time_second = time(0);
    memory_after = Utils::current_mem_usage();
    Print_Time();
    Print_Memory();
    Check_Nunber_Of_Points_In_Triangulation();
    delaunay_triangulation.clear();
}

void Compute_Hilbert_Middle() {
    std::cout << "Hilbert Middle,";
    clock_first = clock();
    time_first = time(0);
    CGAL::hilbert_sort(points.begin(), points.end(), CGAL::Hilbert_sort_middle_policy());
    Compute_Delaunay();
    clock_second = clock();
    time_second = time(0);
    memory_after = Utils::current_mem_usage();
    Print_Time();
    Print_Memory();
    Check_Nunber_Of_Points_In_Triangulation();
    delaunay_triangulation.clear();
}

void Compute_Reverse_Hilbert_Middle() {
    std::cout << "Reverse Hilbert Middle,";
    clock_first = clock();
    time_first = time(0);
    CGAL::hilbert_sort(points.begin(), points.end(), CGAL::Hilbert_sort_middle_policy());
    Compute_Delaunay_Reverse();
    clock_second = clock();
    time_second = time(0);
    memory_after = Utils::current_mem_usage();
    Print_Time();
    Print_Memory();
    Check_Nunber_Of_Points_In_Triangulation();
    delaunay_triangulation.clear();
}

void Compute_Spatial_Median() {
    std::cout << "Spatial Median,";
    clock_first = clock();
    time_first = time(0);
    CGAL::spatial_sort(points.begin(), points.end(), CGAL::Hilbert_sort_median_policy());
    Compute_Delaunay();
    clock_second = clock();
    time_second = time(0);
    memory_after = Utils::current_mem_usage();
    Print_Time();
    Print_Memory();
    Check_Nunber_Of_Points_In_Triangulation();
    delaunay_triangulation.clear();
}

void Compute_Reverse_Spatial_Median() {
    std::cout << "Reverse Spatial Median,";
    clock_first = clock();
    time_first = time(0);
    CGAL::spatial_sort(points.begin(), points.end(), CGAL::Hilbert_sort_median_policy());
    Compute_Delaunay_Reverse();
    clock_second = clock();
    time_second = time(0);
    memory_after = Utils::current_mem_usage();
    Print_Time();
    Print_Memory();
    Check_Nunber_Of_Points_In_Triangulation();
    delaunay_triangulation.clear();
}

void Compute_Spatial_Middle() {
    std::cout << "Spatial Middle,";
    clock_first = clock();
    time_first = time(0);
    CGAL::spatial_sort(points.begin(), points.end(), CGAL::Hilbert_sort_middle_policy());
    Compute_Delaunay();
    clock_second = clock();
    time_second = time(0);
    memory_after = Utils::current_mem_usage();
    Print_Time();
    Print_Memory();
    Check_Nunber_Of_Points_In_Triangulation();
    delaunay_triangulation.clear();
}

void Compute_Reverse_Spatial_Middle() {
    std::cout << "Reverse Spatial Middle,";
    clock_first = clock();
    time_first = time(0);
    CGAL::spatial_sort(points.begin(), points.end(), CGAL::Hilbert_sort_middle_policy());
    Compute_Delaunay_Reverse();
    clock_second = clock();
    time_second = time(0);
    memory_after = Utils::current_mem_usage();
    Print_Time();
    Print_Memory();
    Check_Nunber_Of_Points_In_Triangulation();
    delaunay_triangulation.clear();
}

/*
void Compute_Reverse_Cut_Longest_Edge_KDtree(char *filename) {
    //points.clear();
    std::cout << "\nReverse Cut Longest Edge KD-tree : ,";
    Read_Pontos(filename);
    clock_first = clock();
    time_first = time(0);
    KDTree kdtree(pontos, points);
    Compute_Delaunay_Reverse();
    clock_second = clock();
    time_second = time(0);
    pontos.clear();
    pontos.resize(1);
    memory_after = Utils::current_mem_usage();
    Print_Time();
    Print_Memory();
    Check_Nunber_Of_Points_In_Triangulation();
    delaunay_triangulation.clear();
}
 */
void Compute_Default_Constructor() {
    std::cout << "Default Constructor,";
    clock_first = clock();
    time_first = time(0);
    delaunay_triangulation.insert(points.begin(), points.end());
    clock_second = clock();
    time_second = time(0);
    memory_after = Utils::current_mem_usage();
    Print_Time();
    Print_Memory();
    Check_Nunber_Of_Points_In_Triangulation();
    delaunay_triangulation.clear();
}

void head_csv(char *name_instance) {

    char str[60];
    int posi = -1;
    int n = strlen(name_instance);

    for (int i = 0; i < n; i++) {
        if (isalpha(name_instance[i])) {
            posi = i;
            break;
        }
    }

    if (posi != -1) {
        for (int i = posi; i < n; i++) {
            str[i - posi] = name_instance[i];
        }
        str[n] = '\0';
    } else {
        strcpy(str, name_instance);
    }


    std::cout << "inexact " << number_of_points << "," << str << ",,,status\n";
    std::cout << ",Time Clock,Time Liu,Memory\n";
}

int main(int argc, char **argv) {
    srand48(time(NULL));
    memory_before = Utils::current_mem_usage();
    Check_Entries(argc, argv);
    head_csv(argv[2]);

    //~ Compute_Aleatory();
    //Compute_Hilbert_Median();
    //Compute_Reverse_Hilbert_Median();
    //Compute_Hilbert_Middle();
    //Compute_Reverse_Hilbert_Middle();
    Compute_Spatial_Median();
    //Compute_Reverse_Spatial_Median();
    Compute_Spatial_Middle();
    //Compute_Reverse_Spatial_Middle();
    //~ Compute_Brio();    
    //~ Compute_Reverse_Brio();
    //Compute_Default_Constructor();
    //Compute_Reverse_Cut_Longest_Edge_KDtree(argv[1]);
    return EXIT_SUCCESS;
}
