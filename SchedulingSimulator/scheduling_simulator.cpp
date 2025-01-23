#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip> // Include for std::setprecision

// Task structure to hold process information
struct Task {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int start_time = -1;
    int finish_time = -1;
};

// Function to read tasks from the input file
std::vector<Task> readTasks(const std::string& filename) {
    std::vector<Task> tasks;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Task task;
        iss >> task.pid >> task.arrival_time >> task.burst_time;
        task.remaining_time = task.burst_time;  // Initialize remaining time for preemptive scheduling
        tasks.push_back(task);
    }

    return tasks;
}

// Function to simulate First Come First Serve (FCFS) scheduling
void simulateFCFS(std::vector<Task> tasks) {
    std::cout << "Scheduling algorithm: FCFS\n";
    std::cout << "Total " << tasks.size() << " tasks are read from \"input.1\". press 'enter' to start...\n";
    std::cin.ignore(); // Wait for user input before starting
    std::cout << "==================================================================\n";

    int time = 0;
    int completed_tasks = 0;
    double total_wait_time = 0;
    double total_turnaround_time = 0;

    while (completed_tasks < tasks.size()) {
        auto current_task = std::find_if(tasks.begin(), tasks.end(), [&](Task& t) {
            return t.arrival_time <= time && t.finish_time == -1;
        });

        if (current_task != tasks.end()) {
            while (current_task->remaining_time > 0) {
                std::cout << "<system time " << time << "> process " << current_task->pid << " is running\n";
                current_task->remaining_time--;
                time++;
                total_turnaround_time++; // Increment total turnaround time
            }
            current_task->finish_time = time;
            std::cout << "<system time " << time << "> process " << current_task->pid << " is finished.......\n";
            completed_tasks++;
        } else {
            std::cout << "<system time " << time << "> idle\n";
            time++;
        }
    }

    std::cout << "<system time " << time << "> All processes finish ....................\n";
    std::cout << "============================================================\n";
    // Calculate average times
    for (const auto& task : tasks) {
        double turnaround_time = task.finish_time - task.arrival_time;
        double wait_time = turnaround_time - task.burst_time;
        total_wait_time += wait_time;
    }

    std::cout << "Average cpu usage: 100.00 %\n";
    std::cout << "Average waiting time: " << std::fixed << std::setprecision(2) << total_wait_time / tasks.size() << "\n";
    std::cout << "Average response time: " << std::fixed << std::setprecision(2) << total_wait_time / tasks.size() << "\n";
    std::cout << "Average turnaround time: " << std::fixed << std::setprecision(2) << total_turnaround_time / tasks.size() << "\n";
    std::cout << "============================================================\n";
}

// Function to simulate Round Robin (RR) scheduling
void simulateRR(std::vector<Task> tasks, int time_quantum) {
    std::cout << "Scheduling algorithm: RR\n";
    std::cout << "Total " << tasks.size() << " tasks are read from \"input.1\". press 'enter' to start...\n";
    std::cin.ignore(); // Wait for user input before starting
    std::cout << "==================================================================\n";

    int time = 0;
    std::queue<Task*> ready_queue;
    int completed_tasks = 0;
    double total_wait_time = 0;
    double total_turnaround_time = 0;

    while (completed_tasks < tasks.size()) {
        // Add newly arrived tasks to the ready queue
        for (auto& task : tasks) {
            if (task.arrival_time == time) {
                ready_queue.push(&task);
            }
        }

        if (!ready_queue.empty()) {
            Task* current_task = ready_queue.front();
            ready_queue.pop();

            while (current_task->remaining_time > 0) {
                std::cout << "<system time " << time << "> process " << current_task->pid << " is running\n";
                int execution_time = std::min(time_quantum, current_task->remaining_time);
                current_task->remaining_time -= execution_time;
                time += execution_time;

                // Print messages based on the current execution state
                if (current_task->remaining_time > 0) {
                    ready_queue.push(current_task);  // Re-add to the queue if not finished
                } else {
                    current_task->finish_time = time;
                    std::cout << "<system time " << time << "> process " << current_task->pid << " is finished.......\n";
                    completed_tasks++;
                }
            }
        } else {
            std::cout << "<system time " << time << "> idle\n";
            time++;
        }
    }

    std::cout << "<system time " << time << "> All processes finish ....................\n";
    std::cout << "============================================================\n";
    // Calculate average times
    for (const auto& task : tasks) {
        double turnaround_time = task.finish_time - task.arrival_time;
        double wait_time = turnaround_time - task.burst_time;
        total_wait_time += wait_time;
    }

    std::cout << "Average cpu usage: 100.00 %\n";
    std::cout << "Average waiting time: " << std::fixed << std::setprecision(2) << total_wait_time / tasks.size() << "\n";
    std::cout << "Average response time: " << std::fixed << std::setprecision(2) << total_wait_time / tasks.size() << "\n";
    std::cout << "Average turnaround time: " << std::fixed << std::setprecision(2) << total_turnaround_time / tasks.size() << "\n";
    std::cout << "============================================================\n";
}

