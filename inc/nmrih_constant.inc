/** Double-include prevention */
#if defined _nmrih_constant_utils_included_
  #endinput
#endif
#define _nmrih_constant_utils_included_

/**
 * Author   F1F88
 * url      https://github.com/F1F88
 * Version  1.0.0
 */


#define AE_TYPE_SERVER                      1           // Animation event flag which indicates an event is supposed to be serverside only.
#define AE_TYPE_SCRIPTED                    2           // Animation event flag with an unknown purpose.
#define AE_TYPE_SHARED                      4           // Animation event flag which indicates an event is supposed to be shared between the server and client.
#define AE_TYPE_WEAPON                      8           // Animation event flag which indicates an event is part of a weapon.
#define AE_TYPE_CLIENT                      16          // Animation event flag which indicates an event is supposed to be clientside only.
#define AE_TYPE_FACEPOSER                   32          // Animation event flag with an unknown purpose. Presumably related to Faceposer.
#define AE_TYPE_NEWEVENTSYSTEM              1024        // Animation event flag which indicates an event is using the new system. This is often used by class-specific events from NPCs.


enum
{
    CHAN_REPLACE                            = -1,       // The sound channel used when playing sounds through console commands.
    CHAN_AUTO                               = 0,        // The default generic sound channel.
    CHAN_WEAPON                             = 1,        // The sound channel for player and NPC weapons.
    CHAN_VOICE                              = 2,        // The sound channel used for dialogue, voice lines, etc.
    CHAN_ITEM                               = 3,        // The sound channel used for generic physics impact sounds, health/suit chargers, +use sounds.
    CHAN_BODY                               = 4,        // The sound channel used for clothing, ragdoll impacts, footsteps, knocking/pounding/punching etc.
    CHAN_STREAM                             = 5,        // The sound channel for sounds that can be delayed by an async load, i.e. aren't responses to particular events.
    CHAN_STATIC                             = 6,        // The sound channel for constant/background sound that doesn't require any reaction.
    CHAN_VOICE2                             = 7,        // An additional sound channel for voices. Used in TF2 for the announcer.
    CHAN_VOICE_BASE                         = 8         // The sound channel used for network voice data (online voice communications).
};


/**
 * Collision group used in GetCollisionGroup(), etc.
 */
enum Collision_Group_t
{
    COLLISION_GROUP_NONE                    = 0,
    COLLISION_GROUP_DEBRIS                  = 1,        // Collides with nothing but world and static stuff
    COLLISION_GROUP_DEBRIS_TRIGGER          = 2,        // Same as debris, but hits triggers
    COLLISION_GROUP_INTERACTIVE_DEBRIS      = 3,        // Collides with everything except other interactive debris or debris
    COLLISION_GROUP_INTERACTIVE             = 4,        // Collides with everything except interactive debris or debris
    COLLISION_GROUP_PLAYER                  = 5,
    COLLISION_GROUP_BREAKABLE_GLASS         = 6,
    COLLISION_GROUP_VEHICLE                 = 7,
    COLLISION_GROUP_PLAYER_MOVEMENT         = 8,        // For HL2, same as Collision_Group_Player, for
                                                        // TF2, this filters out other players and CBaseObjects
    COLLISION_GROUP_NPC                     = 9,        // Generic NPC group
    COLLISION_GROUP_IN_VEHICLE              = 19,       // for any entity inside a vehicle
    COLLISION_GROUP_WEAPON                  = 20,       // for any weapons that need collision detection
    COLLISION_GROUP_VEHICLE_CLIP            = 21,       // vehicle clip brush to restrict vehicle movement
    COLLISION_GROUP_PROJECTILE              = 22,       // Projectiles!
    COLLISION_GROUP_DOOR_BLOCKER            = 23,       // Blocks entities not permitted to get near moving doors
    COLLISION_GROUP_PASSABLE_DOOR           = 24,       // Doors that the player shouldn't collide with
    COLLISION_GROUP_DISSOLVING              = 25,       // Things that are dissolving are in this group
    COLLISION_GROUP_PUSHAWAY                = 26,       // Nonsolid on client and server, pushaway in player code

    COLLISION_GROUP_NPC_ACTOR               = 27,       // Used so NPCs in scripts ignore the player.
    COLLISION_GROUP_NPC_SCRIPTED            = 28,       // USed for NPCs in scripts that should not collide with each other

