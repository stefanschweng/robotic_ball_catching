% retrieving indexes

ind = find(T_store.Data~=0 & T_store.Data~=0.5);

time_to_catch = T_store.Data(ind);

x0_plan = x0_store.Data(ind,:)';
u0_plan = u0_store.Data(ind,:)';

qf_plan = qf_store.Data(ind,:)';

save('planning_data.mat','time_to_catch','x0_plan','u0_plan','qf_plan');
save('planning_data_raw.mat','T_store','x0_store','u0_store','qf_store');

