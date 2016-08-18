#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_3.h>
#include <CGAL/Triangulation_vertex_base_3.h>
#include <iostream>
#include <fstream>
template < class GT, class Vb = CGAL::Triangulation_vertex_base_3<GT> >
class My_vertex_base
  : public Vb
{
public:
  typedef typename Vb::Vertex_handle  Vertex_handle;
  typedef typename Vb::Cell_handle    Cell_handle;
  typedef typename Vb::Point          Point;

  template < class TDS2 >
  struct Rebind_TDS {
    typedef typename Vb::template Rebind_TDS<TDS2>::Other  Vb2;
    typedef My_vertex_base<GT, Vb2>                        Other;
  };

  My_vertex_base() {}

  My_vertex_base(const Point& p)
    : Vb(p) {}

  My_vertex_base(const Point& p, Cell_handle c)
    : Vb(p, c) {}

  Vertex_handle   vh;
  Cell_handle     ch;
};


typedef CGAL::Exact_predicates_inexact_constructions_kernel K;

typedef CGAL::Triangulation_data_structure_3<My_vertex_base<K> >    Tds;
typedef CGAL::Delaunay_triangulation_3<K, Tds>
Delaunay;

typedef Delaunay::Vertex_handle    Vertex_handle;
typedef Delaunay::Cell_handle    Cell_handle;

typedef Delaunay::Point            Point;
using namespace std;
double (*coord_nodes3)[3];
int numnodes3;
std::vector<Vertex_handle> arrayofnodetet;
int *vp,vpre[8];
extern bool qsortNodeInDirect12(const int &a, const int &b);
void node_in(void){  //for wang min zhong

   	int i,ncout;
	ifstream file;
	char filename[60];
	cout<<"input mesh file name\n";
	cin>>filename;
	file.open(filename);
	if(!file){
		 cout<<"File open error\n";
		 exit(1);
	}
	file>>numnodes3;
   // if( numnodes3<=0 ) jf_error( "null mesh read" , 1) ;
    coord_nodes3 = (double (*)[3] )new double[numnodes3 *3] ;
	for( i = 0 ; i< numnodes3 ; i++ )
    //  file>>coord_nodes3[i][0]>>coord_nodes3[i][1]>>coord_nodes3[i][2];
      file>>ncout>>coord_nodes3[i][0]>>coord_nodes3[i][1]>>coord_nodes3[i][2
];
    file.close() ;
}
extern void makeInsOrder(void);
extern Cell_handle getStartTet(int insertcount);
const int randomtest=0;
int main()
{
  Delaunay T;
  std::vector<Point> P;

 time_t first, second;

node_in();
	double extranodes[6][3];
extern void cre6extranodes(double cp[6][3]);
cre6extranodes(extranodes);

first=time(0);
	arrayofnodetet.resize(numnodes3);
	makeInsOrder();
	for(int i=0; i<6; i++)
		T.insert(Point(extranodes[i][0],extranodes[i][1],extranodes[i][2]));
second=time(0);
cout<<difftime(second,first)<<" sort ADDING_HANDEL secs"<<endl;

first=time(0);
int insertnode;
	for(int i=0; i<numnodes3; i++){
		insertnode=vp[i];
		arrayofnodetet[insertnode]=
		T.insert(Point(coord_nodes3[insertnode][0],coord_nodes3[insertnode][1],coo
rd_nodes3[insertnode][2]),getStartTet(i));
	}
second=time(0);
cout<<difftime(second,first)<<"  ADDING_HANDEL secs"<<endl;
T.clear();

 	first=time(0);
	for(int i=0; i<numnodes3; i++)
	  P.push_back(Point(coord_nodes3[i][0],coord_nodes3[i][1],coord_nodes3[i][2
]));
	T.insert(P.begin(),P.end());
second=time(0);
cout<<difftime(second,first)<<" Hilbert in ADDING_HANDEL secs"<<endl;

	Vertex_handle v5 = T.insert(Point(-1,0,1));
  //v5->vh = v0;

  return 0;
}

	 int *nodesort[3];
	 int *nodestcp,*parentoflownode;
	 int direction;
	 int firstlownode;
	 int currentlownode;
extern void buildKdtreeAndSortNode(int bend,int tend,int level, int
nodeposition);
extern	void splitNodeArray(int dir,int mposition, int bend, int tend);
extern	int qsortNodeInDirect(const void *ai, const void *bi);
double Ldistance(double x,double y,double z,double x0,double y0,double z0){
	return fabs(x-x0)+fabs(y-y0)+fabs(z-z0);
}

