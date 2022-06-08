#include "OrgChart.hpp" 
using namespace std;
using namespace ariel;

// 							ariel
// 						/	  |	   \
// 			  	 rakaz1   rakaz2  erelSegal
// 					|				/		\
// 		  		lecturer1		mor			haim
//   						/	 |	 \
//						liron	or	ivgeny	
// 
//  
	int main() {
		OrgChart organization;
		organization.add_root("University");
		organization.add_sub("University", "rakaz1");
		organization.add_sub("University", "rakaz2");
		organization.add_sub("University", "erelSegal");
		organization.add_sub("erelSegal", "mor");
		organization.add_sub("rakaz1", "lecturer1");
		organization.add_sub("erelSegal", "haim");
		organization.add_sub("mor", "liron");
		organization.add_sub("mor", "or");
		organization.add_sub("mor", "ivgeny");
	
		organization.add_root("Ariel"); //name it
		
		cout << organization << endl;
	
		//pass by iterator on the organization
		for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it) {
			cout << (*it) << " " ;
		}
		cout << endl;
		
		//pass in the form for each 
		for (string element : organization) {
			cout << element << " " ;
		}
		cout << endl;
	

		//pass line-line from the bottom above
		for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it) {
			cout << (*it) << " " ;
		}
		cout << endl;

		//pass on the organization in the form pre order
		for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
			cout << (*it) << " " ;
		}
		cout << endl;
	
		//	????
		for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it) {
			cout << it->size() << " " ;
		}
		cout << endl;
	
		return 0;
	}
