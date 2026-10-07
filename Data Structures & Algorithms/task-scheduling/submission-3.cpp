class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> frequency(26, 0);

        for (char task : tasks) {
            frequency[task - 'A']++;
        }

        // Frequencies of tasks that are ready to run
        priority_queue<int> availableTasks;

        for (int freq : frequency) {
            if (freq > 0) {
                availableTasks.push(freq);
            }
        }

        // {remaining frequency, time when task becomes available}
        queue<pair<int, int>> cooldownQueue;

        int currentTime = 0;

        while (!availableTasks.empty() || !cooldownQueue.empty()) {

            // If nothing is available, jump to the next available task
            if (availableTasks.empty()) {
                currentTime = cooldownQueue.front().second;
            }
            else {
                // Execute the task with the highest frequency
                currentTime++;

                int remainingFrequency = availableTasks.top() - 1;
                availableTasks.pop();

                // If task still has copies, put it on cooldown
                if (remainingFrequency > 0) {
                    cooldownQueue.push({
                        remainingFrequency,
                        currentTime + n
                    });
                }
            }

            // Move tasks whose cooldown is finished back to availableTasks
            if (!cooldownQueue.empty() &&
                cooldownQueue.front().second == currentTime) {

                availableTasks.push(cooldownQueue.front().first);
                cooldownQueue.pop();
            }
        }

        return currentTime;
    }
};