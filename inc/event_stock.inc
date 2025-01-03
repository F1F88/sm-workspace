/** Double-include prevention */
#if defined _stock_event_included
    #endinput
#endif
#define _stock_event_included

#include <sourcemod>

#pragma newdecls required
#pragma semicolon 1

/**
 * Author   dysphie
 * url      https://github.com/dysphie/nmrih-guaranteedspawn/blob/main/scripting/include/nmr_instructor.inc
 *
 * Improve  by F1F88
 * url      https://github.com/F1F88
 * Version  1.0.0
 *
 * Thread   https://forums.alliedmods.net/showthread.php?t=277983
 * Wiki     https://developer.valvesoftware.com/wiki/Env_instructor_hint
 */


#define ICON_INFO                               "icon_info"
#define ICON_SHIELD                             "icon_shield"
#define ICON_BULB                               "icon_bulb"
#define ICON_CAUTION                            "icon_caution"
#define ICON_ALERT                              "icon_alert"
#define ICON_ALERT_RED                          "icon_alert_red"
#define ICON_TIP                                "icon_tip"
#define ICON_SKULL                              "icon_skull"
#define ICON_NO                                 "icon_no"
#define ICON_RUN                                "icon_run"
#define ICON_INTERACT                           "icon_interact"
#define ICON_BUTTON                             "icon_button"
#define ICON_DOOR                               "icon_door"
#define ICON_ARROW_PLAIN                        "icon_arrow_plain"
#define ICON_ARROW_PLAIN_WHITE_DN               "icon_arrow_plain_white_dn"
#define ICON_ARROW_PLAIN_WHITE_UP               "icon_arrow_plain_white_up"
#define ICON_ARROW_UP                           "icon_arrow_up"
#define ICON_ARROW_RIGHT                        "icon_arrow_right"
#define ICON_FIRE                               "icon_fire"
#define ICON_PRESENT                            "icon_present"
#define ICON_BINDING                            "use_binding"

#define LOCATOR_ICON_FX_PULSE_SLOW              0x00000001
#define LOCATOR_ICON_FX_ALPHA_SLOW              0x00000008
#define LOCATOR_ICON_FX_SHAKE_NARROW            0x00000040
#define LOCATOR_ICON_FX_STATIC                  0x00000100 // This icon draws at a fixed location on the HUD.


/**
 * 创建一个提示，完全使用服务器/地图提供的数据
 *
 * @param client
 * @param name              提示名称，用于随后引用 (例如用指令清除提示，而不是等待其过期消失)
 * @param replaceKey        输入名称，同类信息将取代彼此
 * @param target            显示提示的实体 id
 * @param activatorUserId   激活者用户 id
 * @param timeout           消失前所需秒数, 0 = 永不
 * @param iconOnScreen      提示在画面内时的提示图标 (例如 icon_alert_red)
 * @param iconOffScreen     提示在画面外时的提示图标 (例如 icon_alert)
 * @param caption           提示文本 (例如 #ThisIsDangerous)
 * @param activatorCaption  只有激活者能看见的提示文本 (例如 #YouPushedItGood)
 * @param r                 提示颜色，使用 (r, g, b (数值范围 0-255)) 格式
 * @param g                 提示颜色，使用 (r, g, b (数值范围 0-255)) 格式
 * @param b                 提示颜色，使用 (r, g, b (数值范围 0-255)) 格式
 * @param iconOffset        相对实体原点的 Z 轴位移
 * @param range             提示剔除范围
 * @param flags             提示标签 (flags)
 * @param binding           当 use_binding 为屏幕内图标时，绑定使用
 * @param allowNoDrawTarget 设置为 false 时, 当目标实体不可见时提示将消失
 * @param noOffscreen       设置为 true 时, 提示超出玩家视野时不会显示
 * @param forceCaption      设置为 true 时, 提示即使被阻挡也会显示文本
 * @param localPlayerOnly   设置为 true 时, 只有本地玩家会看到提示
 * @param startSound
 * @param targetPos
 */

/**
 * create a hint using data supplied entirely by the server/map.
 *
 * @param client
 * @param name              what to name the hint. For referencing it again later (e.g. a kill command for the hint instead of a timeout)
 * @param replaceKey        type name so that messages of the same type will replace each other
 * @param target            entity id that the hint should display at
 * @param activatorUserId   userid id of the activator
 * @param timeout           how long in seconds until the hint automatically times out, 0 = never
 * @param iconOnScreen      the hint icon to use when the hint is onscreen. (e.g. icon_alert_red)
 * @param iconOffScreen     the hint icon to use when the hint is offscreen. (e.g. icon_alert)
 * @param caption           the hint caption. (e.g. #ThisIsDangerous)
 * @param activatorCaption  the hint caption that only the activator sees (e.g. #YouPushedItGood)
 * @param r                 the hint color in (r,g,b( format where each component is 0-255))
 * @param g                 the hint color in (r,g,b( format where each component is 0-255))
 * @param b                 the hint color in (r,g,b( format where each component is 0-255))
 * @param iconOffset        how far on the z axis to offset the hint from entity origin
 * @param range             range before the hint is culled
 * @param flags             hint flags
 * @param binding           bindings to use when use_binding is the onscreen icon
 * @param allowNoDrawTarget if false, the hint will disappear if the target entity is invisible
 * @param noOffscreen       if true, the hint will not show when outside the player view
 * @param forceCaption      if true, the hint caption will show even if the hint is occluded
 * @param localPlayerOnly   if true, only the local player will see the hint
 * @param startSound
 * @param targetPos
 */
stock void SendInstructorHint(int client, const char[] name,
    const char[] replaceKey, int target, int activatorUserId, int timeout,
    const char[] iconOnScreen, const char[] iconOffScreen, const char[] caption,
    const char[] activatorCaption, int r, int g, int b,
    float iconOffset, float range, int flags, const char[] binding,
    bool allowNoDrawTarget, bool noOffscreen, bool forceCaption,
    bool localPlayerOnly, const char[] startSound, int targetPos)
{
    Event event = CreateEvent("instructor_server_hint_create", true);
    event.SetString("hint_name",                name);
    event.SetString("hint_replace_key",         replaceKey);
    event.SetInt(   "hint_target",              target);
    event.SetInt(   "hint_activator_userid",    activatorUserId);
    event.SetInt(   "hint_timeout",             timeout);
    event.SetString("hint_icon_onscreen",       iconOnScreen);
    event.SetString("hint_icon_offscreen",      iconOffScreen);
    event.SetString("hint_caption",             caption);
    event.SetString("hint_activator_caption",   activatorCaption);

    char color[12];
    FormatEx(color, sizeof(color), "%d,%d,%d", r, g, b);
    event.SetString("hint_color",               color);

    event.SetFloat( "hint_icon_offset",         iconOffset);
    event.SetFloat( "hint_range",               range);
    event.SetInt(   "hint_flags",               flags);
    event.SetString("hint_binding",             binding);
    event.SetBool(  "hint_allow_nodraw_target", allowNoDrawTarget);
    event.SetBool(  "hint_nooffscreen",         noOffscreen);
    event.SetBool(  "hint_forcecaption",        forceCaption);
    event.SetBool(  "hint_local_player_only",   localPlayerOnly);
    event.SetString("hint_start_sound",         startSound);
    event.SetInt("hint_target_pos",             targetPos);
    event.FireToClient(client);
    event.Cancel();
}

stock void RemoveInstructorHint(int client, const char[] name)
{
    Event event = CreateEvent("instructor_server_hint_stop", true);
    event.SetString("hint_name", name);
    event.FireToClient(client);
    event.Cancel();
}
