// class H2O {
// std::counting_semaphore<2> sem_h{2};
// std::binary_semaphore sem_o{0};
// int h_cnt = 0;
// std::mutex mtx;
// public:
//     H2O() {
        
//     }

//     void hydrogen(function<void()> releaseHydrogen) {
//         sem_h.acquire();
//         releaseHydrogen();
//         mtx.lock();
//         h_cnt++;
//         if (h_cnt == 2) {
//             sem_o.release();
//             h_cnt = 0;
//         }
//         mtx.unlock();
//     }

//     void oxygen(function<void()> releaseOxygen) {
        
//         sem_o.acquire(); // when sem_o is released
//         releaseOxygen();
//         sem_h.release(2);
//     }
// };


class H2O {
std::mutex mtx;
std::binary_semaphore semO{0};
std::counting_semaphore<2> semH{2};
int cntH = 0;
int cntO = 0;
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        semH.acquire();
        mtx.lock();
        releaseHydrogen();
        cntH++;
        if(cntH == 2){
            semO.release();
            cntH = 0;
        }
        mtx.unlock();
    }

    void oxygen(function<void()> releaseOxygen) {
        semO.acquire();
        releaseOxygen();
        semH.release(2);
    }
};

