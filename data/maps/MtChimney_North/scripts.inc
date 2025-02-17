MtChimney_North_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_North_OnResume
	map_script MAP_SCRIPT_ON_LOAD, MtChimney_North_OnLoad
	.byte 0

MtChimney_North_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtChimney_North_EventScript_TryRemoveMoltres
	end

MtChimney_North_EventScript_TryRemoveMoltres::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MtChimney_North_OnLoad:
	call_if_set FLAG_CAUGHT_MOLTRES, MtChimney_North_EventScript_HideMoltres
	call_if_unset FLAG_CAUGHT_MOLTRES, MtChimney_North_EventScript_TryShowMoltres
	end

MtChimney_North_EventScript_HideMoltres::
	setflag FLAG_HIDE_MOLTRES
	return

MtChimney_North_EventScript_TryShowMoltres::
	goto_if_set FLAG_DEFEATED_ENTEI, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MOLTRES
	return

MtChimney_North_EventScript_Moltres::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	delay 20
	waitmoncry
	setwildbattle SPECIES_MOLTRES, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MtChimney_North_EventScript_DefeatedMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtChimney_North_EventScript_RanFromMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MtChimney_North_EventScript_RanFromMoltres
	setflag FLAG_DEFEATED_MOLTRES
	release
	end

MtChimney_North_EventScript_DefeatedMoltres::
	setflag FLAG_DEFEATED_MOLTRES
	goto Common_EventScript_RemoveStaticPokemon
	end

MtChimney_North_EventScript_RanFromMoltres::
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end