    COLLISION_GROUP_INVENTORY_BOX           = 34,       // ref: https://github.com/dysphie/nmrih-qol-ex/blob/7a1d5f393d9c8b9de163166828e45f5b9c88d0a8/scripting/qol.sp#L80
    COLLISION_GROUP_CARRIED_OBJECT          = 34,       // ref: https://github.com/dysphie/nmrih-qol-ex/blob/7a1d5f393d9c8b9de163166828e45f5b9c88d0a8/scripting/qol.sp#L81
};


// settings for m_takedamage
#define DAMAGE_NO                           0           // Don't take damage (Use with GetTakeDamage/SetTakeDamage)
#define DAMAGE_EVENTS_ONLY                  1           // Call damage functions, but don't modify health (Use with GetTakeDamage/SetTakeDamage)
#define DAMAGE_YES                          2           // Allow damage to be taken (Use with GetTakeDamage/SetTakeDamage)
#define DAMAGE_AIM                          3           // (Use with GetTakeDamage/SetTakeDamage)


#define D_ER                                0           // 'Error' relationship definition. Used by NPCs and players for relationship disposition.
#define D_HT                                1           // Denotes a 'Hate' relationship. Used by NPCs and players for relationship disposition.
#define D_FR                                2           // Denotes a 'Fear' relationship. Used by NPCs and players for relationship disposition.
#define D_LI                                3           // Denotes a 'Like' relationship. Used by NPCs and players for relationship disposition.
#define D_NU                                4           // Denotes a 'Neutral' relationship. Used by NPCs and players for relationship disposition.


// entity effects
enum
{
    EF_BONEMERGE            = 0x001,    // Performs bone merge on client side
    EF_BRIGHTLIGHT          = 0x002,    // DLIGHT centered at entity origin
    EF_DIMLIGHT             = 0x004,    // player flashlight
    EF_NOINTERP             = 0x008,    // don't interpolate the next frame
    EF_NOSHADOW             = 0x010,    // Don't cast no shadow
    EF_NODRAW               = 0x020,    // don't draw entity
    EF_NORECEIVESHADOW      = 0x040,    // Don't receive no shadow
    EF_BONEMERGE_FASTCULL   = 0x080,    // For use with EF_BONEMERGE. If this is set, then it places this ent's origin at its
                                        // parent and uses the parent's bbox + the max extents of the aiment.
                                        // Otherwise, it sets up the parent's bones every frame to figure out where to place
                                        // the aiment, which is inefficient because it'll setup the parent's bones even if
                                        // the parent is not in the PVS.
    EF_ITEM_BLINK           = 0x100,    // blink an item so that the user notices it.
    EF_PARENT_ANIMATES      = 0x200,    // always assume that the parent entity is animating
    EF_MAX_BITS = 10
};


// entity flags, CBaseEntity::m_iEFlags
enum
{
    EFL_KILLME =                            (1<<0),     // This entity is marked for death -- This allows the game to actually delete ents at a safe time
    EFL_DORMANT =                           (1<<1),     // Entity is dormant, no updates to client
    EFL_NOCLIP_ACTIVE =                     (1<<2),     // Lets us know when the noclip command is active.
    EFL_SETTING_UP_BONES =                  (1<<3),     // Set while a model is setting up its bones.
    EFL_KEEP_ON_RECREATE_ENTITIES =         (1<<4),     // This is a special entity that should not be deleted when we restart entities only

    EFL_HAS_PLAYER_CHILD=                   (1<<4),     // One of the child entities is a player.

    EFL_DIRTY_SHADOWUPDATE =                (1<<5),     // Client only- need shadow manager to update the shadow...
    EFL_NOTIFY =                            (1<<6),     // Another entity is watching events on this entity (used by teleport)

    // The default behavior in ShouldTransmit is to not send an entity if it doesn't
    // have a model. Certain entities want to be sent anyway because all the drawing logic
    // is in the client DLL. They can set this flag and the engine will transmit them even
    // if they don't have a model.
    EFL_FORCE_CHECK_TRANSMIT =              (1<<7),

    EFL_BOT_FROZEN =                        (1<<8),     // This is set on bots that are frozen.
    EFL_SERVER_ONLY =                       (1<<9),     // Non-networked entity.
    EFL_NO_AUTO_EDICT_ATTACH =              (1<<10),    // Don't attach the edict; we're doing it explicitly

