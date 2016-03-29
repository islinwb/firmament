// The Firmament project
// Copyright (c) 2016 Ionel Gog <ionel.gog@cl.cam.ac.uk>
//

#ifndef FIRMAMENT_SIM_DFS_SIMULATED_DATA_LAYER_MANAGER_H
#define FIRMAMENT_SIM_DFS_SIMULATED_DATA_LAYER_MANAGER_H

#include "scheduling/data_layer_manager_interface.h"

#include "misc/trace_generator.h"
#include "sim/dfs/google_block_distribution.h"
#include "sim/dfs/simulated_dfs_interface.h"
#include "sim/google_runtime_distribution.h"

namespace firmament {
namespace sim {

class SimulatedDataLayerManager : public DataLayerManagerInterface {
 public:
  SimulatedDataLayerManager(TraceGenerator* trace_generator);
  virtual ~SimulatedDataLayerManager();

  /**
   * Add files for a given task.
   * @param td the descriptor of the task
   * @param avg_runtime the average runtime of the task
   * @param long_running_service true if the task doesn't finish in the trace
   * @param max_machine_spread the maximum number of machines over which
   * the task's inputs should be spread.
   */
  uint64_t AddFilesForTask(const TaskDescriptor& td, uint64_t avg_runtime,
                           bool long_running_service,
                           uint64_t max_machine_spread);
  void AddMachine(const string& hostname, ResourceID_t machine_res_id);
  void GetFileLocations(const string& file_path,
                                list<DataLocation>* locations);
  void RemoveFilesForTask(const TaskDescriptor& td);
  void RemoveMachine(const string& hostname);

 private:
  GoogleBlockDistribution* input_block_dist_;
  GoogleRuntimeDistribution* runtime_dist_;
  SimulatedDFSInterface* dfs_;
  unordered_map<string, ResourceID_t> hostname_to_res_id_;
  TraceGenerator* trace_generator_;
};

} // namespace sim
} // namespace firmament

#endif // FIRMAMENT_SIM_DFS_SIMULATED_DATA_LAYER_MANAGER_H