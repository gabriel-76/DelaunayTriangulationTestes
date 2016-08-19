echo Compile...
cd SourceCode/Sequential/InexactPredicates/ 
cgal_create_CMakeLists -s inexact && cmake . && make

cd ../ExactPredicates/
cgal_create_CMakeLists -s exact && cmake . && make

cd ../../KDtreeLiu/InexactPredicates/
cgal_create_CMakeLists -s inexact && cmake . && make

cd ../ExactPredicates/
cgal_create_CMakeLists -s exact && cmake . && make

cd ../../Menu/ && make

