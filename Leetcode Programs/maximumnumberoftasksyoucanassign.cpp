#include <ranges>

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
      auto n = size(tasks);
      auto m = size(workers);
      if (m < n) {
        nth_element(begin(tasks), begin(tasks) + (m - 1), end(tasks));
        sort(begin(tasks), begin(tasks) + m);
      } else {
        sort(begin(tasks), end(tasks));
      }
      sort(begin(workers), end(workers));

      auto remaining_tasks = ranges::subrange(
          begin(tasks), m  < n ? begin(tasks) + m : end(tasks));
      
      auto doable_tasks_end = ranges::upper_bound(
        remaining_tasks, workers.back() + (pills ? strength : 0));
      remaining_tasks = ranges::subrange(begin(remaining_tasks), doable_tasks_end);

      if (!remaining_tasks) return 0;
    
      auto first_worker_it = ranges::lower_bound(
          workers, remaining_tasks.front() - (pills ? strength : 0));
      auto remaining_workers = ranges::subrange(first_worker_it, cend(workers));

      if (!remaining_workers) return 0;

      if (size(remaining_tasks) > size(remaining_workers)) {
        remaining_tasks = ranges::subrange(
            begin(remaining_tasks),
            begin(remaining_tasks) + size(remaining_workers));
      }

      auto helper = Helper(remaining_tasks, remaining_workers, pills, strength);

      return *ranges::prev(
            ranges::upper_bound(
              views::iota(0, ssize(remaining_tasks) + 1),
              true,
              greater{},
              [&helper](auto num_tasks) {
                return helper.can_assign_num_tasks(num_tasks); }));
    }

private:
  template<class R1, class R2>
  struct Helper {
    Helper(R1 remaining_tasks, R2 remaining_workers, int pills,
           int strength) :
        remaining_tasks(remaining_tasks), remaining_workers(remaining_workers),
        pills(pills), strength(strength) {
    }

    bool can_assign_num_tasks(auto num_tasks) {
      auto trial_remaining_tasks =
          remaining_tasks | views::take(num_tasks) | views::reverse;
      auto trial_remaining_workers =
          ranges::subrange(remaining_workers | views::reverse | views::take(num_tasks));

      if (!pills) {
        auto worker_task_pairs = views::zip(
          trial_remaining_workers, trial_remaining_tasks);
        return ranges::all_of(worker_task_pairs, [](auto worker_task_pair) {
          auto [worker, task] = worker_task_pair;
          return worker >= task; });
      }

      auto worker_q = deque<int>{};
      auto trial_pills = pills;
      for (auto task : trial_remaining_tasks) {
        for (;
             trial_remaining_workers &&
                 trial_remaining_workers.front() + strength >= task;
             trial_remaining_workers.advance(1)) {
          worker_q.push_back(trial_remaining_workers.front());
        }
        if (empty(worker_q)) {
          return false;
        } else if (worker_q.front() >= task) {
          worker_q.pop_front();
        } else if (trial_pills) {
          worker_q.pop_back();
          --trial_pills;
        } else {
          return false;
        }
      }
      return true;
    }

    R1 remaining_tasks;
    R2 remaining_workers;
    int num_workers;
    int pills;
    int strength;
  };

};
