
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id,AT,BT,PR,ST,CT,WT,TAT;
};

bool comparePR(const Process& p1, const Process& p2) {
    if (p1.AT == 0 && p2.AT != 0) {
        return true;
    } else if (p1.AT != 0 && p2.AT == 0) {
        return false;
    } else {
        return p1.PR < p2.PR;
    }
}


void calculateTimes(std::vector<Process>& jobs) {
    std::sort(jobs.begin(), jobs.end(), comparePR);

    int currentTime = 0;
    if (jobs[0].AT > 0) {
        currentTime = jobs[0].AT;
    }
    for (int i = 0; i < jobs.size(); ++i) {
        if (currentTime < jobs[i].AT) {
            currentTime = jobs[i].AT;
        }
        jobs[i].ST = currentTime;
        jobs[i].CT = currentTime + jobs[i].BT;
        jobs[i].TAT = jobs[i].CT - jobs[i].AT;
        jobs[i].WT = jobs[i].TAT - jobs[i].BT;
        currentTime = jobs[i].CT;
    }
}

void displayResults(const vector<Process>& jobs) {
    cout << "ID\tAT\tBT\tPR\tST\tCT\tWT\tTAT\n";
    cout << "--\t--\t--\t--\t--\t--\t--\t---\n";
    for (const auto& p : jobs) {
        cout<<"P" << p.id << "\t" << p.AT << "\t"
            << p.BT<<"\t"<<p.PR<<"\t"<< p.ST << "\t"
            << p.CT << "\t" << p.WT << "\t"
            << p.TAT << endl;
    }
}


double calAverageTAT(const vector<Process>& jobs,int n) {
    double sumTAT = 0.0;

    for (const auto& process : jobs) {
        sumTAT += process.TAT;
    }

    return sumTAT / n;
}
double calAverageWT(const vector<Process>& jobs,int n) {
    double sumWT = 0.0;

    for (const auto& process : jobs) {
        sumWT += process.WT;
    }

    return sumWT / n;
}

double calThroughput(const vector<Process>& jobs, int totalTime) {
    int n = jobs.size();
    double throughput = static_cast<double>(n) / totalTime;

    return throughput;
}


int main() {
    int n;
    std::cout << "Enter the number of jobs: ";
    std::cin >> n;

    std::vector<Process> jobs(n);

    for (int i = 0; i < n; ++i) {
        jobs[i].id = i+1;
        std::cout << "P" << jobs[i].id   ;
        std::cout << " Arrival Time: ";
        std::cin >> jobs[i].AT;
        std::cout << "Burst Time: ";
        std::cin >> jobs[i].BT;
        std::cout << "PR: ";
        std::cin >> jobs[i].PR;
    }

    calculateTimes(jobs);
    displayResults(jobs);
    
    double avgTAT = calAverageTAT(jobs,n);
    cout << "Average Turnaround Time: " << avgTAT << endl;
    double avgWT = calAverageWT(jobs,n);
    cout << "Average Waiting Time: " << avgWT << endl;
    int totalTime = jobs[n - 1].CT - jobs[0].AT;
    double throughput = calThroughput(jobs, totalTime);
    cout << "Throughput: " << throughput << endl;

    return 0;
}