// Function to simulate Shortest Job First (SJF) scheduling
void simulateSJF(std::vector<Task> tasks) {
    std::cout << "Scheduling algorithm: SJF\n";
    std::cout << "Total " << tasks.size() << " tasks are read from \"input.1\". press 'enter' to start...\n";
    std::cin.ignore(); // Wait for user input before starting
    std::cout << "==================================================================\n";

    int time = 0;
    int completed_tasks = 0;
    double total_wait_time = 0;
    double total_turnaround_time = 0;

    while (completed_tasks < tasks.size()) {
        auto current_task = std::min_element(tasks.begin(), tasks.end(), [&](Task& t1, Task& t2) {
            if (t1.remaining_time == 0) return false; // t1 already completed
            if (t2.remaining_time == 0) return true;  // t2 already completed
            return t1.remaining_time < t2.remaining_time && t1.arrival_time <= time;
        });

        if (current_task != tasks.end() && current_task->arrival_time <= time && current_task->remaining_time > 0) {
            while (current_task->remaining_time > 0) {
                std::cout << "<system time " << time << "> process " << current_task->pid << " is running\n";
                current_task->remaining_time--;
                time++;
                total_turnaround_time++;
            }
            current_task->finish_time = time;
            std::cout << "<system time " << time << "> process " << current_task->pid << " is finished.......\n";
            completed_tasks++;
        } else {
            std::cout << "<system time " << time << "> idle\n";
            time++;
        }
    }

    std::cout << "<system time " << time << "> All processes finish ....................\n";
    std::cout << "============================================================\n";
    // Calculate average times
    for (const auto& task : tasks) {
        double turnaround_time = task.finish_time - task.arrival_time;
        double wait_time = turnaround_time - task.burst_time;
        total_wait_time += wait_time;
    }

    std::cout << "Average cpu usage: 100.00 %\n";
    std::cout << "Average waiting time: " << std::fixed << std::setprecision(2) << total_wait_time / tasks.size() << "\n";
    std::cout << "Average response time: " << std::fixed << std::setprecision(2) << total_wait_time / tasks.size() << "\n";
    std::cout << "Average turnaround time: " << std::fixed << std::setprecision(2) << total_turnaround_time / tasks.size() << "\n";
    std::cout << "============================================================\n";
}

// Main function to run the simulator
int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <scheduling_algorithm> [time_quantum]\n";
        return 1;
    }

    std::string input_file = argv[1];
    std::string scheduling_algorithm = argv[2];
    int time_quantum = (argc == 4) ? std::stoi(argv[3]) : 0; // Optional time quantum for RR

    std::vector<Task> tasks = readTasks(input_file);

    if (scheduling_algorithm == "FCFS") {
        simulateFCFS(tasks);
    } else if (scheduling_algorithm == "SJF") {
        simulateSJF(tasks);
    } else if (scheduling_algorithm == "RR") {
        if (time_quantum <= 0) {
            std::cerr << "Time quantum must be positive for RR scheduling.\n";
            return 1;
        }
        simulateRR(tasks, time_quantum);
    } else {
        std::cerr << "Unknown scheduling algorithm: " << scheduling_algorithm << "\n";
        return 1;
    }

    return 0;
}