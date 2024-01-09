#include <iostream>

using namespace std;

class CppProject {
    private:
        const int projectId;
        string* members;
        int noMembers;
        int noLinesOfCode = 0;
        enum type { TEAM, INDIVIDUAL };
        type projectType;
        bool isComplex = false;
        static const int LINES_OF_CODE_PER_HOUR = 30;
    public:
        CppProject(const CppProject &sample) : projectId(sample.projectId) {
            this->noMembers = sample.noMembers;
            this->noLinesOfCode = sample.noLinesOfCode;
            this->projectType = sample.projectType;
            this->isComplex = sample.isComplex;

            this->members = new string[sample.noMembers];
            
            for (int i = 0; i < sample.noMembers; i++) {
                this->members[i] = sample.members[i];
            }
        }
        CppProject(int projectId, string member):projectId(projectId) {
            this->members = new string[1];
            this->members[0] = member;
            this->projectType = INDIVIDUAL;
            this->noMembers = 1;
        }
        CppProject(int projectId, string* members, int noPersons):projectId(projectId) {
            this->members = new string[noPersons];
            this->noMembers = noPersons;

            for (int i = 0; i < noPersons; i++) {
                this->members[i] = members[i];
            }

            this->projectType = TEAM;
            this->isComplex = true;
        }
        CppProject& operator=(const CppProject &sample) {
            this->noMembers = sample.noMembers;
            this->noLinesOfCode = sample.noLinesOfCode;
            this->projectType = sample.projectType;
            this->isComplex = sample.isComplex;

            this->members = new string[sample.noMembers];
            
            for (int i = 0; i < sample.noMembers; i++) {
                this->members[i] = sample.members[i];
            }
            return *this;
        };
        bool operator>(const CppProject &sample) {
            if (this->noLinesOfCode > sample.noLinesOfCode) {
                return true;
            }
            return false;
        }
        void operator+=(string member) {
            string* members = this->members;
            delete[] this->members;

            this->noMembers += 1;

            this->members = new string[this->noMembers];

            for (int i = 0; i < noMembers - 1; i++) {
                this->members[i] = members[i];
            }
            this->members[this->noMembers - 1] = member;
        };
        operator float() const {
            return float(this->noLinesOfCode) / float(this->LINES_OF_CODE_PER_HOUR);
        }
        ~CppProject() {
            delete[] this->members;
        }
        void showMembers() {
            for (int i = 0; i < this->noMembers; i++) {
                cout << members[i] << " ";
            }
        }
        int getNoLinesOfCode() {
            return this->noLinesOfCode;
        }
        void setNoLinesOfCode(int noLinesOfCode) {
            this->noLinesOfCode = noLinesOfCode;
        }
        const char* getType() {
            switch (this->projectType) {
                case INDIVIDUAL:
                    return "Individual";
                case TEAM:
                    return "Team";
            }
        }
        bool isEasy() {
            return !this->isComplex;
        }
        int getId() {
            return this->projectId;
        }
        void markAsEasy() {
            this->isComplex = false;
        }
        void writeCode(int linesOfCode) {
            this->noLinesOfCode += linesOfCode;
        }
};

// ostream& operator<<(ostream& os, const CppProject &sample) {
//     os << "Members: " << sample.noMembers << endl;
//     os << "Lines of code: " << sample.noLinesOfCode << endl;
//     os << "Project type: " << sample.projectType << endl;
//     os << "Difficult: " << (sample.isComplex ? "Yes" : "No") << endl;
//     os << "Members: ";
//     for (int i = 0; i < sample.noMembers; i++) {
//         os << sample.members[i] << " ";
//     }
//     os << endl;
// }

int main() {
    int projectId = 1;
    string members[3] = { "John", "Dahyla", "Bob" };
    string employees[3] = { "Mark", "Dana", "Liurnia" };
    int noPersons = 3;

    CppProject project1 = CppProject(1, members, noPersons);
    project1 += "Alice";

    project1.showMembers();

    float approximatePages = float(project1);
    cout << endl;
    cout << approximatePages;
}