void getLclosestPoint(double x,double y,double z,int &icp){
	double d0=1.e+30,d;
	for(int i=0; i<numnodes3; i++){
		if((d=Ldistance(x,y,z,coord_nodes3[i][0],coord_nodes3[i][1],coord_nodes3[i
][2]))<d0){
			d0=d;
			icp=i;
		}
	}
}
void boxOfP( double (*p)[3] , int num ,double box[6] ){

  int i , j ;
 // double a ;

  if( num<=0 ) cout<<"boxofP"<<endl ;
  for(i=0 ; i<3 ; i++ )
    box[i]=box[i+3]=p[0][i] ;
  for(j=1 ; j<num ; j++ ){
    for( i=0 ; i<3 ; i++ ){
	 if( p[j][i]<box[i] ) box[i]=p[j][i] ;
	 if( p[j][i]>box[i+3] ) box[i+3]=p[j][i] ;
    }
  }
}
void get8corners(void){
	double box[6];
	boxOfP(coord_nodes3,numnodes3,box);
	int cnt=0;
	double a[2]={box[0],box[3]},b[2]={box[1],box[4]},c[2]={box[2],box[5]};
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			for(int k=0; k<2; k++){
				getLclosestPoint(a[i],b[j],c[k],vpre[cnt]);
				cnt++;
			}
}
void cre6extranodes(double cp[6][3]){
   double x0,y0,z0,box[6], a,b,c,h,r0;

   boxOfP(coord_nodes3,numnodes3,box);
   x0=( box[0]+box[3])/2.; y0=(box[1]+box[4])/2.; z0=(box[2]+box[5])/2.;
   a=(box[3]-box[0])/2. ;
   b=(box[4]-box[1])/2. ;
   c=(box[5]-box[2])/2. ;
//   h=a ; if( h<b) h=b ; if( h<c) h=c ;
	h=sqrt( (a*a+b*b+c*c)/3.) ;
	h=h*2. ;
   r0=3.*h ;
   for( int i=0 ; i<6 ; i++ ){
	  cp[i][0]=x0 ;
	  cp[i][1]=y0 ;
	  cp[i][2]=z0 ;
   }
   cp[0][0] -=r0;
   cp[1][1] -=r0;
   cp[2][0] +=r0;
   cp[3][1] +=r0;
   cp[4][2] +=r0;
   cp[5][2] -=r0;
}/*
void makeInsOrder(void){

//	get8corners();
	 vp= new int[numnodes3];
	 if(randomtest==1){
		 for(int i=0; i<numnodes3; i++)
			vp[i]=i;
		std::random_shuffle(vp, vp+numnodes3);
		return;
	 }
	 for(int i=0; i<3; i++)
		 nodesort[i]=new int[numnodes3];
	 nodestcp= new int[numnodes3];
	 for(int i=0; i<numnodes3; i++)
		 nodestcp[i]=i;
	 for(int i=0; i<3; i++){
		 direction=i;
		 qsort(nodestcp,numnodes3,sizeof(int),qsortNodeInDirect);
		 memcpy(nodesort[i],nodestcp,numnodes3*sizeof(int));
	 }
	 int a=numnodes3;
	 firstlownode=1;
	 while(a /= 2)
		 firstlownode *= 2;
	 currentlownode=firstlownode;
	 parentoflownode=new int[numnodes3-firstlownode+1];
	 buildKdtreeAndSortNode(0,numnodes3-1,0,0);
	 delete [] nodestcp;
	 for(int i=0; i<3; i++)
		 delete [] nodesort[i];

}
void buildKdtreeAndSortNode(int bend,int tend,int level, int nodeposition){

	if(bend>tend)
		return;
	int dir=level%3;
	double d0=0,d;
	for(int i=0; i<3; i++)
		if((d=coord_nodes3[nodesort[i][tend]][i]-coord_nodes3[nodesort[i][bend]][i
])>d0){
			dir=i; d0=d;
		}

	int md=(bend+tend+1)/2;
	if(nodeposition<firstlownode)
		vp[nodeposition]=nodesort[dir][md];
	else{
//		if(currentlownode==numnodes3)
//			jf_error("errbuildkdtreeandsort",1);
		parentoflownode[currentlownode-firstlownode]=(nodeposition-1)/2;
		vp[currentlownode++]=nodesort[dir][md];
	}
	if(bend==tend)	return;
	splitNodeArray(dir,md,bend,tend);
	buildKdtreeAndSortNode(bend,md-1,level+1,nodeposition*2+1);
	buildKdtreeAndSortNode(md+1,tend,level+1,nodeposition*2+2);
}

void splitNodeArray(int dir,int mposition, int bend, int tend){


	int mnode=nodesort[dir][mposition];
	int rt;
	direction=dir;
	for(int i=0; i<3; i++){
		if(i==dir) continue;
		int m=bend;
		int n=mposition+1;
		for(int j=bend; j<=tend; j++){
			if((rt=qsortNodeInDirect(nodesort[i]+j,&mnode))==-1)
				nodestcp[m++]=nodesort[i][j];
			else if(rt==1){
//				if(n==tend+1)
//					jf_error("errsplitnodearray",1);
				nodestcp[n++]=nodesort[i][j];
			}else
				nodestcp[mposition]=nodesort[i][j];
			//	jf_error("errsplitnodearray",1);
		}
		memcpy(nodesort[i]+bend,nodestcp+bend,(tend-bend+1)*sizeof(int));
	}
}

int qsortNodeInDirect(const void *ai, const void *bi){

	int a=*(int *)ai;
	int b=*(int *)bi;

	if(coord_nodes3[a][direction]<coord_nodes3[b][direction]) return -1;
	if(coord_nodes3[a][direction]>coord_nodes3[b][direction]) return  1;

	if(coord_nodes3[a][(direction+1)%3]<coord_nodes3[b][(direction+1)%3])
return -1;
	if(coord_nodes3[a][(direction+1)%3]>coord_nodes3[b][(direction+1)%3])
return  1;

	if(coord_nodes3[a][(direction+2)%3]<coord_nodes3[b][(direction+2)%3])
return -1;
	if(coord_nodes3[a][(direction+2)%3]>coord_nodes3[b][(direction+2)%3])
return  1;
	return 0;
}
*/
Cell_handle getStartTet(int insertcount){


	if(randomtest==1){
		if(insertcount<1)
			return Cell_handle();
		else
			return arrayofnodetet[vp[insertcount-1]]->cell();
	}
	int nnode;
	if(insertcount<1) return Cell_handle();
	else if(insertcount<firstlownode)
		nnode=vp[(insertcount-1)/2];
	else
		nnode=vp[parentoflownode[insertcount-firstlownode]];
   return arrayofnodetet[nnode]->cell();
}

