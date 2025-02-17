Route113_South_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route113_South_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route113_South_OnResume
	.byte 0

Route113_South_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route113_South_EventScript_TryRemoveEntei
	end

Route113_South_EventScript_TryRemoveEntei::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

Route113_South_OnTransition:
	call_if_set FLAG_CAUGHT_ENTEI, Route113_South_EventScript_HideEntei
	call_if_unset FLAG_CAUGHT_ENTEI, Route113_South_EventScript_TryShowEntei
	end

Route113_South_EventScript_HideEntei::
	setflag FLAG_HIDE_ENTEI
	return

Route113_South_EventScript_TryShowEntei::
	goto_if_set FLAG_DEFEATED_ENTEI, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_ENTEI
	return

Route113_South_EventScript_Entei::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	delay 20
	waitmoncry
	setwildbattle SPECIES_ENTEI, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route113_South_EventScript_DefeatedEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route113_South_EventScript_RanFromEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route113_South_EventScript_RanFromEntei
	setflag FLAG_DEFEATED_ENTEI
	release
	end

Route113_South_EventScript_DefeatedEntei::
	setflag FLAG_DEFEATED_ENTEI
	goto Common_EventScript_RemoveStaticPokemon
	end

Route113_South_EventScript_RanFromEntei::
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryRanAway
	end