    // Some dirty bits with respect to abs computations
    EFL_DIRTY_ABSTRANSFORM =                (1<<11),
    EFL_DIRTY_ABSVELOCITY =                 (1<<12),
    EFL_DIRTY_ABSANGVELOCITY =              (1<<13),
    EFL_DIRTY_SURROUNDING_COLLISION_BOUNDS =(1<<14),
    EFL_DIRTY_SPATIAL_PARTITION =           (1<<15),
//    UNUSED                        = (1<<16),

    EFL_IN_SKYBOX =                         (1<<17),    // This is set if the entity detects that it's in the skybox.
                                                        // This forces it to pass the "in PVS" for transmission.
    EFL_USE_PARTITION_WHEN_NOT_SOLID =      (1<<18),    // Entities with this flag set show up in the partition even when not solid
    EFL_TOUCHING_FLUID =                    (1<<19),    // Used to determine if an entity is floating

    // FIXME: Not really sure where I should add this...
    EFL_IS_BEING_LIFTED_BY_BARNACLE =       (1<<20),
    EFL_NO_ROTORWASH_PUSH =                 (1<<21),    // I shouldn't be pushed by the rotorwash
    EFL_NO_THINK_FUNCTION =                 (1<<22),
    EFL_NO_GAME_PHYSICS_SIMULATION =        (1<<23),

    EFL_CHECK_UNTOUCH =                     (1<<24),
    EFL_DONTBLOCKLOS =                      (1<<25),    // I shouldn't block NPC line-of-sight
    EFL_DONTWALKON =                        (1<<26),    // NPC;s should not walk on this entity
    EFL_NO_DISSOLVE =                       (1<<27),    // These guys shouldn't dissolve
    EFL_NO_MEGAPHYSCANNON_RAGDOLL =         (1<<28),    // Mega physcannon can't ragdoll these guys.
    EFL_NO_WATER_VELOCITY_CHANGE  =         (1<<29),    // Don't adjust this entity's velocity when transitioning into water
    EFL_NO_PHYSCANNON_INTERACTION =         (1<<30),    // Physcannon can't pick these up or punt them
    EFL_NO_DAMAGE_FORCES =                  (1<<31),    // Doesn't accept forces from physics damage
};


// Hud Element hiding flags
#define	HIDEHUD_WEAPONSELECTION		( 1<<0 )	        // Hide ammo count & weapon selection
#define	HIDEHUD_FLASHLIGHT			( 1<<1 )
#define	HIDEHUD_ALL					( 1<<2 )
#define HIDEHUD_HEALTH				( 1<<3 )	        // Hide health & armor / suit battery
#define HIDEHUD_PLAYERDEAD			( 1<<4 )	        // Hide when local player's dead
#define HIDEHUD_NEEDSUIT			( 1<<5 )	        // Hide when the local player doesn't have the HEV suit
#define HIDEHUD_MISCSTATUS			( 1<<6 )	        // Hide miscellaneous status elements (trains, pickup history, death notices, etc)
#define HIDEHUD_CHAT				( 1<<7 )	        // Hide all communication elements (saytext, voice icon, etc)
#define	HIDEHUD_CROSSHAIR			( 1<<8 )	        // Hide crosshairs
#define	HIDEHUD_VEHICLE_CROSSHAIR	( 1<<9 )	        // Hide vehicle crosshair
#define HIDEHUD_INVEHICLE			( 1<<10 )
#define HIDEHUD_BONUS_PROGRESS		( 1<<11 )	        // Hide bonus progress display (for bonus map challenges)
#define HIDEHUD_BITCOUNT			12


/**
 * Visibility enum for nav mesh hiding spots
 */
enum HidingSpot
{
    IN_COVER = 1,
    GOOD_SNIPER_SPOT = 2,
    IDEAL_SNIPER_SPOT = 4,
    EXPOSED = 8
}


/**
 * Hit groups from traces
 */
enum Hitgroup
{
    Generic = 0,
    Head = 1,
    Chest = 2,
    Stomach = 3,
    LeftArm = 4,
    RightArm = 5,
    LeftLeg = 6,
    RightLeg = 7,
    Gear = 10
}


