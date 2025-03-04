AbandonedResort_MapScripts::
	.byte 0

AbandonedResort_MapScripts_RevealWoman::
	setvar VAR_ROUTE106_STATE, 1
	clearflag FLAG_ABANDONED_RESORT_1F_NORTHWEST_ROOMS_HIDE_WOMAN
	end

AbandonedResort_MapScripts_HideWoman::
	setvar VAR_TEMP_0, 1
	setflag FLAG_ABANDONED_RESORT_1F_NORTHWEST_ROOMS_HIDE_WOMAN
	end
