//~ #include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
//~ #include <CGAL/Delaunay_triangulation_3.h>
//~ #include <CGAL/point_generators_3.h>
//~ #include <iostream>
//~ #include <fstream>
//~ #include <vector>
//~ 
//~ int main(int argc, char **argv) {
	//~ 
	//~ #ifdef CGAL_LINKED_WITH_TBB
		//~ typedef CGAL::Exact_predicates_inexact_constructions_kernel IK;
		//~ typedef CGAL::Triangulation_vertex_base_3 <IK> Vb_IK;
		//~ typedef CGAL::Triangulation_data_structure_3<Vb_IK> Tds_IK;
		//~ typedef CGAL::Delaunay_triangulation_3<IK, Tds_IK> Delaunay_IK;
		//~ typedef Delaunay_IK::Point Point_IK;
		//~ typedef Delaunay_IK::Vertex_handle Vertex_handle_IK;
		//~ typedef Delaunay_IK::Cell_handle Cell_handle_IK;
//~ 
		//~ typedef Point_IK Point;
		//~ typedef Delaunay_IK Delaunay;
//~ 
        //~ const int NUM_INSERTED_POINTS = 5000;
        //~ CGAL::Random_points_in_cube_3<Point> rnd(1.);
        //~ // Construction from a vector of 1,000,000 points
        //~ std::vector<Point> V;
        //~ V.reserve(NUM_INSERTED_POINTS);
        //~ for (int i = 0; i != NUM_INSERTED_POINTS; ++i)
            //~ V.push_back(*rnd++);
//~ 
        //~ // Construct the locking data-structure, using the bounding-box of the points
        //~ Delaunay::Lock_data_structure locking_ds(CGAL::Bbox_3(0.0, 0.0, 0.0, 1.0, 1.0, 1.0), 50);
        //~ // Construct the triangulation in parallel
        //~ Delaunay T(V.begin(), V.end(), &locking_ds);
        //~ assert(T.is_valid());        
        //~ std::cerr << "Construction and insertion" << std::endl;
        //~ 
        //~ 
    //~ #endif //CGAL_LINKED_WITH_TBB
    //~ 
    //~ return 0;
//~ }
