// Kernel includes
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

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

typedef CGAL::Exact_predicates_inexact_constructions_kernel IK;
typedef CGAL::Triangulation_vertex_base_3 <IK> Vb;
typedef CGAL::Triangulation_data_structure_3<Vb> Tds;
typedef CGAL::Delaunay_triangulation_3<IK, Tds> Delaunay;
typedef Delaunay::Point Point;
typedef Delaunay::Vertex_handle Vertex_handle;
typedef Delaunay::Cell_handle Cell_handle;

std::vector<Point> points;
std::vector<Vertex_handle> pointsReference;

//std::vector<Ponto> pontos;

Delaunay delaunay_triangulation;

unsigned int number_of_points;
bool interval_instance = false;

Memory memory_before, memory_after;
clock_t clock_first, clock_second;
time_t time_first, time_second;

void Print_Time() {
    std::cout << "Time Clock: " << (double) (clock_second - clock_first) / ((double) CLOCKS_PER_SEC) << std::endl;
    std::cout << "Time Liu: " << difftime(time_second, time_first) << std::endl;
}

void Print_Memory() {
    std::cout << "Memory: " << memory_after - memory_before << std::endl;
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

void Check_Entries(int num_args, char **args) {
    if (num_args < 2) {
        std::cout << "PASS THE INSTANCE BY PARAMETER" << std::endl
                << "EXIT_FAILURE" << std::endl;
        exit(1);
    } else if (num_args == 3) {
        if (is_numeric(args[2])) {
            std::cout << "IDENTIFIED INSTANCE LIMIT" << std::endl;
            number_of_points = atoi(args[2]);
            interval_instance = true;
        }
    }
}

void Check_Nunber_Of_Points_In_Triangulation() {

    assert(delaunay_triangulation.is_valid());
    signed int full = delaunay_triangulation.number_of_vertices();

    if (full == number_of_points) {
        std::cout << "EXIT_SUCCESS" << std::endl;
    } else {
        std::cout << "WARNING : NUMBER OF VERTICES IS LOWER THAN EXPECTED" << std::endl
                << "CONTAIS : " << full << std::endl
                << "EXPECTED " << number_of_points << std::endl;
    }

}

void Read_Instance(char *name) {

    std::ifstream file_points;
    file_points.open(name);

    if (!file_points) {
        std::cout << "FILE_NOT_EXIST" << std::endl;
        exit(1);
    }
    double coords[3];

    if (!interval_instance)
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

/*
 * void Read_Pontos(char *name) {

    std::ifstream file_points;
    file_points.open(name);

    if (!file_points) {
        std::cout << "FILE_NOT_EXIST" << std::endl;
        exit(1);
    }
    double coords[3];

    if (!interval_instance)
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
        pointsReference[i] = delaunay_triangulation.insert(points[i],pointsReference[i-1]->cell());
}

void Compute_Delaunay_Reverse() {
    for (int i = number_of_points - 1; i >= 0; --i)
        delaunay_triangulation.insert(points[i]);
}

void Compute_Aleatory() {
    std::cout << "\nAleatory : " << number_of_points << std::endl;
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
    std::cout << "\nBRIO Puro : " << number_of_points << std::endl;
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
    std::cout << "\nReverse BRIO : " << number_of_points << std::endl;
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
    std::cout << "\nHilbert Median : " << number_of_points << std::endl;
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
    std::cout << "\nReverse Hilbert Median : " << number_of_points << std::endl;
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
    std::cout << "\nHilbert Middle : " << number_of_points << std::endl;
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
    std::cout << "\nReverse Hilbert Middle : " << number_of_points << std::endl;
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
    std::cout << "\nSpatial Median : " << number_of_points << std::endl;
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
    std::cout << "\nReverse Spatial Median : " << number_of_points << std::endl;
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
    std::cout << "\nSpatial Middle : " << number_of_points << std::endl;
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
    std::cout << "\nReverse Spatial Middle : " << number_of_points << std::endl;
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
    std::cout << "\nReverse Cut Longest Edge KD-tree : " << number_of_points << std::endl;
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
    std::cout << "\nDefault Constructor : " << number_of_points << std::endl;
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

int main(int argc, char **argv) {

    Check_Entries(argc, argv);
    memory_before = Utils::current_mem_usage();
    Read_Instance(argv[1]);

    //~ Compute_Aleatory();
    //Compute_Hilbert_Median();
    //Compute_Reverse_Hilbert_Median();
    //Compute_Hilbert_Middle();
    //Compute_Reverse_Hilbert_Middle();
    //Compute_Spatial_Median();
    //Compute_Reverse_Spatial_Median();
    Compute_Spatial_Middle();
    //Compute_Reverse_Spatial_Middle();
    //~ Compute_Brio();    
    //~ Compute_Reverse_Brio();
    Compute_Default_Constructor();
    //Compute_Reverse_Cut_Longest_Edge_KDtree(argv[1]);

    return EXIT_SUCCESS;
}
