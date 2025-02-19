FortreeBasin_MapScripts::
	.byte 0

FortreeBasin_EventScript_LargeWaterfallWarp::
	setvar VAR_TEMP_0, 1
	lock
	applymovement OBJ_EVENT_ID_PLAYER, FortreeBasin_Movement_ClimbLargeWaterfallExit
	waitmovement 0
	warp MAP_BED_OF_HOENN, 1
	end

FortreeBasin_Movement_ClimbLargeWaterfallExit::
	ride_water_current_up
	ride_water_current_up
	ride_water_current_up
	ride_water_current_up
	ride_water_current_up
	ride_water_current_up
	step_end