// Button mask bindings
#undef  IN_ATTACK
#undef  IN_JUMP
#undef  IN_DUCK
#undef  IN_FORWARD
#undef  IN_BACK
#undef  IN_USE
#undef  IN_CANCEL
#undef  IN_LEFT
#undef  IN_RIGHT
#undef  IN_MOVELEFT
#undef  IN_MOVERIGHT
#undef  IN_ATTACK2
#undef  IN_RUN
#undef  IN_RELOAD
#undef  IN_ALT1
#undef  IN_ALT2
#undef  IN_SCORE
#undef  IN_SPEED
#undef  IN_WALK
#undef  IN_ZOOM
#undef  IN_WEAPON1
#undef  IN_WEAPON2
#undef  IN_BULLRUSH
#undef  IN_GRENADE1
#undef  IN_GRENADE2
#undef  IN_ATTACK3
#undef  IN_SHOVE

#define IN_ATTACK                           (1 << 0)    // Button for +attack
#define IN_JUMP                             (1 << 1)    // Button for +jump
#define IN_DUCK                             (1 << 2)    // Button for +duck
#define IN_FORWARD                          (1 << 3)    // Button for +forward
#define IN_BACK                             (1 << 4)    // Button for +back
#define IN_USE                              (1 << 5)    // Button for +use
#define IN_CANCEL                           (1 << 6)    // Special button flag for attack cancel
#define IN_LEFT                             (1 << 7)    // Button for +left
#define IN_RIGHT                            (1 << 8)    // Button for +right
#define IN_MOVELEFT                         (1 << 9)    // Button for +moveleft
#define IN_MOVERIGHT                        (1 << 10)   // Button for +moveright
#define IN_ATTACK2                          (1 << 11)   // Button for +attack2
#define IN_RUN                              (1 << 12)   // Unused button (see IN.SPEED for sprint)
#define IN_RELOAD                           (1 << 13)   // Button for +reload
#define IN_ALT1                             (1 << 14)   // Button for +alt1
#define IN_ALT2                             (1 << 15)   // Button for +alt2
#define IN_SCORE                            (1 << 16)   // Button for +score
#define IN_SPEED                            (1 << 17)   // Button for +speed
#define IN_WALK                             (1 << 18)   // Button for +walk
#define IN_ZOOM                             (1 << 19)   // Button for +zoom
#define IN_WEAPON1                          (1 << 20)   // Special button used by weapons themselves
#define IN_WEAPON2                          (1 << 21)   // Special button used by weapons themselves
#define IN_BULLRUSH                         (1 << 22)   // Unused button
#define IN_GRENADE1                         (1 << 23)   // Button for +grenade1
#define IN_GRENADE2                         (1 << 24)   // Button for +grenade2
#define IN_ATTACK3                          (1 << 25)   // Button for +attack3

#define IN_DROP_WEAPON                      (1 << 15)   // key g "+dropweapon"
#define IN_SELECT_FIRE                      (1 << 24)   // key x "+selectfire"
#define IN_MAGLITE                          (1 << 26)   // Brings up the maglite if owned and using a one handed weapon (+maglite)
#define IN_SHOVE                            (1 << 27)   // Shoves away zombies (+shove)
#define IN_COMPASS                          (1 << 28)   // key c "+compass"
#define IN_INVENTORY                        (1 << 29)   // Opens weapon inventory (+inventory)
#define IN_AMMOINV                          (1 << 30)   // Opens ammunition inventory (+ammoinv)
#define IN_VOICE_COMMAND                    (1 << 31)   // key 3 "+voicecommand"
#define IN_UNLOAD                           4194304     // ?


enum
{
    OBJ_STATE_INIT          = 0,
    OBJ_STATE_PRACTICE      = 1,
    OBJ_STATE_PREROUND      = 2,
    OBJ_STATE_RUNNING       = 3,
    OBJ_STATE_WIN           = 5,
    OBJ_STATE_LOSS          = 6,
    OBJ_STATE_RESTART       = 7,
    OBJ_STATE_GAME_OVER     = 8
}


enum
{
    WAVE_STATE_INIT         = 0,
    WAVE_STATE_PRACTICE     = 1,
    WAVE_STATE_PREROUND     = 2,
    WAVE_STATE_RUNNING      = 3,
    WAVE_STATE_WIN          = 4,
    WAVE_STATE_LOSS         = 5,
    WAVE_STATE_RESTART      = 6,
    WAVE_STATE_GAME_OVER    = 7
}


#undef  MAXPLAYERS
#define MAXPLAYERS                          9           // No More Room In Hell max players
#define NMR_MAXPLAYERS                      9           // No More Room In Hell max players


