#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>

using namespace std;

std::binary_semaphore semaphore(3); // Sémaphore binaire avec une capacité de 3

void utiliser_une_ressource(int thread_id) {
    cout << "Thread " << thread_id << " veut utiliser une ressource." << std::endl;
    semaphore.acquire(); // Acquérir un jeton
    cout << "Thread " << thread_id << " a obtenu une ressource." << std::endl;
    // Simuler une utilisation de la ressource (attente)
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Thread " << thread_id << " a terminé d'utiliser la ressource." << std::endl;
    semaphore.release(); // Libérer un jeton
    cout << "Thread " << thread_id << " a relâché la ressource." << std::endl;
}

int main() {
    vector<std::thread> threads;

    for (int i = 0; i < 5; i++) {
        threads.emplace_back(utiliser_une_ressource, i);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Tous les threads ont terminé." << std::endl;

    return 0;
}
