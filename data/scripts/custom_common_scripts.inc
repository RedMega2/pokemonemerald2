Common_EventScript_Ommit::
	end

Common_EventScript_ForceFollowerOut::
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_ForceFollowerOut
	return

Common_Movement_ForceFollowerOut::
	exit_pokeball
	step_end
