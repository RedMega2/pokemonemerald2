BedOfHoenn_MapScripts::
	.byte 0

BedOfHoenn_EventScript_WaterfallWarp::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, BedOfHoenn_Movement_ClimbWaterfallExit
	waitmovement 0
	warp MAP_BED_OF_HOENN, 1
	end

BedOfHoenn_Movement_ClimbWaterfallExit::
	ride_water_current_up
	ride_water_current_up
	ride_water_current_up
	ride_water_current_up
	ride_water_current_up
	ride_water_current_up
	ride_water_current_up
	ride_water_current_up
	ride_water_current_up
	ride_water_current_up
	step_end
