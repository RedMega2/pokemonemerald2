AbandonedResort1F_SoutheastRooms_MapScripts::
	.byte 0

AbandonedResort1F_SoutheastRooms_EventScript_Bed::
	lockall
	msgbox AbandonedResort2F_Text_RoomInGoodCondition, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, AbandonedResort2F_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, AbandonedResort2F_EventScript_DeclineRest
	releaseall
	end

AbandonedResort1F_SoutheastRooms_EventScript_Rest::
	call Common_EventScript_OutOfCenterPartyHeal
	warpsilent MAP_ABANDONED_RESORT_1F_NORTHEAST_ROOMS, 0
	releaseall
	end

AbandonedResort1F_SoutheastRooms_EventScript_DeclineRest::
	releaseall
	end

AbandonedResort1F_SoutheastRooms_Text_RoomInGoodCondition::
	.string	"This room is in good condition. Take a\n"
	.string "break?$"
