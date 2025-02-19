BedOfHoenn_MapScripts::
	.byte 0

BedOfHoenn_EventScript_WaterfallWarp::
	setvar VAR_TEMP_0, 1
	lock
	applymovement OBJ_EVENT_ID_PLAYER, BedOfHoenn_Movement_ClimbWaterfallExit
	waitmovement 0
	warp MAP_FORTREE_BASIN, 0
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