const int sortway=1; //0 for previous, 1 for complete box, 2 for sample box
const int ETANODE= 0;
void makeInsOrder(void){

	 vp= new int[numnodes3];
 /*for(int i=0; i<numnodes3; i++)
		vp[i]=i+ETANODE;
	 std::random_shuffle(vp, vp+numnodes3);
	 return;
*/
	 for(int i=0; i<3; i++)
		 nodesort[i]=new int[numnodes3];
	 nodestcp= new int[numnodes3];
	 for(int i=0; i<numnodes3; i++)
		 nodestcp[i]=i+ETANODE;
 clock_t first, second;
  first = clock();//time(NULL);
  if( sortway==0){
 	   for(int i=0; i<3; i++){
		 direction=i;
		 qsort(nodestcp,numnodes3,sizeof(int),qsortNodeInDirect);
		 memcpy(nodesort[i],nodestcp,numnodes3*sizeof(int));
	   }
  }
second = clock();// time(NULL);
 printf("The time differencebso is: %lf
seconds\n",double(second-first));//difftime(second,first));
	 int a=numnodes3;
	 firstlownode=1;
	 while(a /= 2)
		 firstlownode *= 2;
	 currentlownode=firstlownode;
	 parentoflownode=new int[numnodes3-firstlownode];
	 buildKdtreeAndSortNode(0,numnodes3-1,0,0);
	 delete [] nodestcp;
	 for(int i=0; i<3; i++)
		 delete [] nodesort[i];

}
int getDirectFromArray(int bend,int tend){

	if(tend<bend) return -1;
	double d0=0,d;
	int dir=0;
	if(sortway==0){
		for(int i=0; i<3; i++)
			if((d=coord_nodes3[nodesort[i][tend]][i]-coord_nodes3[nodesort[i][bend]][
i])>d0){
				dir=i; d0=d;
			}
		return dir;
	}
	int nstop=tend;
	if(sortway==2&&tend-bend>10) nstop=bend+(int)sqrt(double(tend-bend));
	int ip=nodestcp[bend];
	double
box[2][3]={coord_nodes3[ip][0],coord_nodes3[ip][1],coord_nodes3[ip][2],
		              coord_nodes3[ip][0],coord_nodes3[ip][1],coord_nodes3[ip][2]}
;
	for(int i=bend; i<=nstop; i++){
		ip=nodestcp[i];
		for(int j=0; j<3; j++){
			if(box[0][j]>coord_nodes3[ip][j])
				box[0][j]=coord_nodes3[ip][j];
			else if(box[1][j]<coord_nodes3[ip][j])
				box[1][j]=coord_nodes3[ip][j];
		}
	}
	for(int i=0; i<3; i++)
		if((d=box[1][i]-box[0][i])>d0){
			dir=i; d0=d;
		}
	if(dir<0||dir>2)
			dir=dir; //jf_error("dir=dir;",1);
	return dir;
}

void buildKdtreeAndSortNode(int bend,int tend,int level, int nodeposition){

	if(bend>tend)
		return;
	int dir=level%3;
	int md=(bend+tend+1)/2;
	if(bend<tend){
		dir=getDirectFromArray(bend,tend);
		if(dir<0||dir>2){
			cout<<"e! "<<endl;
			getDirectFromArray(bend,tend);
		}
		if(sortway==0) splitNodeArray(dir,md,bend,tend);
		else{direction=dir;
nth_element(nodestcp+bend,nodestcp+md,nodestcp+tend+1,qsortNodeInDirect12);}
//
_Nth_element(nodestcp+bend,nodestcp+md,nodestcp+tend+1,qsortNodeInDirect);
//		rearrange(bend,tend,dir);
	}
	if(nodeposition<firstlownode)
		vp[nodeposition]=nodestcp[md]; 	//
		//nodesort[dir][md];
	else{
//		if(currentlownode==numnodes3)
//			jf_error("errbuildkdtreeandsort",1);
		parentoflownode[currentlownode-firstlownode]=(nodeposition-1)/2;
		vp[currentlownode++]=nodestcp[md]; //
			//nodesort[dir][md];
	}
	if(bend==tend)	return;
//	splitNodeArray(dir,md,bend,tend);
	buildKdtreeAndSortNode(bend,md-1,level+1,nodeposition*2+1);
	buildKdtreeAndSortNode(md+1,tend,level+1,nodeposition*2+2);
}

void splitNodeArray(int dir,int mposition, int bend, int tend){


	int mnode=nodesort[dir][mposition];
	int rt;
	direction=dir;
	for(int i=0; i<3; i++){
		if(i==dir) continue;
		int m=bend;
		int n=mposition+1;
		for(int j=bend; j<=tend; j++){
			if((rt=qsortNodeInDirect(nodesort[i]+j,&mnode))==-1)
				nodestcp[m++]=nodesort[i][j];
			else if(rt==1){
//				if(n==tend+1)
//					jf_error("errsplitnodearray",1);
				nodestcp[n++]=nodesort[i][j];
			}else
				nodestcp[mposition]=nodesort[i][j];
			//	jf_error("errsplitnodearray",1);
		}
		memcpy(nodesort[i]+bend,nodestcp+bend,(tend-bend+1)*sizeof(int));
	}
}
bool qsortNodeInDirect12//(const void *ai, const void *bi){
	(const int &a, const int &b){

//	int a=*(int *)ai;
//	int b=*(int *)bi;

	if(coord_nodes3[a][direction]<coord_nodes3[b][direction]) return true;
//	if(coord_nodes3[a][direction]>coord_nodes3[b][direction]) return  false;

//	if(coord_nodes3[a][(direction+1)%3]<coord_nodes3[b][(direction+1)%3])
return -1;
//	if(coord_nodes3[a][(direction+1)%3]>coord_nodes3[b][(direction+1)%3])
return  1;

//	if(coord_nodes3[a][(direction+2)%3]<coord_nodes3[b][(direction+2)%3])
return -1;
//	if(coord_nodes3[a][(direction+2)%3]>coord_nodes3[b][(direction+2)%3])
return  1;
	return false;
}

int qsortNodeInDirect(const void *ai, const void *bi){

	int a=*(int *)ai;
	int b=*(int *)bi;

	if(coord_nodes3[a][direction]<coord_nodes3[b][direction]) return -1;
	if(coord_nodes3[a][direction]>coord_nodes3[b][direction]) return  1;

	if(coord_nodes3[a][(direction+1)%3]<coord_nodes3[b][(direction+1)%3])
return -1;
	if(coord_nodes3[a][(direction+1)%3]>coord_nodes3[b][(direction+1)%3])
return  1;

	if(coord_nodes3[a][(direction+2)%3]<coord_nodes3[b][(direction+2)%3])
return -1;
	if(coord_nodes3[a][(direction+2)%3]>coord_nodes3[b][(direction+2)%3])
return  1;
	return 0;
}
/*
PTETFACE getStartTet(void){


	//	return head_tet;
	  int nnode;
//	if(insertcount<=16) return head_tet;
//   int nsample=(int)pow(insertcount,0.25);
//   double sqdist0=numeric_limits<double>::max();
//   double sqdist;
//   for(int i=0; i<nsample; i++){
//
if((sqdist=SqDistance3D(coord_nodes3[insertnode],coord_nodes3[vp[i]]))<sqdis
t0){
//			sqdist0=sqdist;
//			nnode=vp[i];
//	   }
  // }
	if(insertcount<1) return head_tet;
	else if(insertcount<firstlownode)
		nnode=vp[(insertcount-1)/2];
	else
		nnode=vp[parentoflownode[insertcount-firstlownode]];
   return arrayofnodetet[nnode];
}
*/
