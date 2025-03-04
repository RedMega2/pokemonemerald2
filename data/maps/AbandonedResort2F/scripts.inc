AbandonedResort2F_MapScripts::
	.byte 0

AbandonedResort2f_EventScript_Bed::
	lockall
	msgbox AbandonedResort2F_Text_RoomInGoodCondition, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, AbandonedResort2F_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, AbandonedResort2F_EventScript_DeclineRest
	releaseall
	end

AbandonedResort2F_EventScript_Rest::
	call Common_EventScript_OutOfCenterPartyHeal
	warpsilent MAP_ABANDONED_RESORT2F, 0
	releaseall
	end

AbandonedResort2F_EventScript_DeclineRest::
	releaseall
	end

AbandonedResort2F_Text_RoomInGoodCondition::
	.string	"This room is in good condition. Take a\n"
	.string "break?$"