enum
{
    NMR_STATE_ACTIVE = 0, // Player state code used by living players.
    NMR_STATE_WELCOME,
    NMR_STATE_DEATH_ANIM,
    NMR_STATE_OBSERVER_MODE
}

/**
 * Spectator Movement modes
 */
enum
{
    OBS_MODE_NONE                   = 0,            // not in spectator mode
    OBS_MODE_DEATHCAM,                              // special mode for death cam animation
    OBS_MODE_FREEZECAM,                             // zooms to a target, and freeze-frames on them
    OBS_MODE_FIXED,                                 // view from a fixed camera position
    OBS_MODE_IN_EYE,                                // follow a player in first person view
    OBS_MODE_CHASE,                                 // follow a player in third person view
    OBS_MODE_POI,                                   // PASSTIME point of interest - game objective, big fight, anything interesting;
                                                    // added in the middle of the enum due to tons of hard-coded "<ROAMING" enum compares
    OBS_MODE_ROAMING,                               // free roaming

    NUM_OBSERVER_MODES
};


/**
 * ref: https://github.com/dysphie/dystopia-servers/blob/2b7f30024efa3315bd16028be47fb8b0c87648ec/addons/sourcemod/scripting/voicecmd-processor.sp#L14
 */
enum
{
    VoiceCommand_AMMO = 0,
    VoiceCommand_Follow,
    VoiceCommand_Help,
    VoiceCommand_No,
    VoiceCommand_Stay,
    VoiceCommand_Thanks,
    VoiceCommand_Yes,
    VoiceCommand_Incoming,
    VoiceCommand_Injured,
    VoiceCommand_FireInTheHole,
    VoiceCommand_Taunt,
    VoiceCommand_Pain,
    VoiceCommand_Death,
    VoiceCommand_BleedOut,
    VoiceCommand_Drown,
    VoiceCommand_TOTAL
}



/**
 * Sequences used during zombie bite.
 * ref: https://github.com/dysphie/nmrih-qol-ex/blob/7a1d5f393d9c8b9de163166828e45f5b9c88d0a8/scripting/qol.sp
 */
#define SEQUENCE_CRAWLER_BITE               9
#define SEQUENCE_BITE                       31
#define SEQUENCE_SHAMBLER_BITE              32
#define SEQUENCE_RUNNER_BITE                33


/**
 * Sequence used by barricade hammer when placing a board.
 */
#define SEQUENCE_BARRICADE_HAMMER_BARRICADE 16


/**
 * Zombie schedules.
 */
#define SCHED_ZOMBIE_CHASE_ENEMY            17
#define SCHED_ZOMBIE_MELEE_ATTACK1          41          // When a zombie tries to melee a player.
#define SCHED_ZOMBIE_SWATITEM               93          // When a zombie goes to swat/bash a prop.
#define SCHED_ZOMBIE_ATTACKITEM             94          // Zombie swipes at a prop.
#define SCHED_ZOMBIE_BASH_BARRICADE         102         // When a zombie bashes/attacks boards
#define SCHED_ZOMBIE_GRAB_ENEMY             106         // When a zombie tries to grab a player


/**
 * Zombie activities.
 */
#define ACT_WALK                            6
#define ACT_CLIMB_UP                        41
#define ACT_MELEE_ATTACK1                   71
#define ACT_SHOVE                           961
#define ACT_SHOVE_LEFT                      962
#define ACT_SHOVE_RIGHT                     963
#define ACT_SHOVE_BEHIND                    964


/**
 * NPC state type used in GetNPCState(), etc.
 */
enum
{
    NPC_STATE_INVALID = -1,
    NPC_STATE_NONE = 0,
    NPC_STATE_IDLE = 1,
    NPC_STATE_ALERT = 2,
    NPC_STATE_COMBAT = 3,
    NPC_STATE_SCRIPT = 4,
    NPC_STATE_PLAYDEAD = 5,
    NPC_STATE_PRONE = 6,
    NPC_STATE_DEAD = 7,
}


// Old values
#define OLD_ARMOR_RATIO	 0.2	// Armor Takes 80% of the damage
#define OLD_ARMOR_BONUS  0.5	// Each Point of Armor is work 1/x points of health

// New values
#define ARMOR_RATIO	0.2
#define ARMOR_BONUS	1.0
