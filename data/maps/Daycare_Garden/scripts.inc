.set LOCALID_DAYCARE_MAN, 1
.set LOCALID_DAYCARE_MON_0, 2
.set LOCALID_DAYCARE_MON_1, 3

Daycare_Garden_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Daycare_Garden_OnTransition
	.byte 0

Daycare_Garden_OnTransition:
	call Daycare_Garden_EventScript_TryMoveDayCareMan
	@ set flags for OW daycare mons
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	getdaycaregfx VAR_OBJ_GFX_ID_0, VAR_OBJ_GFX_ID_1, VAR_TEMP_0, VAR_TEMP_1
	switch VAR_RESULT
	case 2, Daycare_Garden_EventScript_ShowDaycareMon1
	case 1, Daycare_Garden_EventScript_ShowDaycareMon0
	end

Daycare_Garden_EventScript_ShowDaycareMon1:
	@ set pokemon movement type based on compatibility
	special SetDaycareCompatibilityString
	call_if_eq VAR_RESULT, PARENTS_INCOMPATIBLE, Daycare_Garden_EventScript_DaycareMonIncompatible
	@ Don't do anything if PARENTS_LOW_COMPATIBILITY
	call_if_eq VAR_RESULT, PARENTS_MED_COMPATIBILITY, Daycare_Garden_EventScript_DaycareMonMedCompatibility
	call_if_eq VAR_RESULT, PARENTS_MAX_COMPATIBILITY, Daycare_Garden_EventScript_DaycareMonMaxCompatibility
	clearflag FLAG_TEMP_2
Daycare_Garden_EventScript_ShowDaycareMon0:
	clearflag FLAG_TEMP_1
	end

Daycare_Garden_EventScript_DaycareMonIncompatible: @ mons never face each other
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_FACE_DOWN_UP_AND_RIGHT
	return

Daycare_Garden_EventScript_DaycareMonMedCompatibility: @ down and towards each other
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_FACE_DOWN_AND_LEFT
	return

Daycare_Garden_EventScript_DaycareMonMaxCompatibility: @ facing; walk in place
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	return

Daycare_Garden_EventScript_TryMoveDayCareMan::
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, Daycare_Garden_EventScript_StopMoveDayCareMan
	setobjectxyperm LOCALID_DAYCARE_MAN, 29, 9
Daycare_Garden_EventScript_StopMoveDayCareMan::
	return

Daycare_Garden_EventScript_Sign::
	msgbox Daycare_Garden_Text_Sign, MSGBOX_SIGN
	end

Daycare_Garden_Text_Sign:
	.string "Taking a stroll or riding a bike through\n"
	.string "the garden should help pass the time\p"
	.string "while waiting for an egg to hatch.\p"
	.string "Make sure you bring along a pokemon with\n"
	.string "a warm body to look after the egg!$"
