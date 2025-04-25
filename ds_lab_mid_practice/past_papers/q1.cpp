#include <iostream>
using namespace std;

class Team {
    public:
        int totalMatches;
        string teamName;

        Team () : totalMatches(0), teamName("") {}
        Team(int TM, string TN) {
            totalMatches = TM;
            teamName = TN;
        }

        // void sortArr (Team arr[]) {

        //     for (int i=1; i<5; i++) {
        //         Team temp = arr[i];
        //         int j = i - 1;
                
        //         while (j>=0 && arr[j].totalMatches > temp.totalMatches) {
        //             arr[j+1].totalMatches = arr[j].totalMatches;
        //             j--;
        //         }
        //         arr[j+1].totalMatches = temp.totalMatches;
        //     }
        // }

        int getNameSize() {
            return teamName.size();
        }

        void shellSort(Team arr[], int n) {

            for (int gap=n/2; gap>=1; gap /= 2) {
                for (int j=gap; j<n; j++) {
                    for (int i=j-gap; i>=0; i=i-gap) {
                        
                        // if same number of matches, then sort based on longer team name
                        if (arr[i+gap].totalMatches == arr[i].totalMatches) {
                            if (arr[i+gap].getNameSize() > arr[i].getNameSize()) {
                                Team temp = arr[i+gap];
                                arr[i+gap] = arr[i];
                                arr[i] = temp;
                            }
                            else {
                                continue;
                            }
                        }

                        if (arr[i+gap].totalMatches > arr[i].totalMatches) {
                            Team temp = arr[i+gap];
                            arr[i+gap] = arr[i];
                            arr[i] = temp;
                        } else break;
                    }
                }    
            }

        }

        void printArr(Team arr[]) {
            cout<<"Printing Array: \n";
            for (int i=0; i<6; i++) {
                cout<<"Team " << i+1 << " Details:\n";
                cout<<"Matches Played: " << arr[i].totalMatches << endl;
                cout<<"Team Name: " << arr[i].teamName << endl << endl;
            }
        }
};

int main () {

    Team t1(25, "Karachi");
    Team t2(15, "Lahore");
    Team t3(40, "Multan");
    Team t4(50, "Islamabad");
    Team t5(10, "Peshawar");
    Team t6(25, "KarachiKarachi");

    Team arr[] = {t1, t2, t3, t4, t5, t6};

    Team res;
    // res.sortArr(arr);
    res.shellSort(arr, 6);
    res.printArr(arr);


    

    

    return 0;
}