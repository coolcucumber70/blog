# qt_note
自己记录的笔记
这个是我的qt的blog，我会实时的进行更新！
现在我建立一个dev的分支
a+c=f
a+v风俗地方

ModuleNotFoundError: No module named 'light_malib'
Traceback (most recent call last):
File "main_pbt.py", line 131, in <module>
main()
File "main_pbt.py", line 119, in main
runner.run()
File "/workspace/GRF_MARL/light_malib/framework/pbt_runner.py", line 100, in run
self.evaluation_manager.eval()
File "/workspace/GRF_MARL/light_malib/evaluation/evaluation_manager.py", line 43, in eval
eval_results = ray.get(
File "/root/miniconda3/envs/ray-work/lib/python3.8/site-packages/ray/_private/auto_init_hook.py", line 21, in auto_init_wrapper
return fn(*args, **kwargs)
File "/root/miniconda3/envs/ray-work/lib/python3.8/site-packages/ray/_private/client_mode_hook.py", line 103, in wrapper
return func(*args, **kwargs)
File "/root/miniconda3/envs/ray-work/lib/python3.8/site-packages/ray/_private/worker.py", line 2667, in get
values, debugger_breakpoint = worker.get_objects(object_refs, timeout=timeout)
File "/root/miniconda3/envs/ray-work/lib/python3.8/site-packages/ray/_private/worker.py", line 864, in get_objects
raise value.as_instanceof_cause()
ray.exceptions.RayTaskError(RayActorError): ray::RolloutManager.rollout_eval() (pid=6038, ip=10.244.24.118, actor_id=5b87908f091041670c8ebd3e04000000, repr=<light_malib.rollout.rollout_manager.RolloutManager object at 0x7066d2bb41f0>)
File "/workspace/GRF_MARL/light_malib/rollout/rollout_manager.py", line 130, in rollout_eval
results = self.reduce_rollout_eval_results(rollout_results)
File "/workspace/GRF_MARL/light_malib/rollout/rollout_manager.py", line 611, in reduce_rollout_eval_results
for rollout_result in rollout_results:
File "/root/miniconda3/envs/ray-work/lib/python3.8/site-packages/ray/util/actor_pool.py", line 170, in get_generator
yield self.get_next_unordered()
File "/root/miniconda3/envs/ray-work/lib/python3.8/site-packages/ray/util/actor_pool.py", line 370, in get_next_unordered
return ray.get(future)
ray.exceptions.RayActorError: The actor died because of an error raised in its creation task, ray::RolloutWorker.__init__() (pid=1026, ip=10.244.24.117, actor_id=4fb2f1dd061f2809dae37a6a04000000, repr=<light_malib.rollout.rollout_worker.FunctionActorManager._create_fake_actor_class.<locals>.TemporaryActor object at 0x79c696f96f40>)
At least one of the input arguments for this task could not be computed:
ray.exceptions.RaySystemError: System error: No module named 'light_malib'
traceback: Traceback (most recent call last):
ModuleNotFoundError: No module named 'light_malib'
﻿