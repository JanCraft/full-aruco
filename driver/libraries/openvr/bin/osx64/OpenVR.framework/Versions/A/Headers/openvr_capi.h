//======= Copyright (c) Valve Corporation, All rights reserved. ===============
//
// Purpose: Header for flatted SteamAPI. Use this for binding to other languages.
// This file is auto-generated, do not edit it.
//
//=============================================================================

#ifndef __OPENVR_API_FLAT_H__
#define __OPENVR_API_FLAT_H__
#if defined( _WIN32 ) || defined( __clang__ )
#pragma once
#endif

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

#if defined( _WIN32 )
#define OPENVR_FNTABLE_CALLTYPE __stdcall
#else
#define OPENVR_FNTABLE_CALLTYPE 
#endif

// OPENVR API export macro
#if defined( _WIN32 ) && !defined( _X360 )
	#if defined( OPENVR_API_EXPORTS )
	#define S_API EXTERN_C __declspec( dllexport )
	#elif defined( OPENVR_API_NODLL )
	#define S_API EXTERN_C
	#else
	#define S_API extern "C" __declspec( dllimport ) 
	#endif // OPENVR_API_EXPORTS
#elif defined( __GNUC__ )
	#if defined( OPENVR_API_EXPORTS )
	#define S_API EXTERN_C __attribute__ ((visibility("default")))
	#else
	#define S_API EXTERN_C
	#endif // OPENVR_API_EXPORTS
#else // !WIN32
	#if defined( OPENVR_API_EXPORTS )
	#define S_API EXTERN_C
	#else
	#define S_API EXTERN_C
	#endif // OPENVR_API_EXPORTS
#endif

#include <stdint.h>

#if defined( __WIN32 )
typedef char bool;
#else
#include <stdbool.h>
#endif

typedef uint64_t PropertyContainerHandle_t;
typedef uint32_t PropertyTypeTag_t;
typedef uint64_t VRActionHandle_t;
typedef uint64_t VRActionSetHandle_t;
typedef uint64_t VRInputOriginHandle_t;


// OpenVR Constants

static const unsigned int k_nDriverNone = 4294967295;
static const unsigned int k_unMaxDriverDebugResponseSize = 32768;
static const unsigned int k_unTrackedDeviceIndex_Hmd = 0;
static const unsigned int k_unMaxTrackedDeviceCount = 16;
static const unsigned int k_unTrackedDeviceIndexOther = 4294967294;
static const unsigned int k_unTrackedDeviceIndexInvalid = 4294967295;
static const unsigned long k_ulInvalidPropertyContainer = 0;
static const unsigned int k_unInvalidPropertyTag = 0;
static const unsigned int k_unFloatPropertyTag = 1;
static const unsigned int k_unInt32PropertyTag = 2;
static const unsigned int k_unUint64PropertyTag = 3;
static const unsigned int k_unBoolPropertyTag = 4;
static const unsigned int k_unStringPropertyTag = 5;
static const unsigned int k_unHmdMatrix34PropertyTag = 20;
static const unsigned int k_unHmdMatrix44PropertyTag = 21;
static const unsigned int k_unHmdVector3PropertyTag = 22;
static const unsigned int k_unHmdVector4PropertyTag = 23;
static const unsigned int k_unHiddenAreaPropertyTag = 30;
static const unsigned int k_unOpenVRInternalReserved_Start = 1000;
static const unsigned int k_unOpenVRInternalReserved_End = 10000;
static const unsigned int k_unMaxPropertyStringSize = 32768;
static const unsigned int k_unControllerStateAxisCount = 5;
static const unsigned long k_ulOverlayHandleInvalid = 0;
static const unsigned int k_unScreenshotHandleInvalid = 0;
static const char * IVRSystem_Version = "IVRSystem_017";
static const char * IVRExtendedDisplay_Version = "IVRExtendedDisplay_001";
static const char * IVRTrackedCamera_Version = "IVRTrackedCamera_003";
static const unsigned int k_unMaxApplicationKeyLength = 128;
static const char * k_pch_MimeType_HomeApp = "vr/home";
static const char * k_pch_MimeType_GameTheater = "vr/game_theater";
static const char * IVRApplications_Version = "IVRApplications_006";
static const char * IVRChaperone_Version = "IVRChaperone_003";
static const char * IVRChaperoneSetup_Version = "IVRChaperoneSetup_005";
static const char * IVRCompositor_Version = "IVRCompositor_021";
static const unsigned int k_unVROverlayMaxKeyLength = 128;
static const unsigned int k_unVROverlayMaxNameLength = 128;
static const unsigned int k_unMaxOverlayCount = 64;
static const unsigned int k_unMaxOverlayIntersectionMaskPrimitivesCount = 32;
static const char * IVROverlay_Version = "IVROverlay_016";
static const char * k_pch_Controller_Component_GDC2015 = "gdc2015";
static const char * k_pch_Controller_Component_Base = "base";
static const char * k_pch_Controller_Component_Tip = "tip";
static const char * k_pch_Controller_Component_HandGrip = "handgrip";
static const char * k_pch_Controller_Component_Status = "status";
static const char * IVRRenderModels_Version = "IVRRenderModels_005";
static const unsigned int k_unNotificationTextMaxSize = 256;
static const char * IVRNotifications_Version = "IVRNotifications_002";
static const unsigned int k_unMaxSettingsKeyLength = 128;
static const char * IVRSettings_Version = "IVRSettings_002";
static const char * k_pch_SteamVR_Section = "steamvr";
static const char * k_pch_SteamVR_RequireHmd_String = "requireHmd";
static const char * k_pch_SteamVR_ForcedDriverKey_String = "forcedDriver";
static const char * k_pch_SteamVR_ForcedHmdKey_String = "forcedHmd";
static const char * k_pch_SteamVR_DisplayDebug_Bool = "displayDebug";
static const char * k_pch_SteamVR_DebugProcessPipe_String = "debugProcessPipe";
static const char * k_pch_SteamVR_DisplayDebugX_Int32 = "displayDebugX";
static const char * k_pch_SteamVR_DisplayDebugY_Int32 = "displayDebugY";
static const char * k_pch_SteamVR_SendSystemButtonToAllApps_Bool = "sendSystemButtonToAllApps";
static const char * k_pch_SteamVR_LogLevel_Int32 = "loglevel";
static const char * k_pch_SteamVR_IPD_Float = "ipd";
static const char * k_pch_SteamVR_Background_String = "background";
static const char * k_pch_SteamVR_BackgroundUseDomeProjection_Bool = "backgroundUseDomeProjection";
static const char * k_pch_SteamVR_BackgroundCameraHeight_Float = "backgroundCameraHeight";
static const char * k_pch_SteamVR_BackgroundDomeRadius_Float = "backgroundDomeRadius";
static const char * k_pch_SteamVR_GridColor_String = "gridColor";
static const char * k_pch_SteamVR_PlayAreaColor_String = "playAreaColor";
static const char * k_pch_SteamVR_ShowStage_Bool = "showStage";
static const char * k_pch_SteamVR_ActivateMultipleDrivers_Bool = "activateMultipleDrivers";
static const char * k_pch_SteamVR_DirectMode_Bool = "directMode";
static const char * k_pch_SteamVR_DirectModeEdidVid_Int32 = "directModeEdidVid";
static const char * k_pch_SteamVR_DirectModeEdidPid_Int32 = "directModeEdidPid";
static const char * k_pch_SteamVR_UsingSpeakers_Bool = "usingSpeakers";
static const char * k_pch_SteamVR_SpeakersForwardYawOffsetDegrees_Float = "speakersForwardYawOffsetDegrees";
static const char * k_pch_SteamVR_BaseStationPowerManagement_Bool = "basestationPowerManagement";
static const char * k_pch_SteamVR_NeverKillProcesses_Bool = "neverKillProcesses";
static const char * k_pch_SteamVR_SupersampleScale_Float = "supersampleScale";
static const char * k_pch_SteamVR_AllowAsyncReprojection_Bool = "allowAsyncReprojection";
static const char * k_pch_SteamVR_AllowReprojection_Bool = "allowInterleavedReprojection";
static const char * k_pch_SteamVR_ForceReprojection_Bool = "forceReprojection";
static const char * k_pch_SteamVR_ForceFadeOnBadTracking_Bool = "forceFadeOnBadTracking";
static const char * k_pch_SteamVR_DefaultMirrorView_Int32 = "defaultMirrorView";
static const char * k_pch_SteamVR_ShowMirrorView_Bool = "showMirrorView";
static const char * k_pch_SteamVR_MirrorViewGeometry_String = "mirrorViewGeometry";
static const char * k_pch_SteamVR_StartMonitorFromAppLaunch = "startMonitorFromAppLaunch";
static const char * k_pch_SteamVR_StartCompositorFromAppLaunch_Bool = "startCompositorFromAppLaunch";
static const char * k_pch_SteamVR_StartDashboardFromAppLaunch_Bool = "startDashboardFromAppLaunch";
static const char * k_pch_SteamVR_StartOverlayAppsFromDashboard_Bool = "startOverlayAppsFromDashboard";
static const char * k_pch_SteamVR_EnableHomeApp = "enableHomeApp";
static const char * k_pch_SteamVR_CycleBackgroundImageTimeSec_Int32 = "CycleBackgroundImageTimeSec";
static const char * k_pch_SteamVR_RetailDemo_Bool = "retailDemo";
static const char * k_pch_SteamVR_IpdOffset_Float = "ipdOffset";
static const char * k_pch_SteamVR_AllowSupersampleFiltering_Bool = "allowSupersampleRIFF�> WEBPVP8X
      ? �  ANIM   ����  ANMF�        ? �  }  VP8 �  �q �*@� >�@�J���"%�;��	e��t'p���4϶�I�3�y�;v�gE��%~��:p��춂���~�����|��o�?���ލ{��'������+����?h��{�~����#����?�{ �%���G����W���4=��;����G�?�?��{Uz������g�����0��+��&;}yk��֙��e��պ�zH�[Ω����p��3+��ew����O�c�x���尼�S��)���o�>���l������� .�W��/����+�vBֶ͔v5�G��l�ed����4z����[���J2�D��j�'s�x
|d��,Щ����'�s��Li�E��sWfV_�:�4|�jt���p��gHx���_�^��f��׬h��Jb���Zrܫ���/�Ok!%Kqܲ����l�שΥg�H��z0v;P]g�{[����>�c���_�=3�`)gƎ p�!�C�����rYo�NJ]�d>⢞rzZ['�X|��#���N�b��檑@�+��g�W��H� ^��{/�n�
i /f�y���N�i���G�?�TQ)LcF�M���C�y�e���	>���A#Xt[\�9,��٢0i�Ϸo��d>�b�)qO|̯w1�"V��>^�GNt��|��F}E��̝�)"h�=���t����vt��l��T@��Ҡ��ȫ����>U�+�@�KW���bW�h�B,��w���/ �2Ǫ���L���/�>4��yq���=��IC�>�nu���� �$�6�����ağP52v��	�m�Ì�#a	�F�t��+��s�|��)7fl��R�־��'$ِE�QVMuC'�5��3�������n�:�m[F<���&lz�$���ea���[36�/� ���J�t
_f�`�ݻ���D�=�B���Pgx`���V���k�soڢ��DR�T��V�5���kR�\*�A�x�hv�#�=��:�.o�&]K�	�ܷ����ά�]*pl[�Y#8�v"w6Lc�Y�*�}F^Dn�
���s�*���}y�~
�`nC��-�,H�r�VR/�c<y�I4Ė �+��ɃZ��1`�\�.�A�?����P��Q��%�7GT�7����6:� �ϴ|zX`k�A[�&��c ��NY�qw�p�_�Նp���˄ʗ�)�K5�!_�{z�b�Oؾ�;�OF�<f�f��Cr�	�����d�U'��CTp֦��iUR1ʳ�]�n�M��zPhH}�x� Z�x��S`yB�
��J)s�	��=�r����B����"���]�����oz��lR�.���W���q��F������i�V�5�Rգ�"\�"�<����q"��G7�~�͋�����M$�,e�w���D����&��?W\2��-�ED���@�^�T�6;k]���
�6D�1�I5�:?s0���(���%��	�$����K�\�t�I�7�tb+�.�m_����9�ېe�����P�JEn�a	���Fq�~�I�-NY����v�H�U�! "��bh�O`d���j�K0 T�M|^T%m��]��w'S�׹�`��]����w�ͤ�]�̙�y���I�<��5H"�y/ ����a��,/��F��:��z�5>��� ��F���u�KM��*� GHR�,�ZgT�J-!p��Wf�ș���,ć!�!W�)�x�zud��"�ʐ��&_��f�h'`Q
@���HU��P���b|e%$��8�Gu5^��%{w�RͰ�c���dZ����U}�ޓ��)� FpuqH����m�.��rB�j����iWE|��l�3<��wq��3�xg% �igr�!g"��WU�1tE&m-���`_�oE���t��Ut�n�Do��S���B�zG�*dy�} <�0�i�}#�ȅ�<�Hj��Z�Q��Ǩ�U����$SKs���!J//�Bn߫�B���D��|
�و]�栞͝C��1'���
n��*z`�4�lp�M{�w���Ѱ�[���7Y��������A.�b�$��#��Vx?x	�b��T��i2*��UEO�W�K��)� q�+Z1#��a^u��:���7��Y�҃=�J0��+R�� ~�o�@�:�g�]�m�7/�`O;�E�iN�����h�!d�N=6�Yǲ��xr� 0�������[�W�m��ml3,�u�6�n���}[���{��vm���yu�v�6��K݀�
��L3+��9��L�=&���I���5�Ǖb�������Z�����z�ʼ9�<)C�JFhCs��{:[����g5��W	Q� ?���d�1PB!xjV��/�PA��6V!�H�v.�[���rCY��1 ���6�R&��W��<�\<o^D�v\G��0!�C��x�PYAQ��XsXkUC/�K����y";��\^&�Y�{����&���߄A�����z��'#t��$�エ��no�� �z'�`�ՐɄ��+�tx�$	O��(_*���enݒ{��pS�p�*���X�/&/~�j�ɖl%��Ot�b��T�MP+��bN_&=���Š��j����	3�xQ��/'��ݕ�R��d���q�!���p5�R��,P�QY��;�_F����f�� ]���`�<N@�%�#L!�#{޹^�/ٖ���q��|��?��ݠx��IwoCE;�W\��Eh��w��+k��[�z�X�P���������M��H}�1$ H���T��h�W��p/�*�q���^4�u�ZO��������Q���|M�.e�\���)�r�d��n;����N��)Kv�Fz�M='w�=��m����Ih(�<����8N�L�:�5�H`�ޑ���K_��q6�VD��s&�6Kc�͒��9#��T���.������,aKoN0�'|�7uL�a��3���*�%Hӹ�b��l�۩���1�^U��#�`���RW�#�DCu��_i��n��Y�$�j�W��]� �Ab6�]�1tj�h�`���ȫ�]0o��$�\�G(v{mjP�q�@��!��6�L75E�;5��!{�f���\��y���=�z�9�B; ^~������_�M�P�tm��}6��>(]ї!��2x�0� �o��GدZ��/����mscƬ�����lL�B���W�Y�	�����//问V��|���ߙ�*��R�|`�;\l���ci��AZ�w�D~���@�
!M#�O�@͇w��u��oI�ɍ�#��3~�9��3�q�" �s�x��'}�R�na���u�a>۱��(�����^������XkQ�A@Z�6�v��[�'��#$,��(Pk5�U��V��	$����?��d��R��i��i//�jxi,y����?m2�8֙��
�"\�/JX˂������r��}$I�5����}B��I�?B�%��\Hq`�E-��PG��,�dݑ�n���P�c�}Q՛� teO�L���l����O��pb"������h�DX�]p�0Ǔ;y	��������"y�d��۷�{��Z���λQ޺`-N'��;��C<��r҉O�WdoY�t�}/p��BH8�*d����eY��~'���^ ���ԋ"�ؿ��@FR���Y9��ؚEZ�E%�4N�ݝ�"m���MF�*U:+���5�ʷ���Nb���P}��Ҏ/	���0�|/�Xh��E���ر�������aV�~[�F���孌�6���8�	�jb�o�u����]�_1~Ų�P���	����4%x�h9:�Ά>^�#�j�;dH4�X��B��ީ0:xĉ#+�QM��]�+���z�'m��ڳ�����mPcD�5�;u���8�#`�X������1W*��D�ώ����Z�㻳2�$C�Q�����)ڝj��[�L�:A`+G5�0�|%�\�yfy�pi� ����eւ�� Lf����&�ƥrN�!!�]�0�N:���2�c�ߣ�����#����L��T�e
�-^l�a����敻��/P�k)��ڵ�_mRe�C�ƊO�ʰ�+�L�e��}s%�:D��S�:�C��H�Z�P3�[xEm��A:��%�)p�r7ˡ�������!�3:��}�r�a�WhlĚYשAa�P?u��Y<��p�^�x��������[e��$� �M�������0�K7��h��0�3dbga��MY'*g%�P�%#Q�)����g��$��H�zI���mOڌ��+�3R6q�72d��>?X����v�J������2�+o�Ԡ%ѿִe�(1����٫p. X~:�.�q�ս��Vr�1������F����Oe���d�p��l��|w���o����_4��-��$c�4.W�߮�	O� ���n��F�OI�8��ZJ�����3bO�q��E�s8�T�v�/����J8�&�(aK��P�`�.d�-���f|&�w8_�0˟���A���C�yI����t{�|+���M'OY\
+��c�ԡ�~�x�Y���6yƮ�Zd��~h��jG��KE7�#�A�"�$%n7-������ԭ�V���O�j�v��[Լ���H�w\Ыh�x�6Z���ͽ���\��%-��d�}��/G��tϽ�փ�&5��Ϫ����r�%��Oe��p���dr?�gd�MXq٤v�_H�g�A�M�0��"+�;!EݵŬ�દ|q�����)
Kj�U�/eh��4߹�#*[�w�G�P�#^X�&�^�F(2gh��?^&E!��h���g|�<6Sڣ��ٱ�Yi]��KJ�ȝ���ÇT���Ʒ} w�GWftY*�`�gR>D/k�
��l�c8,���:�E�o��#�%�����"bҺ��?���]�p̈����D�/��@Z��r ,�tYĘ\U���i�[��HI�Y�)��QZ%���亳��������/�5n��b�˝CzgD?}����S�>9p��\0�g!��R�kz@5v�4��{��{Kn�OL�ޱ����N�m�����樌�b|���0f�H��)���8E����+%�F"�A�bApݦ0�,�������5%[x�	N���0R�gۜQ��p79K�Z;Ц����~;�z����d�/�;��Ь���G��#c�q��Zs��V���-y�i�Ac�I���~7o����Շ�i�<��zMe��n�b7�'���I;6�����<<i"��k�Vs��њ��X#���l,Q�)k)�~�è��� 8�t��T��>�2ӭ2ʀ����؈v&����7�/��}�A�'����Ϣ������~^$���NO9��$��2�H]��:E��$[w[	95���,+A^q����#���*�!|sE����DEԁ�. '��DN�c'6h���}bf+�]c~�6s;�^�T֎��ǯ�$��e%�[��`<_�)H��֦��Ͷj���)[����� �L�����L��Cq��'dЖ�}2�|��Έ�c���}�7���7E�xM����Z��j��7�����@�I�47m��9ڒo�E��#��ƒ�Z�	�Y�8�v�>r�Ѕ���Š��ϧ��� 7?��mq�A�X�T�4�ǹ"���6@RGR��K\X�x�_Nf��Ý�w���ɼ�y���1��w�`�|��W�>q�c]�}J(u��+�:���g�K��eEv��E\�!L���/X-�tνh���>Pǘ�M�Z{d�]��`��=i��-��Z�S�kD����98���3ɨU31�S=���4�&	_�]Gڱ2��a��A L�#�A��_��sb���7s���{���>���L������۽�0�L̯B��*�pzn`B�e'D%>^�~�r�Ol?��L��^c!�_)+9���]��%t��ZXD�!�p���1��-�P�aK5#{pϣ��^]�+a�r&��!QvRe	�"�G������p����(E	�S���2�� ���~CӰ�KX�]c�o:�+��`�j�U�t�q-@>'���������X5���ݨ�
��Tp��6��/�O�Y�FFt2��R|��[� v�IR��(�"E�v�*:|b#��M�PB#���w K�EƧ��`�={.�UWf�^3�J����9�R��Q��z߇�%4��ُ�ckLp�P�x�+�'E�
nLޢ6mʒ��&�`4��-���������gP��z��gl
]�x�(Y���]K�2/�rw��n`"S=3�]��jg�ȯ��F�� ���x�Hn�a\�*Jv�"�f�F��T���DۦJ�@��ݣɥ��e'GZ�˹ �Դ�oݟ~�Zr����~��'z��A*'�ri&���Zh����g�039^+��H��d'7��B��U���ʜ��0n�&����V��YF�w�v���}L���!��;q��������Z:a���+@�5~;�!��+��Q�s\�1��n)�H	���l�};z����a��|/J��K~uŪ8쩖�; A?#pgZw��Zڛ�wn�0Jv���དྷ�́�ѵ=�Y��������T��F_T���βdc��
q�q�;<1���>Z�x���3ڿ��W�G~J2z�WHp���m��<�}P��Ly���v�����d���Ǝ,]�52�7�He�<0���n�y�փ��zc��Kn00�H���oyu}oA�q�dpy{�|��|g��� ջ��F�2o���(�̙?�
���Ю��ׁ�1�����N!��vs�@�v����?����&�*�>�r�<z��ۡ�`΂E�5=@�hxP��-���V���R�]� �pվ�8x�p3l���}�ln��۔%jI��	��0/9rX[JG�s>*����
�Y�S�_��6�����>}�D�,q�!�V�}-�Q{x�*r��Ȑ`a�&�.��
�J�w�m��1�����u��{��`��nB-��[�
5��֐@|�$T��a ���>�s(-�jׅp�u�Hm�l�Ȋ��w~+�/�R�߶��8(�e0>"5��F$��/�`t�S�9;�E��q� w�:I��!+���)c��� �%�ߣ���/M�T��Dvy�����dG�ޫU��=��Ā�Ӱ;"@��E�����ǈ�=�CN��i@q��t�C�i5�x���L��*c@�~����0�T�l	}�q.��[���-2�oF�=���1�I%h�(�/�u��8=��E��W��{0U@�bNI��LBlw�J��pQ���O&0�^���
?�������}_̢��Ɨ��m0�VSX�j2RYr��)[�F����໒�?A&t�[��ީ-^W����3��RǬf�q�6גL{��2�])��`le"���kq~g�F1���(^B,JI���jYIV�,a����	Vj?�M/��n����Ӏ    ANMF�        ? �  }  VP8 l  �[ �*@� >�D�KAM�� �p=��DG�2F�^u9}���:[�k��s?���������Sj���� �_������|���F��� ,���+�/�!?g�g�������>�_���)�����o�_����/�������/�o���?���g��a�R��?���hû�x�Q�}g����:9��.�q��}�?��Hz�z��	��Mg?�{G%EZ��Xq.D��ڮ�0�Ѳ�؞�YD�ns1��.��?�¯>��kYKl��]$4�V��q���>�T��t0����4�[�Zp�(@^Ep�s�Wn��O��2��.u�b�*f��7�WG��#7؊��ˬ��t��&��$e�Օ=���r`:�h$UK�I��p82��"S]�=�>o��5?=��=X#�+^�l�����K5o͓��_�p��?���c��5?�	��z�E<��Й�$$G�ͫg�fK�e��-=���/̽�/�BJ����i����E�����/�IM&)h� U66Bb��LPZ1�K��"AO�uxo��h�zY>?1�9Ѷ�]p����D�ޞ:�~��,������9킻�T�|��2��������#q�t~_����?ɼ���E�r-�A)���p�;��A��=���sy�>��`&j��̞@LIN��$���ؿU'͟�k��S�a�n(��HM��.�}/u�W���X`{n�B�  ��x�����ԓ���1��*�c�f��9��F��,T�@| x����F�U�Գ֙���³�܌r�iq���s��=r9��	���u�=�I��z6<=�����r�D5�XTm!�r��ʬ���\}�87�� Ε�.��J����T�B�� ���)��X�L��	r�
`�_љ��Lp I�[ \���WZ�`y�h��D��
��u�P������}���o����d�8��G��T��9�I��)_�R�{̨RoL%;_��ʽT��� �<c|C���B\f���Ż������L�/�Z��i�}�� ;�`�E��)y�jn��S1�)"�r�#�|f�K5~�|���䫙�'+~C�EF����vRy���P�V	u);�{�q�Y�*P��;h?� �Y~�AC��er����c��	��R��eI�r�\���u��R�� U|By��_N�uX˂�^ʘ���j��#-�Z�Ђ��h5P�a�& �N�⦃�<|��R�dVpW���@��^;Ɓ)N�oe�}����g��»�9X�2�T�d iʾ�C,,��)oOSq�EK�	�>qC�����<�|���0�T��wͨ�Iԫ�aYc�ڼ#*���?Ȩ�:y:m�"��M|{��X�պi��X�6[�Ȇs�E0�|�|Y���
�<�h���6S�(qb�$p���g����r��C~��'��l��S�X���$�u�j�1�\k��@{P���g�=���Γka��J$ �o������G�;� ���&f�U%[���h5e�2JEy6�-(�[�&6�µi�e<�ʉ�ߜ9�P�&?Pu����,Z=��&7Q��V�g���b��� ʘ��_�w���)nX�K�Z@}����C��0o��Q�������M@vVM0W�C^���g�_y�����H3Ϙ@Oy���F�|�"2V�$������r�R���^�IQ���Z5�R�-����SF�Y�����e�mI=�g��
���=Y7$~1Vz\tӂՃ����]MJ���ݍ�c=ܱ�~�����j�%�*9�*y^	��j� ��Ҧ	u��s �܇�ߔP-_D=sx��Ĺ�9��0됷21�4�?G��+��32L�߄;�G��.G	���/��N`ds}�� ��Z�R�y�mVj��Kw��=YG�^B�]J�t ��r�I�����'���@0�����&uW4D�t�l3)ڕ�yP�\�Fu*q��7dZ�ޱ�4Wւ���`q�� �����P������1<78�3�ݔbd�dE,�Ԇ �p�̧9���ֹ�P��1\�煮C��f�I_a��@y8�m����ӂ��Q��#�5oL��3Tǽ7���P��g��yvS:�ax �u��2]jpn��IwC�t�b�b>�!�o��4�B�h�̟fRlT(�9똱k�|&?|��}݄�K�u�����p�c�q��&w�@%�j!�I�Zl]���)p� +_Ua~:|u�[:z�-)#B���4aZ��m�z�.O<��z�81�j��ߩ���jj��k
;z�gvP�^�?�$�+�0�fH!�y���>wzKR�f���������G�
��n�}=�Ȥ5�	���`	�2��o�z֐���!�������Plψw���F� �P^%�����S�����q�h�a{a��KX�@���ɡ�wR	�I�����Vɰ*�5�t7Kê*�i�ɶ<ٔK�Q:��ؒ9]�l�p���17-D�Ɵ�Ǯ;���;��*pߡ�V,�Ȟ+��uc2���7�϶�a\�9�a�P���Z�x��F��h��Ǜ�wO����]ԛ�u�f�!f妛�<��!�6/�?��z���P�>��0�{;FP��)���V�c���4_�]��W���P��l�����CD�6�
��-G�Xhi���0$�A��(�k?�/g��%��v�Y���m�����p=R�F��4�3^��2���ڏ�4����Z���$S�ͶI�>�yu)��H|WL�Z�蝐�A0�f�}���h~��-��x*�ZH�v���1�ɨ���ŗm:��O˯�2Bď����g0�8_ov��c�h�o)���" |T��=�C>�R�)�G����s7<�MJ��6p�kEb�9�D5@0ܱ:M��'�0x)B *�:� <l��'��k����[���]5®C!���-֗feg;�����&����0���G�Et<���B!���lӑz�Àrq
�{�C:�|،��C�8�F5��<�J��JS-<�"d(jvN��bWy��Gq�&r��h����S�@�2F�戞t��%�����"MUirҔe��ǵs#�{���0�6�ܒ}�S p��F��^P�����`�~ݩ��h #l]SG�E�J�,gwL��
��'��	D�� ��[��r9�򍰤/��x�<��Ҋ[���6�k�������xu��	v�e_�@�D��w˾&�c����j4ޗ\����t�� �Ӱ��2ķ�y���#�~���I�&�)�Mvk�Y������c�c�3+��x�cQ���,WJ����2�� ��wQ�M����uI�f��ҎMn�Lf�#�n'�}�o��{�!-��S4�E{��x�(	�<��WY2j��(���_Bix��i9��k{ќ�&��~�	�$|/4����C:52'��T#iy�z��}�1:����qg���?�`� �՘c�I'�B"[�Z�Y�}��Z��m�[�Q�g�h4JC�S�	C���ӊ���n��+��9i�D�_�ֽ��i�R�9��_;Q�X�D��~��ۨk�].��]�����-�¯J"��o$����ґ^"F�?g�)������@�tt��1�K|2mSu�P7R�&���o�=Gv�ADqn�P��^��\3]��y%R�'ǐ�rMg�l,���z��̥�U���TO*/5��r ��[���Á*I#1��?%W����`�$�0v�u�@8X�~��S��aܢ�tn��v���Ϟp9xű{J^	�hTP�=�����ҽl�x��4k�*�0�j��=5�wgɘ
~�;}(��DI�ZOc١��pn.zjH��{X�+����)Z}�W��;Q3��X�Qcޣ	����o꿿��Z���A���2��Ÿ���%>�៩��å��|�iKs�~�x��X.����Zr�iV�	7?+��yQ> 'ͫM�;�>� �zz�"�ՒXQkb���V�E(frd���,���!Ea�ӍE�E��>���4�S2N�t�x`��jl�0�e��S}� ���':��愐����_��ۋ��� 7c6e�R���ҫ$Xn��%�v��`X����,�il��d��nk@ʌ�R�&f7+Wah��Iݝ���-æ��i��M�����k~�*~
�I��z�b�r'g��I�7�WVGL3�`��6���x,��e�L���ro��c�p�a�Ԗ��.�h;k�akѼ|!SuZ���HE\�R�)N}�\�����Vu�\�?��C���a[�%/o%h� t R�}�l{���}�6�F��~�~.p�a�����zqb���<��ȝ�^����h�s��+�H��t�q53I~�&��h�>����Y�8O�ʺ% Z��Ip՞�"f͢���xm��o��@<N,<���p���vM����6����6Q[�� ������8�j�y�D��&YF_�����P��n.�;j"�+x���!���{Z��ꨥF�'?b�7��+}$�b���ܱC���o6�ٍ�7�.T�6Ð��:7?/���2?Su��rdQ�JW11�f��_���E�`8؎
��[��\�����2K��a�ь�;�q�P����Ac=�' =��7�-�������� E�8X؀��e���E���,~	�g�����ϲ���^ڃpKfps����O�c�A��xVY�� �wI��ϓ-$'p����]
pW�+��w��&�yK鱮�:���O�u�τX^�(9�Y�*spq�^�A���1��v I�pX��.���ݚS�:�%���裏>{h@J���ΐ!����s����hPW��L:7���t�w�� �SQ�Q���=���ٶ�x�Ls5�,�j�B�x�ͪ�8ۚ`���,?�ǿ�W��[���5 .�9���0.zbF@�3g�mp��d�������S����e׎>�@�'��_�m�1�zEeޡ�H�����>�g��~a&�%m,H��?\�:f�@���ܙ�j�b�&a����Q]���@��˖�2�ޗ�/W�0a`�$s�oXp�])N��0#�%�'��J|I���J��OF�kF��]Yə��Κ�NRv>D_�q��G[�����[�xӳ�Γ���j6��
:o��K;���c��<� I�}�	�m{Nc�"�����s-�ᭊ�,�̣ٝ	U��/��V �ǍXͮ �������:V�1����u]��@���<kL�.������]|;��&�]zo�r�rm����|�VD�+�,x� p̗��xiؐ]Kd�H��vE�Ѷ�]�2}�M�ۼ�$&Ia�Op;*}
V*8*p�$�ʪ�pQ2�,����c��R'}Sy�,�ϓ)�����,
�er��)�E���-����C���`�mDd�e�/:t1�=/2�u'y6�s��vYHVa�����u扑
����,�� %4zT��tZ�D�:_ր<13 U���%�$�|7��i�Ӽ��[�z�s,(�����|t;�eV�'("×_�Aw�tUAz���8#�y�o�����o��e�[1?������h��e�ǥ �{P�y!A إ�_�c�ʶc��$��tA<H����I��S��2H��s��=��7�GH��Wg���<7RgU�t�_�EhӀ/��1�Hr��[��o��\��SF�8v?a��1�acC1�d~��/������)���k}x*���QƢg�4)�$���wɉJ?$@p�yS�N���+���aSa_ʁm�S�b<x`�kխ�J6)��XL_���Jr���M�f΍;ʾi��E�g5X[�����h�_ԙ<���D��?�Ӧe+�^������@ŉ@�ϳ������I����n  ANMF:        ? �  }  VP8 "  �z �*@� >�B�J�_n�  �V�S��L�l����ٛNB9�g�~~��<���W����i���~��]��h~��K�?��_��������?��}��������_�� ?ʿ�����;���'�/�_�t}�}3���/�G�o������������؟���YRɝp۳�Z��	�QS�&L�k��.��bP&m�3|6ݍ�*��L�K�
2w����)QE>������/�)W�;�QH���Zw�+�gP�r�@����� ���R2�j0ag�������{��Z�=y��`�m_�5���Gt��z0	�6��r�_�ӟq�����l��8��d�-�$"�/���m+ ;u��F�TB��`4�*��I@ �>a�uѕ�Wz>k���� ,�>\���\��!=<�=������v��-�*Uq�q�%d����z� L�+��4?j����JQ���8���`O=LÖ<�@�>��j8�M.�I��0]���2����ލ�Տ�[���"����q�:#|�p)&����F�eS^�����Puch�~B*�Z��pݩ[�r�`2����7L\ݔ��%�Ʌ5+�.8>�A�]A�$3$`���X���a�
S��CY�L��mP4(A�b��0´�5o�i�Z����>�f�e-t����M�IB�����j��W�b�̈���@4�/�
hHI�Cu���1�iQ���n|����c�w3�/�>Z�O����g��-��o/粒Si�������y5*��R�;��_�u�[�O:����t���Zr��~|G�ncz�Y�z�^�V���3(T�j�(`����ΔĴ���t�)�]�.�ޚ��F7���*��zU,��AV��� �2�����Ȟ��R'�]a��G�! ��Y�|'�?59��W���c��֘�Hv�2�����s'���b��W5�j1Tp���7e�oU��2V�*/�)�]��ݣE�N}U,<�p��1�>  ����Y����K�W2\�T�`��� ����'�>�^��4�;�m<؊�މ��h������5)��q'T��IEа�lE��o\��"��2^/�}o�l'�V�R�ʆ~Y֋�!��W�3�>D�\%-m��'ް4��`��ǒ�j!�\��a�����zA���&�����\ֲ�n�T�ǡ,9s|�z�*t���D1U�7�jz#�wן�8�ӂC�^	Ir�Q,�o�)s+{��E̔Ș1<��q��+�,U�rઠ�'�OD~'� �c���_X��������&����?$SQ��L��jZ_�뢉�t��ZрS�>�->�E�b`.,�p���h'['����j�����F����'�ݰ�J��8o���F�����PV�@W�h��������tAg�fQ����Nf�%��B=y�*wˁ�?�=���b�!|��!Ԓo�pDj��F[�2tۀ�X^&<�+�zvz��}ˬL\���5׬�q>�k�Y����LI��k|��GA,�q��v.YD���9����	�:��������e�>�y�E��<�H��Q�<�_=d���O���P�m��
�V�~�z&V�L���xa�y* Bw�#.1��yz2��"���k�ߨwCD��,��"�D��	2�+sU�Z���@���b����X���Y���Ϸ��?����(D}�dZ��0'�U��jyjv����e�S�66�k2�#Uԭ���ޏ'c�ƳUs���n\���G�V��h�U���5�֍�6���H�!y6o��dq��+�E�F\���P�����E��ݗ���bcQؖiU��A�#�(�ड़���o
N.��-���G"ؙ�#�6��������9s�+`��:X��&Ѯrb+�wזI�F����v_�?|��3�<[h����а�{�MXg+k�|n�p����gR1D0�qf��'ų;��h������Ϳ�{J����1��Y���c7��i��ha��J�DY����_�"�]ȉю�O�xګ	ȃM
p��Xe�_;{ԗ�6'H1��Ud+�m��s�HǸ���|]h��D>b�N�zz1ӊ	�������l'<d<�奢�6�e�(
-��J�L��}a�����a�G�p�D�6�����
1g{���e5;�I�m�����N�gYr��P;�"q1E�dR�������Tv���@l�<���:C $�_U��JY%,�qR�����FfZ����7紲�	��hz���]�\��궏�Etf��p����"� $��Вҏ���^�|�7�IY_��yR����t�����GU k��P+PRk	'Gf%�H��{�N���|�.o[�]ƹ��)��T%�ۣi��&��ܣ�i��#�����	�:���#Q�rٶ/ʵ�X�o%q=6�f�HNP��i�u�KF�H�����aD����u����Vޫ+y�{���M CX��Y	�ݵus�2�}�;%�E�U�mve+��6�kn�t�:�V�0}hǡ�jy>A��o��1 &lj1���{.Y����z��1�#�a�vf��>�k�Ǒ�]2�-l�]Es���o�Pt��0��w�/R�pփ9��?���Qޑ�HM�R��������_	ڈV��t�Y4I�iy�.u��=�̾)p�$��aS�����_�mp[�RűE\nS�)/�c4��(�-1�o&B����e�<�S�*�rp
��B�l�@��-����WVZ7��x����t��W� �Cَ��u�w�����=�><�5D�n���6YEMM
9�xHHh�ٶ�㊅�d�"�!�q�l���ߙb��nsQ}��|������E���I�*�Wo�h��_N��'�nJ~<qhM��Vئ�]QlΥ��׹�3�d!��!�t��Y.��o�L�C%�o��y��O���l��9�h��ٔ� ��Y	�Ғ`kg�����h�_b��+�FX�?�:M�z�.��t����4d�f��^�3�К��˂6�=D���J{����.W7�'D����p������L������t���@Q��kAء����F>`=��nya�����h�:�	w�42܊_:�h�2R�#�7�-1c���˿!��|��[��I�v��P��UV;"�m%
	w�U�L)?�5��yoPG@�/��`��TPw�$M���îy�K��N�y�`��f�rK �U�����O��g=�qѥ�+J�c5x25�S�K�:]F�r�ϛ�ɺ)i�Ƴ	�!�X<�����C����0�����G��Jg�
S�#M�M�J���P\�FñA���ES?�ڇ�`o�~�e��py3��>v����52f'�zB�.�;�+Nz�T�^`�3�7��Q�f���&ֈ�S\)&�CQ����J�i�<�'� �9�uѐ%���x�>;wp��Gf���{0 �@El�%������x
��D1�Y�w�2�%C�ĉAm�p�p�f7Q�}�X^��8*J#�� �\����pZV%v�o�Ǎp�~���������K���͑�0ʕZ�!���6��������K{C�a2���^ ��M���{�����z�!����>���U�y�A6|Y<�����H�i���˞�=�u�����!m�3��� "v]��gy���`Ĉ�&q�7��1�'��gNV�ȓ�_!�◺q0î���EW��w!>o,)a���o���
�&��_�]�V��4��"X�#*3��3�c�[�d�0���~���n.�
vn�#�	�,B�(ǯgȆ�J�e'�~�$й~q�k�djR���� <��E$6�K�,���)vz��k�%��N W#Ƴ���d��`cɅ�8Rb��^]7�*�E%�Ia5�*������'��?
ی�t�l5b�`���u���e<i�Ғ���~*�$��i�*����R�tN`���f\Y�j��>�O��S�l�{'+�i5�PT�W�(F9���T�0���\Ԛ>�36H�� �O�_�\n�dT�м�6<ڣ�9М繼\� �;cx�s<z����`l2�W�8U'VŻҚ�&����O�����`"�Ǩ�_��Ky�i�)��@�|_� t3҇�7�(A(Cs�q��"�nwO�;���7�:�O!�[����%��;���z��ȴ�e�S���m]Zap�Y�0�mNA�̝8c@Y�K�
TJ_\u ��N�k$F9����\<�>�п�O�2�Q���뛭t�0�Ŗf1W��a���]|@�,�� �=d4�"�����
�|م��&�˭�=���y}�!���,�j�[	ф��H���=2�������q�#��{��"�,&]QQ����#)V;Nog�Ͻ���7�@��tfɅ3���>]�,��g�>L���U��$`��w���,�ف7w�B���CB�̄s��r�O�~G�,k���!�ᙿ6_��I��VN�Ib� ��\ԉ�v��o��[�������tg��+	�ʀ��ī5��96�\�XR��]3��s�,��U	���"@�@�R���z�?f3��F-�PjG+q,*��D�>�]�s`j�m_�[�� fA�^��9Φ���0���i�5؆�o'i�G�XiSux����#����vg�A/����I4r�xӗ���K��#7���͢ /-J`D��@ܝ`ڬ����ƣk�l�x������,+�߮�+�&w�T���+萲��DQS��N�IF�����[ñ���-�A2�U��P��amg'`��y4_��]������lp�v�e���Q��7��̀c����c׍7�s� .�%ŭ���4�!p4 �����j�z����m������q�V����?�-��A�PQ>�Ìk�"�F��'�v.q�w�xK�y���d����n�y� қ?y�ȳQ��d�����+u�↨l����^����p|z߯�;��	B&TDϾ�	g5.�=�]��=R^����;ib�u��G�I'��BMK�H�RW�X������&N�>��7���PڑmB�/���,�A�U�L��`�t�Ts�(���)���? @��#8H�Pg/BM�4���>�+�Fq�5t�f�\��.H��ٜE��b��V?u��9��t��[��?pY�zM�]�nWخg����8� ����բÍ���Ɇ�9��8���9�|�\�3��Է������ϘB�iZ0���!7���ĭ�p}��Pק��,���g�$��i_�M�	g��ɢ��/V���N@�:�N:�줈�KtH�3����|���ɘ�B=ֿ��(M�g]�T�����>���[��lI�_s��e��,e��{�CZi��ڲc��?;(��V�r��^�Oh�a�J��(�{�b�+�L˙�=_v��s�N��o�O�b?����u ]�W�bZs?�%�|��Τ.|���q0�O� ,�A�]z�A��y�u�Az������)�����՛��3���1\�K��8ݱJ�NeU���:���W~!���ăg��$9�d��w� ��'Oe�Z��O�]���>�P�����NΏ�;K��Ќ�Pax��]2��W�e�Y�n�>N�;(��5(����֐���naJJ���F�}Ȟ�U�V�V$v~���	���g�g�L[j,����F?+�W�ŕD�:ssF�̷����a�<!���0�5��*��cNG�m�M���jm�n�d�����h����l�:���x��5���(�pd��z���xđy>}!B��l.�H�>����d�Q���E�_�u-�uA�7g���L�����=!g[*�)��RwbA��5��}�nZ�F]��S��2m�����տB2`p�������o�gh-��3�=�������;m���\`tK��a����k��"�P���O��o�+�vv�=�}�lr_b�]�7��7\��@V<ӿ:��x����M�s�+�w"9�{4����ԯ�l3��E��"*xÒ��W�P���_D%M1$cS9�"�0.���XnI��,�����뱰{��!p}���|�*�/�%[���p����"ΐ�w�/s�T���y�:̜V�s�O�/�;�W�� �����������4d*@%�[�\x�ٙ!&�M�b�mC��r�Lɼ�x{�n|�|)A�a Ӑ�2�����Z�p�ga�I�'c�0w�+��K]����r��W�+{��X)n�^F�ߓ̎Іu�N}���L��j��Y�t}�;gW��������%��%4���S�������/��zS���Y�|�u�!�7��\��/���ܤس��^�##(��o������
r����ѕ5���;����?9_6���3�u����9(��߻5X~!�.S��?@T\+<���A7�6�Jլ�ڏ��;)����b���/��}]��x����J��Y�;�8��r�8HΦ� ����Gא��U�)����*|�X��> ��r�=�޲t�T�ҙ󐧢�r��N&�ڝ�>n����dî��W=,x����;����\������'��&t~Oa㉤[��goc��<�{ �Wo��D��o*�s�z�V��� I~Ȣ�m�6!� Bn����y�P����	�����_���K�S�����_n�5@%-Y�%��AG0�,��X�D5@�5	c%Hά��;Ȅ@@���	迯n��UF�es���#C��[�T���{�.���!�QJ�O0a���h�'М��B?Ɵ�C��&>a"���s�|ڳ�c��� y�S,�8\�F��e���Y@� K~�#Yjh%��k��]P��:._v�9 ���4��T�' I���� ʒ�<�x��2x�ވ���qjFο���J�ƶ]n�U��'�![C^��r�ڻ������ߐ
����O���c��.92G�&q�ƈx�4���t�#Οl�D���!f�N�Iu�H=M������p�|����ӝ�bO2�ъ�,ut��b�G�Й��s9"N�UK��/�O����}.�N��@u1�V(<�K���`#WYDTI�Bw�������ԗ�2���y�S��Ὸs��q�x:�2��:[��{#�	�|�C���Ǌ���ͺ������jd��h���xN|�Z�ڴ���$Q�^v!�e�j�cP�l/&9��J�6ncn���A��bj��hV�;����c�����e�ng��:P�늯�����c������3�s�d��WS`lH=�hb��O���9�ŇJ�C�#���u���I�`�\�=~��o_K3�����A:!P��"���E�n��P�=`Q˕���")^ޓY��L�<$`��P��Z��ؿ �p�x_����*��+9�����!�3ċ(�/�I�����ם4~#��{�|��	��8��S|��VqB���Ϧ�s��%#)3�[��9����>��1"L�7���̭��/�M�+�9��BH�2���<�M ����di��Sp��(��8^.��7}ȴ�h?Q�~#�G�� ��$�H=�;*����r��[&��*M<0�X 86Y��,��9dew/���b�,#�Yҟ��2����{#g��{ >s�3� ��-5���Np��>�[ŋW��t^k��}�Q�7?��͒��L{Ե:���<��O�έ	0��@�X�=�y�R�/^�@����|]F�M�S6f�����7�A]-�D��~��T�<����O�w�>�����v�q����!J���4Yw���%�?�/W����k�7�Oy%Wu���%�N1B[�m���N�BsgSj��v�i`��  <&��W,lh#��z��2a�O|��owqp@�3���b��U4�BC*��H��    ANMF        ? �  }  VP8 �  w �*@� >�@�J_��� �6�D�H�)�2����Ѩhq=Pn0�vӕގ���W��`�S��<^��[�w�?��i���߁)�������
p�������$>-�����?f��?��S�e�G��կ,���������������?����;����o�?�?����+���7�G�g�Om߶����[��O���Q+���x�aa�	���	H��9"9^�^�{����Go�����qg��A����eo7��~�����gÈdO��{�0� ?���c���F�q��ʷ
j�װ�aOZ�A�\�}��N�3l���ljm�����^D!܉H���>j���m�����y/���͋�����Uԣ�[M}e��Mk,�}��[T�۞�T`'9�����G��l�A� 3͢��:X=�vu�h��Z�k����Z*.6��m�Bh�jr:��sA�8���,�*%b��>A�:��Զd	,���#,U�����dsݷg�)UQ��S���#<~o�^����:�+��QC�>#@Lζa�@������J2Bf ����p���+�;��u�RF������.yTl�����,��,L�Lz��&��*u%��'�dK4��xXM=�~�<�ҫ�]��O�7o>5(�eLv��d5,S��V}�}����e�����������5��Ư����A'�}��b���UE�	���v��:"��̵���	0�S�/j/�[��xm[�Fj��RJ�±+
N�J�ӥr��K-�V�l_6�K�s�LЭo��Ʉ_�RI{֖D�������DJ#��i���Lc9�20��P����ٺ�����.Ð�h-
+�sGmۈp�Ν�d�2�E�9y��y�հQ}zl^��'���a�5�ǫW�G�z1��$
bD��qdZ�n��񖌭%Mf-�N�  ��UV���Ӑ�I��/� ���X=�6g@R����0�"������kir `����=)�_�HJ���P�-\/�ͼ0Z>HXre��l���r��|[!��G��,F�\�Z�S�zD���N�b�ҿȖ�?$�P}������cMdmp� �Xi�h+m<Eٯ$���	��7�:���/Њ�0�Z2�1%�J|;�Y�l�qQ�<l��|� ��6{�L��Q���at�(�����f�H�����������W���~��#�&!����y�O�����	��u���x@���e�����i��ւ����59\�ܝ�~B�n��
�X���r��1_?�!��.ک��z��ę�v������.3M&��n@6�>ͽ���sY������s��-R�L�@7�L9v+�W]P�W�b�骫����\%Ã�&0b\S�]c�{Jҋ�|��<"5ӭ �O�����.A�CDڴæn��Xl����M���*�,d����Q��q�!��~��/T��� ���b��X%6��a��� &�zm��e��>�1_<o@�t�;;^��.�j�\c��O�����w�y���$�>{^���Z�esV+�AQ$廒�{�0L�ɸ��|T����'��.�*i�CAU�����;�'���MB��U��9X 	�e�V�?��a�p�OR#%�2 L�`GAI R��v�9��>er��!���R�mU@<�i`�uK��tA�Pgj�.��+�L��Y��a�9w4n��=xs��
�⃠����̈́a�ԫ�B�~�i�%�1 5]��/
.S�!�A�u�Bة����=	'c߈�&�dvdroɿ
C4O�W����"&�
�*�W��J1'[Bs�l�N�_W������W�%��Ę��.4o��$����� i&��-� �,� ���ջ�0jl���:�����Xt����'���d�m�lNBQo�3T��Xo@��x����
�,����⧄�#��>�#��ǳO�p��=�^�˕��mJ��q2I�iV)P�ej�B��/g;!o�e�Z^�m�VHs9~4ֺ.������8��/KP��I��q��Ǎʚ��!]���!��.���K�V���A�_N�k�?Li����\�*"��r���-��7��ҷ���<�=V�l�� ��0cM��IѦ��x�7P�/ϓ[�Áu{���r'�������~L��t[8���aZ��	��\?��´n���fcN��pl- մ���uo��T\-��2�.�	���7aSL��%ֻ��	�~W��΅,�v�0���i���U"�c�6sYJ���KuSm�Y��w�����z���!�_�����)������4i2wm
G�~�&�^jJ�d�ܖ�t�x-<�����"��q�,v@͖��2"t�!�m��9���'�(ڊ�$�L JN��45�G҉�6��ǣ�yh����nG��s+ʄg�ZMq+�6�\�2�>L���k���<�p	.��NNjO�ִ��̾,��g�͂�!�i1�&�� }�&��/�y��S&תF3����4y���ۆȪ��e�k����<F��M�B�h�� �+ZRZ3��|�4<:\�<:I��%��]��v����k�yZ�[���8��#�9�^}�a�8n��o��rҕ�K.�@�Q�:������qP&W�Kz�.���5U3��%@Q\��TqVз�u
'4�����.ZP`ЂC;/@��3cݖ~`1gD�2ad�{"9h���`��S-�?�<�J���k�c�x]�^C+f�/!.P3��h��w�2$��Z���C德��j�%�\��F��y��uy�Nv�?���~�a����6�w��ݒr�:.F4[ē��"Es5hB��Fa[,���r�v/���W�s+��&rfJ��_�N��&m\�2�0P���wf��t��v�Զ��Z_�T�jW�«.����~�P3�t��K-n�-�F���x%Ù���O2�N��/J֋�s�(,'�G�3�1n�$���㼶�{c���x�hMM<��mYz�
 �nYL3����%�jDh`'�bE��e��*S4#)���,d��,=����3�n�C��&�wO
n"�������?W����B�P�(W�U��<`���$�3%���������X�e�*��a�D�Z��)l}�J�[,&������I�ʾFSja�$#g;��F� �ǫ�ՓdnK��t� ������,��+�s��&�Ʀ��?���l�*U_4���N���m��b�>ch����2�۹������8Xl�j}1v�-�Z��I#��X98��f���a���į��%�u-��y0^������S(\����b��L�|𥊵�ꐧ~�\'l����I���� m�3��ݣ�?`��8���'�������洹�1���1^Jܖ�R��^��i/�?�iVۘg����y�+*��CF�RJ�M�J쾝B�gn��)�]�:s�
݄ʷ�1b+�[�;��:�7�V�72%	o�A��R�����6�bM�-y�Y{����}��o��Wݪ�4|@�o��Z^�l>0�A�^�7��)��
a�+k^�aR��k��+��Nn�{O����E�i�R�5��o����d&�_�S�q�<�T�0��3�ţ�,�<g�	����ᑗ����!���@�Rʼ`�{�O� �
�%R�|�E�Ã��w������v^o<ٻ�5Nf|�]g�O�Ȱ�*��˥\ҊU3�3�4�	�3{XM�������/��X��t?��EGsgc��E�˖�c��XL�MQ�:�C�t[|��͛O)����Z
�#��a`�o��^RP��^��P��g���60��4cK��lX�ZJ��L^h��k
��ǲI&j�$�I��s���㪺=/�X�S���H:F�?Ỡ� ����ƈ�|��e#f�'`m���3ѝ/]��
�dMl�ȇ�,L��"���/	au�i����;�K��2���#�fM��3�K1g�K�g�$�j,�Ĉ�3���ps�z���eYp�>Z8;-�Hgԅo<����:I�t�+��t� d5��8��z�;X#Hޔ\�jc�FB��L}]�rZ�1����̬��fa��ӡ��EW��r��*O9��m�*o�tHXO�z]������aSE��`����!����z6�ݎ̤��5-��w��33��A�M�i�j���j��$j��E7AH���
Bdo�C������s��OF*/1���a�]s�oz_#��ly�T4�܂8�ď�:�ȁ�\���s:��>�u��y:\�&�&U?���E8�Q�7� �8P�$д:�����Qh�ދAQ�８]����	tv����T��M�Ә�2g�A�^�T(���_��˲\���Yi��B�f*S�o��>�s�k�N*��e�]M��LUg�\֜ i!RJ�Cʡ�Ln�T�RF ��G��xn��7z��W;�SHLDZ�݀4+k��i]��9��\�I����!��[�h�_ߟ��*�lny'-�ӏ�#�[����,�_[�UL�,sJq�O�R�iL2i�S�J�%%R�[Ě�>��T@�'����i�K���#uP*5��<c9����(+r?�M�i��X�C�y� ��DU3��׼O�S���<�[�A�G�(���Z����V� dc�>[�v��'����ý)I��n�U�Z�Ċ�)� ���~�[Tms6 �O1X�,/26�[;���HJF�s}3�9��A!�5S�[
����k���7oK�qg[�j!o�ͅ���)��������t ��$��k"!�s�;��/��q���#�ф �Y���C��!fq�Dڼ����z����ڛ�a��R�-��RϏ��i�+pwk5���6V
J���	����-f�D�0�Ҵ�a�f�� i�O��)�5�ؿ��A��uV��;N��vّ���=o�w�{?̿$X�+q稭���6�v���I��+��cC�8������{�D³�����G�E!��p��]1����uW�P'�+�Q4��?�����hHN��H��*�����!���[��RxD8(4)yF:��G�x��B�ِ�b�����	Zr���ɨSKU��AR�#���%0��v� ���?s)�Ӽ��_�E?������2���=���E�ѮS�τ;�����~%���O�%$����}6�;�Ne��}�`�%P�q؞��`���mth���gW��z{Tw��o�
�$��w��'0�8d{�.s�	N���F`�N,d���=<�+���h�aL���o������!�.�Ļ�k�4�x��x��3(;����m�%��.>��Z J�EI��2ͨ���>P���'�����"͎R���P��Sm�jLe}�a(�G=))��5�Za^
�+����Tk��ӱ��}Y��UXZ�)ǉ�����TJ��s�da����Ԫ�g|>C�r�}�`~�p�|��Y6<6b�
���Nˇ'���i����"n$Ӈ� �L��ʼr�G>gq��.�63�qLu��*�i���yFIk	)-��U�oe�,|B�-��~Ho9,�G�=�ƍ�A�,'r��܃�q3����C�Zk���b��� G�gbh�� ��r ��N��=s��3��Xr�-Z/T�ʄ4׈~~���(^Q�Uo�Z�8XJ�Ep	CM�I�|�g3�?x�?z)(r��@Ǔ<��k"�rTu|�>=j.���9��N�ҙ�iϰi�7k㊟x v]��[���HJ2>�Ze�m�7�1���(=�F��۔a) ����ͦu���O�'�\p�h
�|�.A�����j�3�^�R
�h*ժ�Z���p��4�������#��(�_��f�G|_�����_��v8le���Z���qc�W<L!}���kw�B���rL�譮'�� R���A���h��୮�{�!�e��-����r�-�P�J/��,鞜��z�;��o�0�'�@�ηo��=�W�U~�	���	x!�+h��S*��K֠�~W����o�6M�?��A�����%��R�G��kĜ�N���	���$ncV�����`P�a����Ϩ�,y���P}�z���dP�(��$$>���`�W0Rݷ���!����歠��\����I�r\�gAI�=���Z�Sq�uĨQ����g�l�ϒ��~{���αbxa�ǷL���g�z�X\�T>����xrVz���͜�V;ܒ�����1�RWm7�s��_
�r3��v?��"�6�C�`	��g,�;�z��Pp��"���e�09�����N<��h3i,���d�9e�c�����/;�Y{�Z�`Oj�	��Mg�����F&Sɞm������zo:��_Q��[�<H}"gtrd��9�^��oO��e����B�L�w?�׭�'2�D�* ������-�գ�)�*��/l$��w'W�H*J�gtf���I0�  ���w/r%̚gB(�/�+�N�8D�W��;@�+|P��F8�=-I	�!7�i`;�>�˔w;K�αx6{~����k�|3�G��h���hSZ�X�n�c������b�8X7_P���D���+?�L��@"Ģ������ܾ���F��N����u8�Us4��SsU�O��=��������7�3��)v0�\J���=PZz�!��ո�kU_2�*Z�d{
1O;,D�8$�ûC=G�k�C��=�U�z�����L�T�A,�l�*��fKjD���;W���7T���(�?.�+#�:>�N����;�O�o,۟�����8;ap�nw����"�i���	��O�޸���wğ:�H��E��9j����."�G�Ӏ�I`�1�=ۯ*%kّ}1^�2�m��W�0o��8u
k�L;���w��	^��}L�$�v2eA�ړ����dtGyt��.�����{܂�zdvsf?9��;�Fg�1�RPcb�s^�C�b~��������o�3�?7���o_"}m�x
�|@��2�2z^i;.w��-spbvZ��зc��E��ƕf �y�O[����k��(f掏(�N|�;���Dʲ�eLj{�?����]X�QϷ�Vpa~�f��N����.F�U�\l���JK�"����x����ʸ�!P����YH�7"I4c��������\�Ԋ��9��`b����]AK�6���a�5��^Ar��m��(�Ө�i�joV���q��]�g��Mp��Q�a����1@��X�f�p,��P܍Gaȶ�fฯ�8?�M�Y��@��<�1D.���S6�Ϗ�e�DJ��MvaA������R�#T��dx�N{�f9���J<BnwS�K?��W^����� �ߘ���jl���\e21�"�1����;��+���vA*ӠFܥ7�\�v��$���[h��߉i�� I��yȿo�H�������ꇕ4�n׿�@<۸��?,��p�"���~���gɦgvp��,�gW�����;�g��Lƾ��h\��l��k?�	���n��`�*��4���FL؈�*@@�� �ɬ����,�7�2�����K,����E/�w�O�'gA      ANMF�!        ? �  }  VP8 �!  Tz �*@� >�B�Jc��  �P�:&���z��|��b��_ޣޝ�lA�^,���W�޷�5A�O��?u�1a�OˍA}o���;�Vs=B=�����/�?��?�o��p���>����o�w��`�������������jߡ�����w���������������]�Sܻ���'���=�
�[]����#0��u�[�:@����*bOq�������t�\�8���祌]�X!�Am����W�O>xI�	���ع]� ���|��*����W�����c��.b{�*k.`��f|K=�<abj�\���s���~-ū�}�t����U<��Q��9���C
b�p����EC��D?S�,95� ��.���?�ۑ6��:y�/���_��.����"��}���V$�bm�m��]��6@��y��Q�j��0�n�/��%?w��UĖ��e4��NB[�/����M�GT�76j����L���v40{4��8+�"UH�^05̬�΢u����)�|���}T3���U�w&3' ��}ھ�Z�]��՚񕭡�1��/��Edl�Q��>V�@6״�rG�P���A�ȉ�87�l*���7�R ��`H�E\������q����E
9	7��qx���:C��C���[�;v.9����z�2uٶW���B9��
Tgֳ�!L�m����hYk��nĭWv|�:.MԬ����,X��e�3L��[��"�	�1>d�����K)����L�vZ�A"��}_E�iB��ҽM��8qd���g� ���\�74O��~�K�&#m���bE?��2vb��?�0�aΔ��%|�K/m��w��Ů(˯hT�T�����$�gr\̬��!���0�yM��6�Y������lؘO�[�Ɨ��;8�4K�*�9q���r*&<T  ��G�K9k��a��)����=��<�q���2�,�������4���r�C��٣o#�2��s��ݾ��|5Ң����ݦ�?��;�����s-�E��N�8�jr�b6�V»
7Y�#��F[s��S^�#��L�z�f�8#�Ή����1���  ZP������m���]XGS�����V�qW���vfHǴ�������Z����"�0���]�F�c%��H�J�t��95����Q�ͨ��|� SN1�e�H7qZV9^L��	ʁu�0r��N���/*���R�Wb�Q�{�!7��*��oLh��������3�9$�"��ľxk�Nf!���=^��{�+T�w5��=������5�iJ�Xp_�T=�����-�
=}NC��/���ޏ�Q�����"���T��v�cMu���?V�f��J�q���67�jJB=8��Vӣ*{L3�:��9`q��|�踍�S��&�7aɡ�xH^��@�_��/?���.���nɺX��\�z�Ǵ�sܛ�2��jͦ��f�O�Vm�o��y�\�3a8�C�V�����B�a�TS䕔)�x���Z;��!�f����BTy�P�p�>/Z|�r��uWS�����cم�C�u�!���>o3�j�	�_h��N}�����6�h�<�CR�Lj�[D�����?2Ut�w�GvT���v Sa͠���^�45bR���Z7K@J�\xB:TT1Չ�8�Ag.������!>��;z�u�_y���3A�p��KO��f����ߥ2�	���_��2~��<߇�������Yލ�b��#Ӣ
/�{��u�Rm�{��^5p���>��;4���h����W�e� �����ǵR�ȓ������l���+���4$�����{�U��`����2��M����wf|�'�z4���ۡ���5�����p4��,*��m6�s)l�ؓ�����T��zum��Ў
0	Q�:��v�
E�0�X<��U>�M��KJ.3�E���ƖC�X�|Y�B��b�q���(k�	�M�GM���:�/���4�� �u�!��V��*���] b��1n�:�D��
������ v���`M��A��i_��0�4~�HmY!�J�7~�Vj��8�H1��[�JBm��o��� �t�m�uY��^�m!YTI�~�U��I��~k�A�s.����+��>�nl5Gm�Xy��ǁ����ҧq��E�xT_
�T�ōZ�֙�܂�Ʋ5�C�H���I4�ܨ�)�f�W ���AͶX�S�?-<||摰�+[��=�����N1z�D��*9������^��?:�		&1�O���<��<E�U	뤵
�t17Ub:c덝1�hAK/9>0���~��Z���߀V�c��5�`�׌�*�	
k���<�i7�6�	^*���ʄ:�H�]L��������\��A~���^"���`�T��WHV�k��!���|#ɩ�~��u�[�W�\�`���~�Ix<V���<;c9;Q.WA�"8�LܴHs�	ঀ���ȌsU��2�,,R��4��b���O�ǧ��6�6��y������X^������\�÷��+&�>h�ҚnV�� �D� ��³�]���ZH��ǃA���"T]s �鯍#%�	P�E�B6PՇ��ԝ�D�,E6��@oS���7�s�j�� ٽ|�~���e��Z�g}H>����V7	'��E۪�!S�.��A�O���Ε��:S����'h&��^�1��~�,`[��Z'ّnl
�HQ8�ɏ2y�V,��������j;TLj��>���܏�V�^� �$�cV=�͝�M�z�L���?�g�N�
�LV2�j$P�w���{\_	m��s-��T�'�f�(�o>�������&��Mj�~d#��L���+0��ä*�:���ڝ��jJ�һH�ˤrF�w�)�W��������?���`��5K:��^�%��Ma�ZP�;�[]I�e��b�Pp��	0��������*��w�Zi
��2���Ad���樃u�02��O��N�������?�5w-k��c��."�����
\T8$a������A��C��nX4��=��.�7~���-K����3����Iȭ�I?ԖӸ�5������*�-ԫ��+p������tq�٪��[x̘�/�(��7���˭Pr�S�O���(0FY���mq��m6�vc~36��'�#�Ɔ0 ��I���S"�a�y���3;,w��:��{���E�q�W���%�;�:�r���@��������0\%��qY@Y\�4%�hI�gQ�Pzii�`k/����*��x�6v�Ӿ���{��0��*��hM�ɀ�2�UKo<ZKiǗf�1�}�Wg���[��Yp���"�)�$]�_��x�Fw�p �˵��v�G�$��jӑ��9\���,�n�����%bF�ϠܷP"�o�+P �%���-G,���B\��K�U��惢�EA��.!�{n�(�g��VFA�h� �r�+v��P_���ए��$�e��6��w�\`�u�;7
Ѯ��}��K�� �I_�����I
 z8B4n%'�H-0)&�����瀤/Xz��H\����Fv���Z8D�1�w���Ȱ��KiԢ�K��5r4��?:�0��O��v=O�}�^�̧���Ӝ�(�Yz4y�I׷�DKy1�&���F�����J&$k#x0	o�@��&��M=�7��|�M�҂��/�e6��n?j�Av�pcp4�����+�{�3wI�L_�M&?�?xm�w+��y%�2���E�S���|8�S�Q`YgG`���Y��<�iij��/�7�?n>��Fbv�W ��IN<~}��@����n�Қ���:�(�B��F�硯x?u'?�k�'�G����d�gOK�?�^]��b��j_siRG_Q����Jc��U�����|K�2+��घ�2�|jwR��~Z��?CPcZ�?[�J�R�t�q�Lӂ��,�A�,��;�k�8��z�#��������9(�>�8(O�2���.$����H�#� ���S��s�7cO�/�J(=㼰Cd%
:�����8�-U k���\�#-r�+���)�����ۆ:�|l2�Ka�@�Y������W�w,�gX}���(��f�hM�NO�x��XOI�˂�LY]������X���鱺{��P������
3�^K�4�z��L�/����*��"u��}]�淞��&H�b�B��]Ӛ�gR$ ?}(�Cs �uW� �~(F.�$�'0.C��%�$4k�_0�j���޸��dQ����n��'�*^�ٙ~�+� �#�T�5v���0b��פ�H)�<���4�����H.z�6_�3{�࿾�*+�K�c 9|�?��%q!�7G|B�9C��r"�;@�΋mz}��Z��?&�*�Ą�^�����)QGڌ "l����4���c� �}��Ç-s{�K�6����f��c-�Y4`�*�T?�%���Sn��3�ʳL<�k���`����!�w����_����a65|�0U����Kv�0��S2J��FeL��`�w�Q���W���7�е ��3D�g%���V�;6�0�BA��l��4����:e^2�Ӥ��x��ef�]�EL��b�+�C��/Kf�,�煇�dJ�]E<�l곔Fs�����[��+��H6N�O����5���Mda��i���`S��č�ydԧ�������9���'�7�^zb��M)#�;�|"�b�.�%�]�Iޙ��L*��=$s��aG+�ټ�|�Kd�UpLO��![�;�F�c�!�\b跷�G
�SH�{鉊Ͷ�_#�\u}�@E*4%i�!H�����<�og�φ<*-H�ѳ����^�#�T�	�_[R��%�Z��h|����V���d�6�.,��{l������ʋ��l��P�	�qmCƤ@�]���}�ں�x�g	l-Ā�'(la����A��Lc֊������o&B��Pw�=��v�;��)�V�;�\�J�����k���p� s�J��a��3�9e����b1�/j5:��OXj�Nv
�z�_�/�۵ca�����$H����e8���g����͐ٰק�5��n�0R�:�13�i�J���hT�敽7��p�,i��;��z�}���\;��4�I�=}�m�5Oِ˜����Nx��\�ŻB�P����ŕ��Q����F�ڲ��1�%(fւ��5`���}S~�3E�:�U5�����`jCys�7��;��q���M�􏜕=�hm�E��17hTnvD2��`��4���G����Cr�a����b�Sd�ށ+k��+�~��̹�|�4�ϸ���P5C[G��(E�����fȞ��6T���+�e<�F�cU.l�V^.g�s� �-
8���=�R忳���}�4�9�Uc�h����a�����褀��{g,����f�V�[%k�=�7SX*3M�[�+���phn)f
�_P�֖��,|�� ����
�.�Y�W ���Bjq��+�����D��)��:���5�v#.��y�g��P�¨�[|'�}q�5���Q=���Tʝ(���I ��}P8Ԓ��<Y�\ ��g���5���,��.يq�5�[�C��J��5F�JF��H����"5�}�{J-��ui�u9;��G�>(����Y�/�vTc�"6���s�a�X�&4�`$�!���̯�I�l��|z�{��o�4!���?��l�9�w3��Ja�������r2��w�OTrV@A�V;/�>��s��r����=�N ��J/��Զ2S)�,-3���U�9d�hk*�@:�k8b�������&=�ga�Y ���</�jw�JE��cm���4���(R��.x1�6Y܀@���b�N�s��J���NL�1Wyw:���Y�6�ɕ&�S�P�=���d�0�@��3�`qvvP�A��zPz��c�u�)e��Û�8	�R�S�*������d^���h�*��+_�זּS�x�S�A]΁uC��1�eyuk�Zi�������r�)q�����P��LL^h*��Bph��?��ff���Xg�H���JeK�L�����}��g[Up��Õ-�3��\�.5�0���Z|�X��HO��.�*<[\�@�ќ��N��m͝@�0��?CL��"pq��sW"��X����rI�5HJ|��N��Ҳ�W�*�Y⳾�;wf���V&֋Bc�M`R}�Jqr�i�iǥ?A6�o� D��oD�\L�(���Y�iw�Q��J*���`!�=���1KE��PT��Gc(�ܪ�Ϸ>3��b�b�$�m���>X��ڵ'���a�\�(�dV ��z���]�I:��~� #�:����ފ�L�
+`�Ȉ��{q��\����J+sd#?������e4��hC_�.�}%y߿��k�Y28z:0=�Vߧ�:�57���1K�~��󴗽]���a�d���}-�xz�;A��K�tψ��9M��S�o�8�1�>����϶ph_�������մ�!R���=��b�?�6*����I$�釁���vN��(_��*�4�5��k3#�s�H{c����;4���#�Ë%6{��~��|��|�>�o�+`A�&������Cr�a�a,������RId��Af?�)�-
��9n=h�x�z����ʁ�-�Y��j*�ȅ���-�
�2"C�_�NаA&������ɥ)%np،����PiH�GMd�"ɄZ�L9.�p[֧?���� +p�m�eSs��-�dC��O`V�NӘn]���5!5�d6��=?�O_'1F =�픽L `r��~��*���F��a�܎��#E��2��0��c�S�gF}K��n�R�;��"Lբ��@�f�g�EQ	�<vK�,�pHS.���+xޓ�0k�-����VI�J6����y��1K�q�����bR��![��<�k�ξȰ5�b��+���_z}��G��kb�	��J!���-��?�R�^�hO'�7չ$	�� �rBV��� ]�a�"��F��p `X��ʟ�|j#���jpN�GzYg5���H�Ӻ�$�2Լ~�U U3�)�s>�]|���Y�cL�\7sq�!�v.����O����0n���7�Z?�C��rGO�g�����~\��(WV��sI��e}힘
���~� ��Qw� ��)t��j'N�]���y��'�8s��	'8�錗:^�P��S+�/	�S����ک���������w�R) �my�7`��Q]���@e��w�אtm嵮��o��g0������C����BHq�W��vil�-���"�`١I��F�Նï��S�`�5��:�'y�_��}o�.�u+o�^�q�uD���O8f���%�q✰��2�HG��]F'mE|k�pʂx�!I�'�F|�$g'D���;~֖2%�t�G��!G9�:܊�����ŏ�Ð�Kb5���G�Q�ta��Y�g_������4�4q�������.
������½o���#���Y���0W���=�u,N����ޟ�O�m���q�e�ﰊ�6��1'	�F��`96�M�"���b��7^��9�P4GN����s(X��-6nV�Ȧ.�"�F�<�4�B�]�'�l��jwE����g��+	��C��g��a�|�|L�Ɩ��Q�@6&~�F���7�	�W2(a���.6%�:]��*oX �aAHү 6Fvo��9E�T!ln'�&��,�f����k�_;������r�Q����=�=��}���g�ěWl�G�/~g��Z��D��"� |C `��:5K�ލ��#��2ęRSH8��>��G������b��Mϱ����d
��}7��~/�NV��p�9Ff�j�&��7`��%�Y A��֏�Z3�F�rX`2閅]�bj��!٤�C��Q�-��$��ل�����.MVl �|��ӽA��)d��6��S*�n�QC���*���^ٚn.� ���ݻ��-G����n���w���x6N�sk�v��pKP��LB�Y#��GK3��Ń�WpE���Klʦ�����徎�;�չ$bQ�.�t��G�U`���5>��O����5����\���P+����E\b�,���> �T �t��̀�S�dqzZd�Xd�bzSH`��t��O�[p
56C���߹�u�A�F�!��S�I�K��Q��9��QyA7��V��^'4*�͹E
��e@��_璏r��/0w�6K� �ON.�<Y�'�K�H/���*z��1������:m	�Ϻ���5��n����KDA��*�'��X@��,�� �ej�e��S�V�F��Zc����?�����X�Qlcf�Y����"�k����b���C&U�wg O����I���r���m�Qt�\�[ɔ$!��T�ǰT5��膀������}ë\슈�N=Xˠ�7p�����Y=�<*���S��M�=F���'�g	@  ANMF�        ? �  }  VP8 �  �n �*@� >�D�J�Mq�  �P��&8�I��MV����+�ݻ���~G��r���G���ۯ`�	�>�O���}��i�_ /�����]������7�ע����;�W�p��ֿ����?�����G�����_���?��������7�O���~�]������g���/bo�����݊E�vL�
)PA�ֻ�y�E��Yؘye���z�|�	��Npk���MX��}�-�$����S�eզv.��ƤGS���Ta���6�&����8p����?�ɛ$_��'��;l���I���Qu���ge��K��O�����mu�V�4*� ����H�Ga",��c�(�#@g��d�!8xM�4�l���KW��%�F�!��O�~(��^ �}�[p,
�ʼ޻�J[��/)���qݓ�<���U��  �%�[�y��gye�!���L۲:��읧�YAn�!�Qh���p��n�Y:a&�A*�%`�W���{�|�ؖ���_�~
h�N.�鋎@�8����J�' ��XjdP�O��ڵ��>���i��`�*H��(�0����%�����e�X�_�J�A/�E���H(��璙�FHǧٷDL��֎�5 Rⷵ�oM�A���|)���`��g�,�0�Q�������wY8Ȃ!�	K���C,��Ӽ��Д��Y��"�ڛ?�)qCy��"�p��� ݈
R���'3����H]H�lH�LT��{��+�Gܯ��_����.
�X�����w����d�H������f z�)
?�kB9ֽ[9)%� B�on��l�,U���Ͱ�#�d�y�cjc|�W�5��@�)u�D�2�  ��/�
�� =�/����>��w�[�hk);�*p�<���`������p��>�I����L'u�m,�`jU���e;�/376�D%y1�B�T6>�Ak�/|��_0�wm3$���NG��=N��Mx�ݘ�!��:��diP��U.n<))�S�M�$9O
�瞁ppe�%�x�ɖ�$Tv�^#��q"�s�<�H�@��B��&�S�H�a�#c����#�|s&�ǀ5������N���p���~A�m�4ȿva��h����O��;����I'�L\;б���:��q�(�U &��*͚!\q:C|d~��f���&�V�8�ߡmj���[�?q���X�5��������@(sr�Cj>���O�l;�J�r��.�O������ӍY��em2�yO֠ɂ�6����s��� �Rޡeyi3~SL/W�y��Aw��~{�tJ\��4+��4�s�T�8����܎�x�]v�RQ�5T�D�V+���z�kp��m��1�=m�ܛ7���V��X���Sl=���7��N������[�z�%M������L��-g��@�s	8C�`�p�Ѳ�Wz+���z��m�t���vN?��m�Nu�����p�X%�����^P��GAk�>.��X�)4?g"��~���S�Rȝ�}����5�K���:�D��D�ԄF��Ȁ2_�Z��b���O��>7�*XfWš��� J}3�/��O���M
�q���P��iT�;��QXu9��3�"�����d>&�Yr[젴�@xՎ'b
�����re�(���4�W�=F��,�֛��T�d34�Z�B5a��<3�{�R��7#~�(6Z�pHZ����MB�pX���tiq�R����tqׇA/���v�Ě��:9T��3��=p4&�{�1���m!�Dfl�єy>psd��r����������.��ꗼ:+f�BTb/�n�z0s�֔xM�Y�'�r���u��9��� �����JrȞE��HGw��5N�1'��9jgͺ��L��z͆�ې7<��C�.�������;#��_������#Wy:��v�2JC��O}��P��ܔ?����#��e��U&{���]:	�zk�?����54j�.�3��L�</�@�V��@��W��	)�ؔ����~6������u�]"OB�q&rR[�{�/K��-'4��B�cϳ�m{�u�[�c���2fC�����;6���S-C�8��1;���i�y�6�vj���Z�	Z�=?-����
�8˔�����-G��?Q}���'��ǴπDr9��x\�u@3�rz�8m���<��Xq�]��X�+O�J[���$�w�:�8��ML��>�I�����D Y��/��N�0�3:.�W� �m2�=?�l�P�#���;���o>PD�љ8���[���hA�	V�g�b+t���<\d2p��}��ZvjpVT`P�V��7<�}SD���y�=��bf��1�b�q~�3�o�l;-�ѾO0(��G��=�a�LI�S�p@+�{�Y]�1f�W*P(H �m1ڧ��]�ob2)��$��VC�z�^̤�K��P6[�N�p�[��D��̾���5���*	�%�⬍���mz��e����_~�^<��ǳ�Q�R�����"�1��%Z���}y�ϸ�P���𑬙�mq�]YOV��/��nY�l�
���k��PwK�,[_M\��gtG�2q���0M�����vf�.1U�7�B���r��EY�#���Q�5�a���(iu�2jD��_�-K�Y�h�������~��Z�� ���7���PZ�	�5��Vj�d�1��yg�;/�� E:��N����k��Ɯ��F�u�O��V6���4�E�O�^ ��QKOtg �V�e��HL��%c��Z�21؜y8,nc� Rv����[-(�rF�2�JA>�p=�6(3�j�n��$�%�r�Z ��e�z6=�-�<f������$��/�)�S8���hncӔ�ZA�X}�ݯ�Ur�d/����r	��Vy�'�I�%�ok�V�K��W�ϴ�U�9�i��˧�eR)��4�GBv��7̮ڠ4V��~mƿpxjy�N�ͅ�|2�5�up��q��\��c7���f��Q!���)U� ��.
���'�$��f���'�b����� �,����� ����m��3�Ľ5j��G�/��h�4�-_W�جnېJ/��=�|k`xf��``���T~/��WF5�yY(=��z��R D̵�we��B����΍8$�* v��ú�}(��ݯ�.�B����}4����/:#}5M��F���
�
!��X|�ŕ�f�%_�C��`=���;��R�d������l#�_��h��Ë_R�����T	^�b�"T1��c�.ۥ�
�]��H�u���>���n"3#`�i4��V��K؋�Ą77�`����/�����ڼI�w_���S�2P�OKy��z�6�@҈8��c�ZN�B�=��7����e��6��Y.��`�uj�i�m�A���0�\��?{V��(\�Z�����_<#����`xIt!�V}�Ƹ�.�Y�6e��:S-�-1۝�;��>�B�^;�
or����:��qLP��U�@Z:�l�&�{�,�����	$�L���1}�C"#�ī��-���zN��rt�%�k�y�)��Z�^��gLD�ڱl��`hE�����A�L�:��{�U�����A�4���u�A�$�ֈ����ϊZ��E3���z�§ϭ�r��LNF#��܎!~�ϗ��H���6H���O؆��?�G��d�p��j�:�C�ٱP�3,���='�bX����9Gu�毼n���Մa�/٪>};���V"��a���霏}W"kAˬϾ4���W�4Y��I��'�dc̢�bD�ۭB�hH�Pb��m3U��e�r���>e�ng� /2w7i�q(_�J�a�����D_gQ�(�㟱����\}_yх�Q�k: k�@y�b��X�T��	��i�K~�%�u���O�����mK};�}�R�6�P�txE��d�TC����!������,q���'�qg�v:#%l��a;]1
�O�L�~c�/޾�W�y(���]ތfLUAz})�C����L��|]��x8F׳�����x_u-uZd�����@E�m�D!TQ���I�'�^4N�P�"�"�Sz����	�LXY{w�H߳�S�ݡ�6.��� �\����;���
��ۮ���O�Rx�Au4��ԌZJoc"�y`[xq�:�8K�Q���=��h�PZ�"Y�7�G���-��jߧ�8�#����ގF��4k����J�ebi*�����u>2��Or��Tl#6��86�I�H]��$e��9a��>��j��qX�������~��P�a?�/w	D�-�Nni�B�衐2U�u���g
�Q�bF�Ca����ݗ�p�8o �l-	Uӗctm�Cb���ڱQ��;�h��xo�q�*ۉ�!��`��G����U�o���R���]�,,Z�������T{�q�VnIs*Y��7*׏�Y�Rt"W���gI��ى�&2@��	6$(��r�&��@���%�?����z�>o���?r�): +��·��T�"�-{�AhUz#'����+�	j�HJB4��ż���=���pJ�H�����"��+ �դ��U^���C��M��a�}�~ ��/�>���ǧ%8�k��>�	��������ւ�r*~kю��B��˾� ���3X�[�j#�K���\��зfbc黥���A
_b���5��72׶�T��Mm�����hk	�	2�"�߶$��>-��A���S��[ $����L~{
�斸�Eq�[�^%o�W�|�*�+qW��+�PO��\�]�H뵚h�!���)3�đa�߭�5gd�t�k��{���+|t�c�sM���Yڎ���4��n]X����˭zL�B��u݉�S �6��E|H�1���O�l��M���eez��D���D��G���|�Z��^���Gwb-�f�v��Є�Հ��H���������:-�S��'���D
H� ��Z\9�z�c�¿��ާ_���~� �tDi��zǊ�$�Ne^g�B?J�+��#E�Xm�M����%����Ƭ�e�Urլ�����3���<V�?l<�k����O�e<��G��8�Ҍ����i� _]=B�$���
�}Wy���K��飦X�{9�7����C�UpO��߷�H!���������ϋ�=+ڱ�����t�í����'tS����(:�!��C�Mދ�;�ŅH;��]|e�?b���"��YB��`��������=���ݸ�a�;�]����6'�5���,��G�\6��)0w��Ԗ�Y%��}&)�%���4L\�f��۸Xaʐߢ���w��U���^���W�u���3����~_��n�]/V��!�Rk(��/<"6C3JYN�;�b����B���������5w �P|���_�E�U�H�r�1�"K4����%�J5���Ȩ�4�;�ڪ�^�����s�HT��0��YM�q3d&8#%o!:�� D\3-m�ݵ�v��Ħ�D���i���b�p-	O_�SH�{i�<���b�)��4�N�z��S��u`J��\x��?����a�,���S�/����L�y��p��ZS��j+�A�y��@N�)���/?��7�W�
{z�U%#�&B�Z�;�<oZ��u�� H ���V�0[�%�}�hG����̔J��a�GV$��,�#/w�j���@ͩu���h�֩,a�L����HǬ��� ��m���M���`PiD9�Ħ�J��r�&��0�i���
���f���a8ʴi� Z{�J����{��ZgS��Q��f�򷢤�?C\[�3���[6���9'���@�	�gnEח5��'�v�_~�l��4e&��('�#$ľ0u��6Tf M�e�qx��j����}��r9�?Ϸo�ٝ*V�K��K�#r{2��h�2|��5�%��SbD{&+�a��#�>�R��b�	L"�7|�7�P�$(��U)~���y���
�\zx}�R� $�vd���J����:TBt�H��;�U��/���hA�/�4k���
ɯ�\]�>5���\y�3lߟ0^\̆*��iq>]�6�WJT/����%mM#�ߏ_��������Β�xU_a�xt0%?�t��D֤>�Ew��"�Н~h�>��/���}��ڞ�+ ��9��ǈ�KAc^�ʅ�w'�N������� T����)孑�E$&b���ϱ��M�5��1$w�G�?
�������ߞW8��{�sw6�e�ތ�/��>�Yl٦��(;��lX�вQ�ߧO�xf�)���
Ք�"�~a��j� ���`�2���g��.<��cvc1��i⠴�(���쵐
"~���M������ks��,ad波������%�}壓R_���.�o��e�8>�ѿ�$�G&�=r����#D1�S��0�E��r%�eG��?nhG��PF>�
Pok�X�Iq�$�*}��0���}ɑ7�%��v(�3:�B�.QN���L�Ⱥ�)
����3NB����+̆��E
����9�C�'��T��ѳDlU%9�:��Y�AԻ];Y�}�Y�Sia�)8CW���kY׹$�ݰJw(����g��¦��o�Pd&����.��zD���j`�F�<UP=q�x_�-FGA~v��	��m�ڇ4�r�E�$�[��I����K�.���?��x(s���.+*�W��	E�H0�`M>��ӵ�LjE4�wn��O�y�>��M��	�J�'�O�J�v�m��Q�#�� [�%^�s�µ�!��v��9��Ae����0�fk��اUޏj��n'�S��j��r^
�q��Ng�ƖULǬJ�D�o�<y<�Cќ��R�-��ؓˌ���c豁'G���z��Q��S^($N��	)���v!f�a���	и�Ws��aQ1�FZn�@V9�	�Ɠ����7wiq߃G��a
���N����#ۊ\��d+��1�7�:E/�#��#�F���u��r	�j.��SV��y�����t{�f�ES���V�Y���8�LCع_�lj����:�t�yf���We���bZ�&q�G h#�<��g���z�y(R�X�<�弚�`��xP����]�p�'�  ANMF6        ? �  }  VP8   �k �*@� >�@�J�e\�  �Pq��ZDEv���ǩ��|��r��7���/�O�K�{�1_��~��7�����_�?����ˍA(�{��ŗp%�����?��~H�I�G�?C���� �y�g����a�a����������ߔ�_���a�{�������_�����׮���~翮��P��������s�5M}�Q
�C����4V��M*wF>��nr;�?9G��(�����WH��^��V���^D��	o�5��v�{��z��Wq�L r�A�)�{���=�))J��V��A�q�0EuQ���?%��D�0N�ءu��H�&�8g�*�4��Ukr]�"l߇���O[���l�d��M�5tF�u:�Y�.[:ub$\l1��i5���a`�C�5Y~h-Ň��WW�*����t6�����n�Aw��XE;���Z̼ۨF��Yu�fG�H�,���>�k~�Mf*j�PXӜPX�(b��hie�Pθ�ѳ|�F�X�fI&P���Aْ�ڳ�>Wd��QÔ�����������x�F|w���K5����N<�4��\���yDH�T@�����ӋS.C}�7U���1���p��ĠĶjZ�[�s�z�d\U��:�~� ~[�0�xH�=;�
+W8���-l�Y�f%t���xa���,�Y3f��D����O������K~`BF�ֽ� }�X��'�Q�T��7�H�PQ���-�8��"�aOd,Rߪ{�u�����N�9Eۙ��+�����%���%��{[�S&.,�2��pi&�Ӊ�I�����$5�z%��ӻ�o�>Y��ER���%�YdP�sU�����FdĂ��)*��6V����K���)� ��x�Ky\md��ޟ`�UxQ+�?fSq�O5{�[a�o��q��O"I��@��4VWN G��dL�I+��܈�ǾTM=�����l_n�w`�zǧ#k��#w
U��ŉx���yIG�Xii~7bt$؍�|���~Q��P�]�7�}I�'I*f=z�!Oֹd�zу�Z�`y�^Uڷ|���NRW�vYm�N��m�Xj��|fV��K6���A�/E(gt��	�`�E��`>#�6�xFڱ��6+@3��2�K�A՛SW����ܹ�ԃ*���Pw�W%O���'x�<z�$�UъR�������q,�O�~'I胚���0�`6ݵ�Hq��(����X j�7fI���ua�9��@�g"�t�nŽe�/��4|�x�����xm{��&��%�kh9��Һ�1#P�v�O4��H`˩i�x?2Z�r�?��L�M�]�B�RP�<�)���>e��`}Ӏ��i�k<x�0�Qz*~��ޖ����c�|��'�Dm�'(���%#�p%j�N��
�h 7�@bZC��p�e}p�T[Y����68��Y�� �7���x��c��||9����]�� v�STa�I��l�~�$}�)�3X�9���\p!,ʋ�~�Đ/�sY��7��{T,O�nj�'L���)�.H(A�����SH����O"9Ad봸?��H�p$�$�ZR�IG_��z��̊s��sQڒ:�<[�@�{=2ZX�\��~uw���b�;ٵ��M[2�Nn�-U�(�L��l�>�O�0������l���h�X���ЪH3.@nW^��e��R�������м�LD��V�U��H�)�p7�M�{Xx�:���i�]���_��9��<U����r2�����Z.�%)����E��>aLϯ2z_��!�5��P���f&%)<�}�=B���!��ch�qp�>}܂��H/xg�<B�F6���{(��+g���Q������m�AG���Kj���L�E����!�é�ޅ ۻ��B^ T~I��3=��s��o@�Z���N��aw�ݬJ�|�a#ehC\��͢J��Z�Ʀl�aK�B�� ��V�3=��� VNw��'ӡ$�U�Z<T{�Z����ؑ�4��=���v���7����˴�)e�8��Gi�`3)G1p�����Ӎ5�s_���=�a�U�'?�o�5��ڕ�t�N�7.}~Q��Yߘ�g�i����� I|���{�k=��P$���A�zG��u%��G("їp?gf���@��f/E��"��/vy�}'�vh��4d-?�߰��9/F ^��Z�}j{`���eNtYj�BWmᢞ����]y��k6Sl(��g�v��`�gԭ
n��i��(�������i�����^?�J���b�\'�Fj�y���M�Gی��]�����9��k;B�8�о��oS���>�] !� r��[��[ռk��O1��ݬ\���ӌ�ق��
��l��V�R#�Eeu�0��c^�L���:�e��)wS�86����v܈����%[l�d��	@�0E���U�TYȞ���>M��9�.��Mr��Sٚ��F�Rv
W�J�?���qF�#�V ����ﱚ:����:�ӳ�b�N9Fo�(6�񞂾�^���r�K4�_�N��'�����*���a��Y��$��G�{њ�/-�s5M����ܼ�V�HAz�A�G`M�>�1w��f:~u�$�߹��>-o���
-�
�ݴ�BÛ�z����/jCNMؐ�[姏v�� �B))��^��-�q�Z%�u����S����,�(A*	�;��S���o���=�&�;ԣ�l�Q��熯Ԑ�q�V���_�q��׃
۾��|,?|Hy�k�'�3�ڼ���n�I2p���)Ľ�`���\��;<��Qx�m�)�}��c�|�˒rWk��m�=��8�
h���#�gO"�ܸ��PX����� �ӟo $C����p���L�~�~�����˻b�#�H\�F��xo��n���ߡeb�]Ł��@�7�B�;%y;�PQ`T��5'��KpRNQ�ʣ�,E�yé!�7!NU�}�6'�� K�q͵���`H���yKβ�n ����I[Iր�'g*��*=	�	�k#�3({p���5h�
)iY�����&��
Oʃ��4f��{K֍~����iF`NgO�8�m�EF�q����@�7�͹tT FQ>��FW���ї`P��r��/��!�n��*C���L柎'�|�2n]���K���B���wap�@.^��\�/!��x3�i(b����>&C�.{�P�uZ}(���<� 2l<^	=���F9������X��;����ە�:�!'���$��i�Ѿ����ʠ �3xR�p�+о��i$��H"g�v>)�Wj�X��	9c.��Z܀ +~P�%5�$*^���>E�cr�^�2?�:�w.l�b��@���R�~s�U�5����1UC��S�m\-/2��J�*ѧ3�S�5����A�E\���";��C��ₛW�A�=PO�P7�%�y	��}�@Z��0-��Z���#�GI��M������+�L����v��5�#Sw[I��=�/=|�I$LJ�N��Zۧ��+�t����F��J)zT5�v`���'�&#��Z���:8��s�~�������.=�T����ī!��Ak;�eA�;R�$ݶ��1���d��Iˇ����/r�G���z��ڂt�2w�9O@b�ܭ�����$�M�%�OI�3��q�����d���LnG�����i�p�����aQZ�D�e��؈x��;X��ll�	[N^r�M)
�d����,��C4���v%<�ZI��z˄��n�c%�-˵q��_1�8c�CH
����D�}]q�#~E������	M���w�|3�f��-�5e׀"�=n�2[m�H���#�th۪K�FTOD�,��s��;-}0k(��] ��}���˿%͍�Oͼ����YL^��/���ت�l%f�s����`�@�k/��Lz[����Z�88�\�R�F����k���1��%��1h�F�E����tR�ZQ��K�� i8��Ӓ�p*�r�������Sd��fgm�~��Ę��DYTj��|�� �븏��&�O�X���@�("��m�yW5%t����P3���u�R�d^[�$��|�E��:D<�A�Ya�.�Ot�z, ����|b����r���K���*=��U�&o����E �5���p�����Z˗Lt����wQ��'~���W�w������U�G� e�؞%�?���U���5�]%����F�^:�֢`��3�*Hj-��㢺kug�A�J䧥1	Sʅ�h֤�kg7��#:jw���)=�|mۯ�mY�!��T���H�I�����+Y�Rs$�Y���@��FϖYE�����:k�7��	������;u�ES8\�\���#`g �Y�3�{�$�[s��f�@4�Rᨣ��AX:���&��1	�?�	�v��v4i����<-S��t_��������n�HR�W��D|�=��A��!��!<��<�!�p���ެ��a�{�y
\*��Ų��J~�8��
tc�x&}�(0����(�a��y�?z�y�Z)�-�f�� �a��"j-zz�P��j^yt�*���x P��ٞCG7�<7���2����xmX����.��ɱ�_��ؤ���Ǎ��	��d^�	�?��]�ɔ��1H�����\��_�z �3:�����҄At���k�~:6�o���bP���,3�y��zBK�(�6�l���ҋ+9�S���7}6�3�,�Q;u�m�+�k�-��_#=����!����#K�v��e zW�p[�=�]~O�mBZ\J "��2��:=, Ҟ�MA� ķ�$�'��qwi0+�h�(S2�Zc���V�v����3�.OrrYy�U��U�8�$��`�&�p6r7���o�$W�5"�J�z\�Sp'�³Rjd
��SǪ{�yy��VT��pdR�C/�9�\�G(��31`�f?���{�tlF12?���e��A�S� �Aޔ�.3��,����<6�QK��3d�=V�x�3LNK�-&M��`R��_���������!fWyz�t4��[���*��vO$�AR3y�1��1cM������/��w&+�SP���tj�&l�يZ��14�E(�3pW�y���p�O����!�	H"�� >]�����&/�p���<����ɪ�C7(��<P�Z��p ���>��t�sp�_l�����[a:u.�7��w�X«�BW9'KI�j�Cc����0�ޡT��*��>.W�5Y6q�o?�-�|5:�I�DO�I�i�(F�ա:Զ�V,�ȫ�8`�B���-��TR��M�	]�4z�	����pKr�C��H��F�z̾���X�n��雁B賔A�4����� %�_�c��%���>������Ge���i̖Yk�����6k�Iܫ7�z*[� ��S!߹���H��M0��Z���O%_$��,�Q�������,(f����$��c����B|&r)$Nw	m7ibN�[�c�Sm\g�V7r�����ߒ�_1���,�*=�0��O��k&iU�Ypx¯|�����ኬ� ��,~�:A S��T��iߜ��ɔMv��p�E��"n��y�X�C0�*<��/���\Y�9�S��c�yg$���Xh�������ʏ%#'0q~C|K}̃2�b�b~�9��t��X�@�f��m�ɟ���;+�ׄ4�b�(,�Ϳ҆9���릿�gf�o��0k��8ud��n��L����V������k�Zn�ùk��#(ep�,MF�#LS�%�	�/[q���\�<6j^���	��XVk�'3�L�!
^����V�U@l����d�y���e�Kc��5���HqC��C��3�ɗ���v�ΩEr��6��V���"z��&u(�߰;.��@�")>�C|w%�W���	���(�Nt/�%x��0�$]���\"�ı`�^�jX�S�GS���E�].Ӊ�ʧ�����EG�6�3�<wc�]���/�́A�h��v�,�]�����l@���g��OIz
ܯl`�xظ.[�v�}3c#Q||W�ՆNc��K�O#��)l�+:"�fK��a���N�aܵ�����;͌~C�]�xA��Цإ��L����"���eX�������ˈoa���1̖���4U)�����g����+��\_��^��Q�z&0lQCt���}|@��4��R��-.�~ZA��5l|�t��4�������fy<�BQ�K7��)��jZ����yDyF�l8�e�z����]�^�a��6'��3���%��d8.0	�K��I�����,/U�lUJ�'���3��t��,�(<�Ƙ#a�V5e��N������z�t01ծK%��C����_��T��F�^�{!�
�R��N���8f�6DLu�+���)_Qs��1cYi,B��ޯ/���i�	�9&�\�y�������.}=���I���G��j�偞�w]�M�\BV��t������0�z;j\k��nW��\'Z#=fg�O��t�����b%��]Ǽ��q�#����p�u�,��G^i[-:�>#��⽝�S�����C�X�5�4-������� H���ÕS����dա����5\����Ԩ�\����6�0A��B�'�ƃWU��#1a:�"-�	�Q���℔~�2U~G�#f���T�-h�@�\0V0��5���:s������_a$H�8�Jq�yAx�N�!u�����<Z��~2�2�:��>�7�I(1���"d� s�,-)��\ʆ��q�_�"���%D�-;�r8:�A-���Ѡq�[��+�5(�t>h��$��ҧM/>�j [��{$�sApqTT��9�'�'�$�'&��E����ŔR������?|��%�m���KX�s��ѓ�#e[5��F^����&�'���g)+C�Qp���dwx�d���9��c� �g��R+�m���T��.E�3�ۄ���V�?zv�9ۙzW�@[����N$&|=�ڵ�m�k�����8�ag��{��0zl��k�ֱ�_����B�N��k].�(���;S��Ƽd�(Ah�����V����  ANMF        ? �  }  VP8 �  �j �*@� >�B�J�[m�  �V��J�c-����;o�r�Pn*�oӢތ�M⿛Ok{O����n���? /^�� ?�a���	��j}�� �W�/����|+������_����,�@���1�Y��������0���/������b�֏������vw����m���G= �,�;x�ȣ�2��15$�=v��J�J�M��Iˌ�tr����Ke�({�nqݩZ[-����7C���7��z� �Y�(>fw@q��)�X�Y�i��ȹ���|�?<p@'������z�@�I��J�ohe��ju�=� ��:�it�D�Zx#/�.I\�d 嬣I�g�|f��Qק;T�I*���1{�?�_��S{�wQڰc�O�D�2� �s�ߕ�@���E�W�ԏ�T
V빱�D���gQY�z��#k����t���ߎ/�cé�r�f������έ7�x*6�<�<���@�q׾����7�и_G�$@݁�y���xuu�C�X�f&H�12����X��d\G�`b���������P�2�j��~��%�n����!s�7�pv&�5r;��h�vg���
b�z�cҶ��aV[� =>n�~�H��Y��x�k���?H'��4��&�o�guo�d=Yk�龮����c��'�;�BW��108��KUs��̪�/�v����ØP��� ���� ׎KO4IBG��tb��:=nʘ����
�tŤ3bD83����R:bW|���{��S��*����颲�0Ĭ�M�������W��l���u�� 3��u([���\wFώ��=1s��}�#w�}��4��yj�  ����ܸ���?�x5��$@��~8 -~�@���@���Vjp��nZ$�OÁ�ϝ�Q�d�m���A�bj�3shu=��d� [Ca��/��%�|Zs}	���ɞv��pp~�t=&���;L?5 c���]qd�՞g����ձ��;������������-m��S~���i!��ݓ��!57eoߜ\mO�5���N��2�d���h��I��N������D�`pMĳ��X��OU�Š�H��$K�_Q���1�=�1;L�|�V�a
�}�!�?�6�únԗ�2��|1��,/����y�q�;zY9�L�A���/z0��|����"��d�<ݬ�V�ivz��@���������q��l�o�4ʾ�e-�R��*K!T�;`�R�dO41qk��REI$����yA�CdA���h<���@�v�hХ\"��=�G�l��N�w.�,s�Q[�Y��.A �ɠ#����5"<�xi �3��5��RI޲�>����L�	(���b��u�������j.������kp�vy⯐["=Me�s��ָ�o���L{��8A�\؉YH���N�c�A�������V+
�ciS�}���)���O���;�ݹ��]���#Eߵm�jp�Xv�]���P��#��q�9ڳjk����!T���x��QblU
:�|+ֻ��cL�ci�n�^����˻n���i(�-�wE��u�X���(��Nd{���F������uiM���F�-����^�W�`L1@� �ZH��ϔ"��	���8��4.T���s�+&��x��!x�aJt9@F�BDg@%w��+W�>ꜿaE�//���+��3��/��Z�h<������EL��bl�	C����ާV�ٖT�`6��D�<ӠS���Ц�_�d ��O'5;'U��@5�5����E5ޜݷ��Q��[�p��I�F�e��^�Լ'��j��jO���D�_�#|��4�S'�w]�ZF`0���� �ZF�W�o3���.�S� �d�S�ZP~�rR�;��p��x�C.���d֬�4���7R�� �g?��B���r�b�T�l�9;�n1�[��
�����o��c~�g���Mt�r��/٨��LB��#qQ��uR������4�q���9���l �C��
���Q��I��mem!F�2���!�[m�����F�Q�^Q����Z����Q���p��#^�7�~#���ݳ$�n�$w�ɿ+\���f�R5�6x�`��*l�ө�h/<�����hq����'�~��6�Ҿ��d��\@ij�_������o�8����$�IKB�X���
Y&(�i��;����.�[�u��W�����q��8 ��NBf���ф�,)�*B7�Jx���׋6��}1�\�g���� �FҤ��t.��EQ����Xܕ��dUe;��-�*?V�3�"AgX�}�6���ke�+�y}J���z�,W�|�f%�Hd��JS��J��g�Q�Gj�!Z��Aٙ3Njh�]F��Ds՗�x����Rc*pG��?R�Wn���n=��:��ȴ�|�@��8�:f��������&�6��Gx�WgQ�Íy[�mIN�$�Wy��.��si��R'� ��D�U����!��"Y^h�v�*�7gw��9�ģ�~pE�Q⇴�K?x��e[g!�y���K�i�� "�,�Y�K�ڲ�"�Znj�#?7	zKm��Yi\��q����V)��Pr:L��J[�,�*8u'��_�1�]�
<����9|��+Q������!��J�}�x�lkyALM�Yv'd׬����{jR����fIp������-E�K��]-Ϙ�'�mg}�;���d?Œ��|�	V��s'�S�Rx��	��KFj�8!��\?���y&��Ѝ���f!N	�	5cm}���+"F��7SU���wN�_�����-���7~D5'�:�Z��8��s�-I�4��O��W	�=&��l��t?H��T�=r)׈#rH����<��^[�5��0[A,�e��_,�J!��՜9ib��14$��&�lZ���[-���z*$�?PV]9SW�T���b:��D�j��jQՔ�_�%���M�����(�2��	� q<9�@K��k~�fjTy����_G�T��i?��*�+_χ��.��u?$�����T;�n�2n�WC
?��r<�y�B���kʀ�p5(J����ޟ�~(N_|۾mr�^(���{u�jdɥ]������}vli���Xi��/�$JSA��@Dg�~_�f�ai���D�/).a��ϼ��~�l��qS����PI!6�{�:�������F��l���ݥŚ@�_�*�Ȟ-5��Z������y��V(1�m`����ٸ�i�X�;�G�I�^\2��ݵ�}MCB3�%f�)κ��b���2�Z������Tb������ƠP ,�}8/�!���f]����aL�Ӡx�X�/RT�C���}�r�x��f�1�V��l~;�)��V��\NcM��
J�vSC�D2��1 Y���.��yC�L>�v��E�L,���
�ٿdP��\�7��7t�x ��M a\ˏ:��#��e��f������w�T���#F� ��v^%�P<J���|�Ԝo���M��|�9wh��+ɋ����3��+	�c�(�g��NO��˅��/ 7�it��t�zdQe��2{���f���PDW�?�|�k]�J�f6�~�9p��v��_hEZ}��m}��û��W.�+���74�N�_ZTu,m��������WH�R׸���w�r�eA`���,}}�Uun�L����cO��|_A{��y�eܑ�|k�v9t;���|�_ߚp�5�fw-�1߁2���tuU!�{?Cn��^oc�UtȤ�n靍�O-�R~���x�
է���s����H�c"�2IW,))��<��WT��˸$A؟1�S�"$�5)C�9��F�<R8ۈK� E�W$nj����>�̻<	���Q�Uc��Q�g��}��ĺ���vWo�|L�� 
�D�؟%.��z3�+�^m|"����v|c�ǭ���u2�M�M��}]���K@)�!�Q�:^�_��DS��J:oOmf�
k�9�9Qy{(Q=1�+���A�+�٦��3r$G>f�y��T�(�n5ξ�Ʈ���h�68��r��bs��y�XA�xG�׈9$���dq�J�L���d����u˅�L�iY��F��I��҇�����0�S�eNN��&�A.EUZ���'��o|���7�z
���0�br���_�A�i���+!#����~�\�n��ؗ"��N�^g��y]N��yd;��嬘�[�=f�d^�������T�b��-��nX+��]��������l����K���U!Z����_j�}xG�[�쀙��>l�y�)�r�d��>()~����D��5A�̶ƭ���w���T�[
��@3�3HM�������N�]��Wܤp�^�m�}�m�u�Xu9�r�I��UnJ	�)���|�P,q�&��
~"�(,�_���αbE�L9��0čոc{��]*�M��L�3�k�p�pfvS;�>�=��"԰P���~�oڭ$r��Cg�uj����,�`Ƭ#�tL���m����~�`�� hqL�E��8ۖ�]�$Czt��nx�?-%��I�d���(�����G���Na:����ǟ�[x�?e86"}�lv54�����&r
�h��?�}��<#T�� k�p/'�DƔ��߮���a#^����ǪЖ����~F�\��~�{"v�����	p��A�o;���s��v��)$m����������av�,u?ěWk֢t ����G�9ޫ� �}?��O#����rRIͯ%�|r
�z�`"Fz8�9���5��*rS�a��1^&2`�f��w�@�R�����@�4H��Q3m8a�jK�0Y�i�X&kc����샿����E���.����u0�a%d�ue`<��)S������.H?�%���0��C�����!��~�ߊ�8�T'o���������{9��u�W#@|���%��Ŭ�g.S��Q����S�GP7�\vݷ-_�����au�
��1}m�b_œ�CO5C��I�/��嵨�}��o`�8�M���v }
)�
��k����]#D�����E(K�ڗ^���W��F�e�^"������Wp6�5� &�b��Qm��Q���y��qL� #\�`�3U��=���n�T>�f٢[���-��w�OY�(�h���]�|(�Wzc�"�f�`��a�����%�62↉�3�76Pʄ�,ǭe��[g��y)e�q:)ʜP�ɕZA��3�G�u����D�UZ,�ˑ`�,�H�8��<>�k�ީ�B]]V�|��Q4!�J��_�AR[��/*���7��w�K j��;��e��j�o(|ԕ�Vb��#U�v4(�<���J�[����؃�7�q���ý ��{'���JX��!�e捆�7e�"�������k�J�����Vnm"Ц�D������ d7��8U�����������!��@:�����D,"y@��E�s�Ӂ�&_���VU�A��Y0��E#^�F��D�o�"Q�|��LH��5:�aW�����'�?s�Ct�Ұ�W����Bz;O����|e=��{�\��`I	�w�<��T�ƣ� $���7�HV�����N���d��¿kW�}�_��[���Gj��J���u�V��HBVJ��tJ`��5��q}��Lk~��N�M�������fO���yAl�Wz1���}Ά�.���� [����4�fJ;ZК���y��x_�c�(d���']^�]]ݶ�S�Zۑ����Ē䱷t����T�cZ�I�Bn�	��xéU�MC=�G&g>h�h�/�L|�S����9Z�(U��k�"�mNkY_�Ei�be4�C�t�Wj�:�{��>A���h��>�����x@��c~x�v{\���&��E��:j[:�&����j	R宛\`L�����c+�w$��CQ��k�
�u�;g'���/���ϑ�4��5��v�&c��V����������}�>?�!yG��mq��7HUדǥSF�T3�?G��L7�KR���
z�W��"�jHh��(�%�Z��[���؅����&��ٳ��fT�)��T�l%=��s�|2�*�I�ӡ��K�Ο�C�8^�*?�r�=�~��G�<�W��E�m=�&��Te�'w3���r�8\$3z���z�Eb�%�k�C�5/J?�/�_�{u'N�2u,*���$�hw��{g;K\Q�h��-�ڙ�dw�b��!����=i��sC*+ȟ7g-�q߰���������O~��*����
��x��&k�k<��:(���֠��/d�E��e�i��r��%EF}�dO`��$w�OX�z����O�wEe�N�9�����(Mmwܥ��J�o!��<�*��� ڈ���8dt��s�X���D �J
�^H��s��s�и���Tu�3���ۭ�N�~�_"�+g/�3�N%���@\8��JH�mm�"f���ƾ@��Ǜ��6/g�v����-jؐƧ��=%dAْM�n��<���4d�,�=s?-�I�9�\y������X7$C"E����%5�þ�z�իo�^U��Ж�U|&$�t��֟�����E-����㝭���78~6����ӕ�<G��z��+�1��A�ș��vnB�jڪ���@�R��b��"_���f�m�9�:]�j�t�Bч&�(SUU�=mHmA&��W�8u�;y��Ơ�p\d��c��8�@��\8�s���Ј�96�}}��Īc6�Ƣx@��]]��J��W��1��S�ݣ�c Ҫ�_���hL�o|��AC�ų;#�H:*_s;+����y$�h��Hɱ<�n��>�	��ey�&�%�C��1ï��i�T����>��Y�6P�-
�����mmQ�����h8Ay6Z�M �yZe��;�@���R�k^7���Z�N���-�ݫ}�I���O�O�_�Q�H��A�`���z����Q����[���I�@(�����՛�����sT�	,ۏ׫����vi��>�ys,&�7 �͔TY��M�Ā�F����Q  ANMF        ? �  }  VP8 �  4v �*@� >�@�JcY�  �P����-�o�`��Gy�:��%~���]�e�Oky�u���X�_���������w���<v���?�����������7����_��=t��������������e�a�����/mߤ�������'������=��t~���.�T���s��:v�A*q�m�ET�����?e>B�$
c���8�ܱ59����}��?�~��gY��>; ?^[�R��I���νe"��9����9h�_��I��g��#z�.��f�1����$
���7Es4X��z��\
��~üR[Di�B+=X0��#��`�+h8�ʠ���%��r��ഏ�A�p����N�;#l�Fl����w��$�"�v�p�m�t���d�l�^f3�+!S��k�Cx&;��&�X��?��]�F���<b���=9����$0纪�ë� �t]��	���'~i{N��ׇ�Z6�����Zv���I�-!�A.[|���㋆��H_��akE�*�h��N�E�.��g��#�����\BB��m��b�.��k10C����#�JϞ�[(��Z`)��\O�C��9�y�e�!��)����{9R3�l8�"{���t�u����u�2;�[�e0l��A�e������ݔŭ��#�@À����f�"�m��!�N�-�r �kɔV�=���&DH�r�|���!Lɼ�7��K�,D"���Ϩ�W�$8��8�p�Z�C�}���@�2���s��T(�-T��A>�\�[���(����!C@���	h6�߿�[��X8�:��r_AL:��2�Y*=��[���g��1�����jf��C+�+U���d�Z%�����S�W�%�=c�	"�x9˺��̆���k����w�d񹮴+���%�O�%�L����J:�����;� ��R��������t�DP��	u��Q<��9���B������"�����:�wg4���HY����d��o��/�8��'���&Z�դ�}�%���k:������Yo����?�A5���囲"B||F�{N�������.���E=䯯
�D�0��w���������<Z�?����MT��8I�` 4\:|3��9d�)���Fi|�*p���vF�b�����4�g~-��:�V$��X��3��'�g��H%
�Br�آ�hv��%�rNS���F^�romɁ���ӏ����5�<�OID���NТ+S&��%���ROv����[���;0>٤z)Ƕ!t<�c��^�*����~[V��BK+鼷bޜ���t�tw5��f�������d4͓"q=}AQ�+ֲ�*qؖ�0Ҽ�8�u�yw�׽�2����\�#�<��$.��eu�y2����^玁��P��
�' 3�+�OȔH�2��!<	���m���y	�&��U��t���3��Z$��G�������F#���|�az"�!�18�d�J��p<4�}(�D�t�q���j�!ۤ�o�N�l�_�pGx��q���;��6��_��E�7*]��g�W�ܤ[�XeM��S �diⲨ�wz�S�x�Bnz����l�9�j�G���.c~%(�~��v�w��_-�Ǻ����:T;, �&q�����V6�&�~ѷ��^j�6Ul��x4��	wI�Bk��?��yȧ%,���\�װ�*k�\�/���Mo��"Y�,M���L����'z"9�a21�l.&�:5�!N;]�yD�m� �#B�����������=�i<Χ��@��9����v`�)0��{�D�uQC��WG:� 7m�Ge�r#@��dM�I�p������"�8rxOEnN1�#:��%������L���B����ʇ0��WK�j��ڽ�����B�~8���,��p�3�qHùI���}Y�bc� Q�s��N��ϫU��"�W�5)�ћ��/�1��^Ϭ�e.5��%8�L�5:T��ɲ�=r��U���� ;ǂP�}��n��
pDhxgp��ɤ|���EQ��:ާ*[GA/fk�!"Gi����<�
^��^Sỽ���pgzi�͵z��o�/�H��&���$�6��_���ԙ��У�w��K��rt߅��$]7� �s9�)��ZQ�C�N��_e*��oj�[Kvux\�െ1@�W��Q��lpk���gi�q�)�j�^�K���lР�U:]��Sbˀ�%�*o�g��Eac*�]Y�i�y�*L�a�O��{ɗ��F��e#PR�ﳷ��k�jD5��c?J�A��®�*̣e|�3�)��:+���E1�&��<$2z�=�Z�gA����~k31A�Y��.�YA��},�6>+.�i�bz�E�s��;���C���J՜���UчvԨL��k^?BI:FS��3I��9����\"2���u�X�z>L��V#�'�� i�fy��VZ��30�5�7:�����d�uz�A5���R�q�GAnQ�o~��m��� �h�j���iH��p�(2���:LI�4�1�g��W�sJg.��r��M�^��p0'��.�N����"��A�'J U�'+�ݎ�^��jd2ሚ��z�9bO�r_��� �&�I)�HG�����e?f|%��|��x������d�RI %&?t0�5�㰕�^~�Ƈ�~�@h���;9��=�b������JLYz�J��cn�R�����_���+wc}��}+s�V$�{�
���ڧ�:���z��\?U��`-����er�Uݎ*���>��l�y0g���Ɋ}���n?R�r���4�$�냕����_8+XAWT)�]�T�]
�C
�a�Ԡ>�Y�c�uẹ�%;��_K�U�'^�g� ���E�d����z�S�0���N����JTū^7�N4� �2�M��o��6/���m�����q��ί��{O���)fL2q�F�� ��w�p%pf9�8�R��>��Z�w�W8K.����8 ���wý2o^�����3m"�<�w�}�g�*<0�W������5��ޔ��%ַpx3�Ypx�p� �11(q� t�Vn|۔!���Պ�W��C��n�M�����K�j��?��
aw���K�N��ǫ'nG�/���4�p������&�)<%l�ӹ� ��?��H�n��tGH���kh �y5$� }�'N��k����>��0	V�T*#��di�1�:bGKJ��t1F�g�"l�W����2"ŧ�r2� !��pj��Xlr�2��)��:�9.�0���Ls�3�p�׿������a�O�EV�Pf�ѻ���9����
6��I�;�9���9'�ތI#x�������WM �}����Œ��|�@�3�����~-��gY��v����BR�n{�����Z���_[����i��7� Ҩ�["��*jـ��@�u[W\⎟}%���&\W�q��/��&(B�x��YlG�����y����Dl"K�q9�&pw�rq�?���-p��׃����Zn�p����]��̕��%���E��~+�>����PMiT�n͢e�q����4�T�+6��j�+ω0E��l��.a�G�W-���#(��Y>�g� 3V��gșss�f6�D��ȇ��
�{|����%�;��{���6��W:���	�2g�'!Y����&��U&����f�Sl����؝fߢo�)V���ב�o��w\a�)��v�O��Q1�Za��3�i�iI}�Y�������d0��h��?
�W�;^�Z���;uTs��9�b��2�$�f�[�ܣ��7YP��RoP�������s���jR쬇�ZY;RT�<W_uؕ�[1�i�u���K�ܹ�I��T^ԽF��e�7'�����k���|��+D���_��!M� ��X�E]D.~S�x�-�#�.>DN�]{9�)����y�j�/5��j�t���-t����,��M}p��)*Uܘ����G~��l텀Z��+��ፉ>�ݱ�SKC�~����#�8�M���3F����V�:�ұ�t���"!�+y�G�~K$˭�E���JCR'|t5�x���$�O[�l�t�E�I�_�%�ۓ��x�M���'¿�n�K��%)�N�ϯ�P��֧�W�/q02�ø�j.�X�Z���AU�M�aX�Z��D}��=���e�M	����	h8�����!���{Q�����|+���X��8�g�B���,��;��$eT�=Z���fM=���k-��8a#º?��[�TYכ3��j�M'�l��Z��y��R\p��r(t���ڧ�����݉�P�X��h�U��b�u��1�(��������9^��]�}����`�?o������o�iպ9�Z�!h.�w���x��:�:���v���i�D�Vq%��	a6�>2�ؤȑ�[Ɉ=�Lb9p>�a�9255eϿ��v#<e�G�F�-��A����8�y:�J�$�����,b����X��E|ѯ�bO�08�@�o*�W��|�E�/�E����q�WL,��5�~��] $��A���kmٻ�)9
�Ye��� OѶ�q��IA�9ddLD8W�|{�����wV��='b�v_Wq�HY�F���{�,���%�LP�B�b؀%���ퟰ⌈~
6�QC�D������N�=|�����/?�&G0��(�w��� ��o����,~�ސ�K@��]�M#?�f�b�͌}�u�B����F��)��Q��<��m0"T�Y,���k�i[-ѵ��^mu�20�N|�Wn�᫳��d��l*R"T0P���E���
���E�-ܦCb��`��i��9a�����h���Bp+�4kOe	�v���H
��{�������QJ�'�6ϳ��C��hd��i:�vh6Y��C	kHާ�gx�K;7�0����V�˯jYKT��"K7@����]���l��	��Ǚ{j�2�/�b��8�xsOkG�k �gC�+hmx�2Z\;��~שA�x�*��������l��9��~ ��I@���_�&b�P�z;;`ظr����*�3�j�Hr�f,����Μڡ�%(?�ٮb�{�|,v�i~� �r�����"�L���ui�wp�B�i��x��+o�3o{s��kE��R��@�p/�rl�l/�v��i�5�p%,�Uf�jA���x�ۃ���iւ5�2�rKkq���ۊG���7,��E�=�.#R���<��冭#ߺ���i���U��?�N���<v|��!��
���Sj���� hz�D�m�(�$��1o��n}1��[�26�q��h7�p��ԛa[�w��� /?VH�'��"���gեe�?�k��1���7�sׇ�E��k�>�;��m�ц�>Y�eK�Z��X�<�/��Y�9V���vr��w�l`m�o�m-�96�-����[כb�N D4�qR*;������]����_yx]Id���F��9c�g-�Uº�T��(� G3���y�c�d2�+���x!�MY1;��s��1���-��d�`8��i�Zh�+-����7'�E`�v�Za}[ɕ�B�c�q4RG�g�;o���.�蔞��]2Z>٤�
Kbp�u��0%�4��1��8����b�=i����}��ߨ���0�2z04�_�Q(��+��*d<Fvxf���RG}ʹou\���,"g���7^R��gM^�b�v�;��ԍ�e��7�~�bv$�O�J���.y���\��MY�[�,?p��"��~�ه�N'�n}�<�!h%���Q�G<��1Sk��ǎ�v�(y��uݸ�g�Ǐ��r����PMvzy%�H�y�k!�����|�7^6�6��yUH��:��[�P��ږ�<y�/N��JG��Y�����N��?�tF�d��a��%�7���Ǥ�L�g�9�q�p��S���Cw*ܻx�)��sn�&�� 7��l1>�t|�H.��5��}�ě�>����B�CP)�����5��
�[y RF8�!̈́	�~��:�<.2��������i�U$���T�:�G�S���%ad�{,�#���uؓ��������i��T��]�N��:�{�S�X%�S�!zfܪy)!A�G�G�F5�������W�9 �[���`V��v\dH`H�'���g���x��iG�6��Ɏ�ŏ?5z��)�T���Q�#ɉ��"��"dt��HfF/�S3�Ѓvk�<a\��j"��$<w���^E�	�m���'���+1�^S�[s@���Y���-z߾��N^�a4ؘs?���F���ȯ��j��y�V��n���#�l��"����"i��ѝ^V�G�xL�Ƿm�Z]S������D먏Uǳv�@���7��'<�V�~�^���u�LE~E/<��v�[9���'����_���s}_�].�f���������k�j�,���riܒ�K�����|��tW	�̶�������m�t�	�W�L�!Z;��H�9j���6����V����Z_�
w�L����'{�S�d��b>HA��ե��ϭ0ƕ.��}�xl�H�9��)���_�ҙWq��ټvֆ����^i] ��p*0BI�F<��F�C��W�uP����$<��9���.lG��i�7���T �q��W����۪5b�CI"���rac?�
���di���A5�݈-��.�N��ڳ�q���#jV<cz��޿@����J�:06)��40�1��vͿ ރ�|%�uM���V�<|c�P����I���%^2�: @7��I�Q�7�	HC9�V?/�Ҝ%��2��H��y̭q彐@�PW?�����Q���p��+�
^�}�l��m{=Ss�4��~m�t���O�Z}YWY�C�d<r#�t4��!�mi������,A���EC�afegg�B#u��4s<4ֈظu���UҚ�T���_����B����^���k�@k~��g-�_v<3	���n�)"&��e=�/�wj�����%?���m�Wؼ*���v ����]���}������.I���re�9�0�d8�	d�׺��m���("�Kx���|������A���d����7m�3m)�"�^��J��ά�@�2��R�xo}M@�#d�/>�F��K$�ˮ/����#B�?
�W����D�����/���i��s�Ԯ~�:�;�.�#G�ƣ��T�6�? �sʯ{�2
{�{�y_�9HW��z�|  F�f�f[�nBk���F�"���j,��!�R�1�,�*(a��E._�UƯP9 8����r/A\�?ƵLs/���/FQ�ȉ��B���D��F9RA�&�p}�S���/(�ˣnw.��ԏV,hj�K�$���΁���? �������S�f�n�|���i~�g�_W|"R�!����u��x(?�A\P�.;��64_��Lh�]�l6J��v���&<�.Kr,|YY��])i��PQ�'�����#M&�SYMH<A�Q�v�ԧ2��f'<e��:ua�H���C������/�Z�9Rf�p�i���`�D^ܼ;���|I��BmJ֔n����T6 m~���80?ʥ� ����ݒ��G�,�e���CX+�wV��y�}ͪT>>5`F���aO3�7�L?XL����$?���"h_�|�a9���B�-YhQS��<!B<� �g�b9���b2����S�H�r�ndִ��7s=IX0F2ۃ!uG�?	�\�h(Ȗ����c�q��H���~�e��S���m>.�q�p�7O�T�{��FS��fԷ���@�����ZI�1�{����$Ad�x,�J
Q�^6�;�r��᫛�Sx��Y ��l}@ ANMF,        ? �  }  VP8   Ty �*@� >�@�J�qH�� �V��D�ރ�5 	�b7�y��ӣޠ�\�_��s��/5�����W�?��m��������@�i������g����G�?�����<�<=>��;��7����⽋��/�����o���?�~Q���2���_�'��y����p����~���/���APU9�E������z;��P� ����9�_RV��-ȱЈ),�8�XF� `�3��jp�H��6`����ꫮ���iz?c�џ!\�u����R�F��:|�����l��c��OUUeof�u�f�Ɇp�<r\��5��8')�`�L��V�:V (���Q�D��2�T���pé�~�!�����Y��M���6վUoa�o��� {�qhi��	������Y�����i����� �`ҳ�V�=��r��p/���.ޤܢ��]�;H�i\���>�"?���w�	i����i��{�A��R�+wb��J�6�����'3x���U�j�Ζ��"���P�z�?ݷ�U��G���w<�ť����G�{�'8��cQ}��^��E5;7�P��%A^�nyJKm;�v%Ͳ|C��\ZH�+%CWX��`١���׋s+W��G�]��{�PMIK�ȯ�b����dm\�VͿێi�G�zW��)*��t.�4�`����b�B'����ݐGF���R���&�ۤ�]���k��g�O*x3,|W�m1ݾh)�p�ʭc'�d�D0����Iʌ7��)˪f?3L�Z�4���� 3�7�O�wY��e���}Sۤ�C����ű#�xU
^�?O�D�L�:m¤�|�q!�n�D����i�D�˦}����z	���0.9���8�UW������Ŭ5�&�x�ޯ��o�����#|t��.�#��D��$:����Q��[�9�	p�^鞽��p*��D3D�` ���Hh-�07�]r0iFe�d�-4%d�3es-��m>U6�I馫 CQ��1:����J��DC9�|�G��� ����F!���G+��˭--��{V���$b��׹y�r��h�7�����n�`�ޏ��`�#>o��'2�|����b��P��<(*�qjR�����q7@l��h����ڴ���E:+��P̄٣�FE���$����7h���"��*Q�䃅�P��UI�C����F���X�1�Bmk�+͗n:�`|k�*���}n�L
���&���m'c>Ǣl��Dt��C;�
D.ֹ�(Է�����Oh@�{x[�?/*u���r�]mT|��13����N�\��~.w�^�؁g�h0M���gR��_��j���u�󪿍�6��	_ ���:���un><p�>FX��2���z�I{��5d�I�Cj���i�+@��KĴ�ɴ�� ^zdv�H)��3;G�����3~�O9��3���8vEl�5Kˀ�ڶ ���*�iu*z�����t�dh�#y7��fZ}?�])m!Gi������;����q$+��?����3��i�	�T��k��ب�C��g>��*�(MW�l3���l�X6��K�E���/����bQ/#�fp����|��,>8�u3ֈ�0���b�"�A�%mԘ��:�Ǉf��Vq?V�$��a:�i	A��&�=����:�X���@�3q�w:!V�#~�%���*<�~�pz%�o���H	���,���0�ܚ@�)���!����[(uS	QZFע�x���|鹪g�,&ҍ،8���ٞ�0m�p��c*�8�
��|�m;�ƻ���ߎۉ�����F*P�����F��v�K�{T�L�]���-��SX�A��$�e<�h�M1vc`��q���USW��������-!%���'&��� ��_��XDv�E/��p�$Q�$��~9GA�%3H*�H��M2#�m�vk)�=o(�8"�Ť�Sh�16B���'Sb�tzŉ�c4ĆO�����'P��B���;B��*=�{Xu�����=���)R�SP<:,-�<����U&2�=zѴ��&E�;���i�*�{	�n,�r��i��.�yF윾sK�dK�JZF��&M���KȠ�!�ʂ�k�&G�8*b�v��`C�6O'_��Q5,����"�_�������?6B�*�`eG�17�É����|ӿ�{���/R���娇=9�H�r@��������-�	Lb"�Ɣr�ol<|��,���X��ۼ=�-�Aa�S�ƒ5��������O�M��5ﺨ�]�K���~���*�'��B[���~���h�[�f��m�<�%���YK`-��9�9O��ޅ������f��dЫ�"�y��F�p��Tf�0�Tpu^�u��E���p�7�x>g�F�F�A�1f,C�f�B�W�҉�:Mɋ�tߗ��R���.~a���"
�6g�Ԙ�����e'�|Y��#���.S
���B��mdIJ�O��{��
����G�{���[���S���4�??��^B��15��_ ��ԇC =�  ���"�!��1'��$�V�/�E�To�B�Y������w�\��g�吆�zx3٥q���e��3̼����1��+.�x;����[���vE�'Fz��ܺi"$�v�����G�B�g�Q��>eg`�f�6(�br�F+ܺ
!t�~��c�1W!G[z�2\V�0>�뢵��g��8m50ݤ$�I�ӗRGJt���z��HN�~��3�)SG��?#Ch.���t֏�$�r�uU�d��cpy�nǝ ��G�
z���">���I�`�uB����X���Ǿ�V��9�n��5r�¦�X *�l���~K��+k�`�jS�ނnȘy�B�<t� ��Ϭ��m��\l���s֚�k�G���}>.k`�U=�����ݴ�ؗS���y�ʩ�(�{�ه���� �f�Q��$3��@��h��g=����7��3����9��x����xۆ�}-��B���9���=�4i_mk8O�[��p���������5a����M��i��ݹ$�5ߙ(��[�/�j� ��D��m����Y<2<�+-�^��u���j��l�e
��0c�"��SݨmS��z�ֵ���Ǧ�2�4�TK�?��e �U��g�u����H�)�AJۈ?�c������*��d1p�x<��S~�oY�]���T[:���@��%P��+��B�&ݬ�.�|.�"�̏�{�w�����iX�B��T�u�'K|=��4��7c<��o㣴��.�a� �+��� ���l?*3Q�R��O\��à������̮	HȘ����k��95�đ5�á�P���8 %�6���4�b�D���9�Z(Y7��;���^ف:dx	d}��D�$	�|�w�I���R�bع>�8�;>ӄ�{�Y�H%5�.i<�a�^ ���<�zpS�G��uW�<TC6���,}T�8R�1 �,d��:T�W�E揸4��2졂�\���'#��q������YXn\7M��Hw�"r��C �{'����������>��Ȃ�(rU��=���[��_��O&�!���9�����J�����!Kl�L+@�]�/,d"m�`�uH#t�I�@�˙a\GhA�_��up-{�M]St̩�.�G	X��E����9�Sq��.������niz�?��o�DӢ�%w�l���^Q���Fm��Y��atY�I��<6^��*�I�eBe����G<�^�up�v�n�YD`��M[�6x�E������O�� A��}A"����k�����gU��I�S~�I���*m"��.��� cc#�.��_��f���"��f}���w'��n�P���ʎI���?����'ͰV�T��6^k��1"�˞�^����3�7/H�:VL3Z��f�/�ڮ���|	Y�`�{�8j�.��Ӳ���"��]R�ysघ��]�9�p��ߓ)�/�#ҹ�*��w�͠^�<V����o�*d�K��8�cn)i�Z�h����E�ζ.��p�9��\wk���s���w�ޏ.��d��mmv��5���+R ��$�'ɒ�@�;�3VvT?  �:Jp���Oq��|;o��o(!����Z��Mɷɱ�������'d��;�w�%��Yv�T?�-FES8�Cd�y����t���X���a�5K�&�AIm�����	)D��WO�'!*�@��~����|j[���J�Y�����-T�G��S#�Q�-l\=�̜��O��#Q�Z����bG�l�3��f cf�az�pDG����'	����$��u�oG9k��ZXo�?���9�<�x��WY���NDp����.��u��6?�'��O����@����E�� ��iP�>y�Q��OWc��6ۛ�&Q����
^V �'�S��`��)����럈�(����G��в�*�=+��n,J���Պ˞�����I��ȵ��I�}��3+������H��Y��S-�aoeG;:��T�N��^j��":��T+ʓ4���ϲ#Å��d�S��"Ղ�U٤��/�3�J�(����=Au>ª�֜��E�rR�w?ft�>p�����6L�g+�!�
H�T�LJ(����1&�`��H���f�S�u]��#@�2VC48�cV����R�6�i�k|_Y��� 7 읶
��9bL�mdר^p.��.�S��p���A�d%���]�%t�##�+���@����概������6��֤*�oAe!3��||���b�%�@cb�����B%a���y} \Է������P��������5M�3���p�q[lB2<�.�;��ȷ��?K�<ccʨ�f�ʎ�Uazs4/W�T��	��D�D���1N�䩗��E[;t��,��]sF�ނ���U�#P����@y�C�U��f�@@ K<��H3t�J�,^=��3��� �,��*3����WڡD�	Ly��5q����ԏ�R8Vgk,ǥ(�R,2�(���˪
Mp%�vo���pW�l�Q��X2�5!����#n��h�]Ӯx�J�X��$��L�[R�Bq��/VQ����hŻ��~���s(i�%��(/�2f���0i�g��x�M�İ��C�*�L�nfq���ݗ�a�bͣ��)9�l�J�g0���� ��"GJ6�*@G���hDW_e�^�����p~"T_�1Lw��� �����?"����*�Y�?b0�0 >
QT�8�O�p�*t���_g+{�y�6�~�L�1�p���]��;:�����\�~Ρ&g�7�}xnPk�4kP��fA5K�鸧[f�'�2�z�e�����P	�{����NgOj��uy�RK�mG;ټ��-E�a��NMI0�W���rW|/��ʊyi{�_N<F<șA�Q��#b=�~�����}��4];��4��!��Wq���.��F��=��de|"�����!vq��Ȱ�!�*fKZ��<��{	�P G-K�&VƛDo�
�~��{b�Uh�V���$1�߿IL��`<�ж+�zz�8��?KeBֺx.R��E�8L`�
�����Ƈ�MĭE���"�2�
��A?��҉ZR�m���E~���CV�s��;/B k�����	hbۆa�;PB7�"�1��Ujg�y�W�OJ�����Й���i�7.7�>�&����4o``!���\�a�+��2M�N�J�K���b���N�?�_顭b��y�eh����#���k+��g2�g��3��d}�q�{��O�|7�����W��_��ȕ{���R�Q�ȗ��w���Pm���<F�"��D���)W_o� �}�]%� O�S���oiY��jw97z9G^�Y[)<w�C�+u�P󦙸�$�ݭ�/�@�v�ʑ��)�,�ڽ4mw����\�	lK����'
��H��;c�V���7H�ݻ=�����WQ1I�P�5���L`I��R�(����0ņϽ�5��3�:7 �)�{�:qv�[j(6��?�7�G�(y����������6v�Y"g�����#|E����<�\�߀��e�;m��!�{��ѕ!�b����G�	@�6?DH��<�@ȎT2��DS�����UQ���i.J��r����@�������8����Mp�y�� ���/s]C��/����h��Z	00� lf�}���,���"���V�[s�>�����0�g��R��/�VpD�[��<1��,:䍮%	/빖��8���9D��o����M��,[֛]˃�9[_�Cu����+M���f׿)>�#l��8��|��]��HS7	��.w�9s�lP���jf�����-`=?�� `�,�7�ʟ�؈�wd�m���s�)=ߏ4��s�[���Cx�{R�����Jl���
@�Z�e�*(.���i�6%f�i��g�r��b�0xsG�����l�)��j�f�ӞǱ#�dc�X(o�&87Y�@��f�k�`<��F�_�����-CrwE��(�Y�w�`�C�����/��8�����Q������-��s�=��E�f����'(�U.�M"mF�I�� "�7|���<�n�K��d�.ԩ	��i\�]�&]�e����Y+��C�(�R��Ś�5��!��t��m�7v�������q��9z^�,������o)
 N1��	yπ���-i
�c��>�����N�,ڻ���]K��ֿ����}u��Av �>�)�����ۃ���,��]Z��j���˞��.���c?�Y��,��]�/�O���þf�����E�M�YZ"���\-����	Ǭ3���8W�������d+v
"�A[+�Iڲ��j㚳�s�c8q��&ɣD���$a�A??��j�`�QZ��Z��H8�h
\����a�яT�$ШSD<p�T�S�b?��|X��	Zc+ ��0(?G%�?��ᰫgvŋ�z�Iocy�7�Ìմ ��1�Z%���]a�@r��r��@u~��̘TV���Z��WV���xO��F�:r�WM�o!�mv���@{�ɡ�)*ڀA�Gh݊�@"�������C-�y�&�	�Ma�g��6�c��ɋ�:�τ�[Bz�u�s��UBcլ�\%N�	-Ⱥ��f��.��:�E>8d���+�E��>]kuPɋ�<�ʡ����5;>̃�h�->����3�S���.�id�y�`�+M+w�f�yS���\�jl�	,�w.׍�������������?l[bB����E�3��&e�5tn�M��1�f����S�2��k4e�<�Ӳk�ȫ�D�[P�釽�7B �� cD�?ee3&8��hԤus�j,;t�ӑ'3I��X���կт�����@\����[�"�����w;\�7I���>_��Ϥz�]F��+0��S6�i�.w���9�qx­��A�����V�F��W�����D=?�^�Ó7�N�gЪUB�,�d�s�ñ�-0�֌W�ȉzj�l�,�:�π�j��:V�7�ykV ���(�v��~���U�i�#���L$����, ?���\�n;�U�pxD�]�J��'�K���&��n-�ؒ��MmN� ��я$B*��)v�¢1|�u��]�t3����'�G�9"�� �J٦��g"�<���zۃ�����ַl��d頉�[7 H�BF!6n�;^�|�%�"����\o�Cx�/���u�E��&��ܡU���:xp��rܢ���v YkD½h�/��BO��$��ʷդ��^ǔW��/��炗����?�@�o�����>s�pt/zhBGu:��w�Rmh��U�m����^�F�=��%o�k�T��� ANMF�        ? �  }  VP8 �  �p �*@� >�B�J�gP�  �P<��~���py`��o�Ӯޭ�u\w��5����[�������x���P/������� ?�Q�������}�-���o�_��Y��}��1����7���>������W�?���>��e�����'���?�O�����?ʝ�:���m��(e���8e��w&/�����i��,Neϳ��s�{���tR��jg���!�W������,fz��^��!�^a�Щ�c��X,QeC��/(Q�%:J�\B�6�KC��7_1�*Kl�s���,�[����9L Y�;k)Ћ�C��O��`-g{�4��m��_��Q7@�n�L%Z���o����.��rfi%&�#�'�T5)D�qLV:;Nm��w�8�P��ZPAv��?�pڡN{���"�2%ݖOAY�"E.��l)#��>h��*3p���嗅�x��K ��Qx�է�KD@��Ã��x�$��¼�݅��=v5U���m�ͱ<����,EAe������S�%��ۓ �_[b������뵐U��"��Ė"�cfL�Q��\`��*Rx�^V���S�.��c�[hy��gX��N;�-��"�$CE5�,��1�(��n֧�h�g��\��;n���5z��{����B2��h�߲���<̑;tO���ʧ�����>�&$�J��c��U:!x��<Ǜ�:=��^f���K���0L�Np��D�M��r�9(_EJx`Ϊ�Z�s���sԙ%���h;V�=�7ĺO�_Gx�7��7�rp�����0c#Iut��]}X�> ������;9襼]��h97�UP�H�K���~�'���P���ɺ0��Q�^c�몼������z��8
L��j-��wb�eE��  ������p&e����YtsA��� Ԑ�Sr��y��Yg�Znm%���#���HdDγm�s�� ���hR�4����{Z�C�ws��X`5��.M��b�6vay��_k����9D1����e�}�0����OF���E��͠_|_ζ������(:�s�I-y����.}%�%-^�8(:M�B̴���5KԞ&ϦN�Ȣ�����^=��H�����J��|��p�F�B.@mv@�pC��$�e$��J/HR]<C���wo�i���1k*�����m�2to����H�&,��7L�wU\h1���P��z3e�z�?����)�2.��	L7�"Q �5:{�J;��)��w�/�D;�WdD�6�<�w7��X"\= ��9I�a�����-%�`���J*���,r��-�C���=#��Y����>A�֍��l��9����S�(���V�˾;�r׭��e'E���`}\*�/��R���/~%��3�����ʕ� ��_F<�,�bK�
�s_Yϋ7?����	���L����V��5�~�����Ŵ����u��D����n�Z�sc� �a$�6ǖh���J��WĖu����!�&�P�G�hN���!c�a����Q�.��}���]7[V~���	�ǘ��ΉP(����x�x���O��.^6>(��������3J%�nfi5h��;���[ �0 ����O�um�	.`Ir�Wfa�Ts����B�����dp���'P��vز4+�n&f7�����br9M-\�n�ʷC&�Ƚ���K��l=�+2Ucf/튄a��kϛ��+�U}w�D��\�����ݓX~}�涊�	բ�R�݋�X�\)H��qC�QW�I*�ָ:�H)G6@��"R��!�#�$�+����8˶�	ĕ��g�/J��@<�/5���l������ɬ,}�IF�U�X���`�['��}�@4@�VP��2�(H~�Q���k�
�=���|1W?!n�L���]hӶ�6N�a�����؀b�׼%�E,~Z�tΩ؝�������������w6u�2�y��[�a�_�%`��A��G�J�|��#�����M��o�#����&u%���I�_Po=#�Ι�+�����V���b��jGTJ	�|
5K��u���s�f��0µ�x?�6��0�����Ǉ��d���6b0"G��:,��9��ះ�E?��#�.�&�!ö�kD�OU�y��o%�r#���|��z�V�Kyn���jG(��?-Q�R>��k��/��:C��3�W�U��چ��2]��g���v�;�)��Kxob�KQ��m�I����+�s��s���K_8w$�M��)3���Γ֖�VZ|��h���+�&f�ȥX�HQ���b��7�����T �XיϘ�g�C�Z>�x��71
	͓؁�5&����{mrk���X���V|��j��"�@�����t��zW�͡pZC�m)�J����|�����Wb����p9�b��ϋ�_�I3�b$=C��* %(f	����gW4����xs]�]�Ԙ�p���۪��n�O�ѳ�`3��mz@�\&d'a�J�\D�JJ�����2cR"@��;I�M���880�QG���|s���z�cH�0t�zBv��עx�/�MI�ѝ��p"T�QPc}N��a����zC��=��ɪz��3�-�nu�]h�p�($[�s�>b��G�T�\V���'J䢜��i�������
� Ĵ�YR���vX���u#{'��)���'␮x4~ᡈ������FKg����R��q�ݬ� Ƕ���4�i��ӏ1�D�8���qg[H���o9
n��ϣ�]IMØ�4Z���a�3lo��-���(��i�-�盘+yna��}D��Ve)��7h�����U,a���s*���'&�FJ��\�>	��SNy.%�`�	�mÜ�o����x�N�VE�g�b����r�2(���YEL�R��}'ė���%J�R{����F���w��ih�c7���Z|���]䫏o+ ]	Z�HxO�}��Y���c:K�j�"�$��}��3�S���j{n/a� ye<P2!�E��<q��EC�@��ͅN�1W��O���[YC��Ż*jv譞�D��l�����KD��+��VQҤ_e�T9F$e`b�A�+}�Ν�>:U`L�%t�z�����
E�I��l�c�-����7H�u�(Bgū`����#`�e�2�u'x�t�=_�Z.q�\�r{xs-�^���LiA��E#���_U�]�؁E�>�6�F�Am��-�Ly���Y�:�e���7 OM�;8��V1=�u4 ��?vq��C��CB�1E8��P*�:mO�̠�r�*5�����'K{�'o�\��
��9�"9f���|���*��X�p��o\�Zw��sw��y*�)�Пcc�C�(8���m�E2��(��5�4"�O��{	�maX����6�Ԗ�nK���lĕRg�=����9q�1�'�:�	Z��t��B>��p�M���f�*���똝W\���F�.��%�^��b�͆s#���?�U(a�*���=C�'Pz(�V�4������6ޮt�z�+6%�\�}�]��Ē ���{�~�x��فWP�ux��k*�@Ծ�A��n�Q�b�ы�-l'D���y�������/�7�Lt�85��_������{j�C/յ�S-�s���{@����đSU6�tl7����̡�"�uϓK:sA�t��ii�|Si�2Mރ���؅<�	�G`�����@'+%�������.���YKikm�0��ae2��tMm�nbp�IS���(�8&�!�&��N�0��BZ� D�fI|{?���N��C�X"�V(�x���H��Vi��u���X���=���O|��~=|���ֆsWsy�~�qaj�G�%����# r�����&�ۋى�1X�T��Ф�v{.�^��jC�a�˱���0!�ջ�{(�r�(���}ZWM
�}
^�?�(ڕ%�-�ؕO7�w�	�|��Wq��-�k�*�]sv�
1��N/��ߟ�\r�Gb��1H#�w�͕[-q��]&�oD���S��9g��n^��ǩ��@˟6E*�;�@�����滿/�!PC���R4�w�t.�����
��W[4��Ǜf\�ݓ�����3�(�4�lI��#�4��<���y��p��'�]�y�G�=�lp���8���`>���C-C��1��l7P��	�{�Q��W�x7�%)�{pa�O��am�G��K5�����޺�^�C�Vy*��ѱ�bb	�j/ޣ�<�<�#w��	�UeI�m4�1��,�L��m1��W��l^9�I���G=)ZN��'`�{���!�/��M.)� �i7j���<x�>���7{�w��P6�»���C���U���9�*Y�B��Y��{��HI�wLi�eؠ�3T߭����ͨ�Qw~�)o�6@��irL������ �Z��V\|��Ո��heP*��0�����+b����B��l�"ݹ����
J�p 9.tѕ"��ҷ���=��o�3�F���/�Sț��Ħ�R�zs�hԊK�s�n�ȈL/������م�Ey�4R��=s�{�w�j&~2����^b������B����H ���p*����V��F(�ş�~��M=1�֍}[���"ZG���)��$�{�W7}���ϷuS�bj��za���g�p[�^���~��~nw�g��7�&z�!=�+P�\�M|7.4��Ѥ2���K�;oߔ-�#��JB_f�]�
z��+u�C��n-��.�u�,��G��ҳ(Ұ�閶�pn�U�Tٌ��d��"��X���ђ\�%�=�^�P?��h� �[��w��kC��b9�J��o�#�ڡ[�y6�P�M��=�:�,�ޣV�%�eD�{fB���Z9���<�Ź�����xZ��x�;n��M�i�nO�9_�����5��e��DO.$S�����g���]c�G�²�F��6��v�W�,W����T�I�h����h@}�W�@U03�)��XT�dҿq^ �+�3E��_T��N�� 9y��,���"��k�T+A�؄���$��d�j�Q�|JH�!�I��!�1��#�R�5�*7	:�~���74�����;�u&;��1�<p'@/����LA�,Jxn�����]�q����u&`�ކ%&<�er�x��{z���06��k�=%�8��P��a�G�f�1��ZE�j 4�X���T��4�R7z�L�LHf�A���uZ����1�B��H�0�U�IG�j� (8�o6~?��`=�,�}�ϓ@�>��l�Z��J���C��N:�0�I�#�&�\��� ����X��]B�S��/�*�y���/d�6���Ց?��kq����a��t������@��
>)&�6}�'�?��>L�Z<P�� �G<����
_����D5\�O�	�5���M��k��J����^��Ò]^�']��VES���c���w��#���hx&n/��|���
d{����6ᠯ��-4��wJH�ܱ`�)��
��PlPmZ�קwm�c�I�T��N��}���f�	�\a[34o�K-q�����`\;7b�P����1�|g2����?�o�(�&h5|̰�O��&��|�����������gx-ݎ��`�x{�v��?�!����w�F�7�Gw
�3S[.%���>үm<5vgd\z&�5�0#�p�[e`׋����h��Ŝ�Ȗa9G����©��uK����O���6YdMх�ї=_����[��1�c)���)Ueo-s���(��/V=u��a|�m@{��Cǋ��7$�Q�c	��<��$����<��
�:����3S�b4�׬�3W/�rX��?2dҎ@���v#5J_�ڸ�)�%����m�G9��M��6���¬"�|�/�o�r�R��۲g��c�8����R�/د=u��c�kj��xl�	��Ato^+�"�o&Fѿڝ�2��W�n	c3m�{G��;��{�
�T+��F1�#��7����1����a�uf�Ώ�� ��tu1�7�=G��erlayTransformAbsolute)(VROverlayHandle_t ulOverlayHandle, ETrackingUniverseOrigin * peTrackingOrigin, struct HmdMatrix34_t * pmatTrackingOriginToOverlayTransform);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *SetOverlayTransformTrackedDeviceRelative)(VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t unTrackedDevice, struct HmdMatrix34_t * pmatTrackedDeviceToOverlayTransform);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *GetOverlayTransformTrackedDeviceRelative)(VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t * punTrackedDevice, struct HmdMatrix34_t * pmatTrackedDeviceToOverlayTransform);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *SetOverlayTransformTrackedDeviceComponent)(VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t unDeviceIndex, char * pchComponentName);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *GetOverlayTransformTrackedDeviceComponent)(VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t * punDeviceIndex, char * pchComponentName, uint32_t unComponentNameSize);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *GetOverlayTransformOverlayRelative)(VROverlayHandle_t ulOverlayHandle, VROverlayHandle_t * ulOverlayHandleParent, struct HmdMatrix34_t * pmatParentOverlayToOverlayTransform);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *SetOverlayTransformOverlayRelative)(VROverlayHandle_t ulOverlayHandle, VROverlayHandle_t ulOverlayHandleParent, struct HmdMatrix34_t * pmatParentOverlayToOverlayTransform);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *ShowOverlay)(VROverlayHandle_t ulOverlayHandle);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *HideOverlay)(VROverlayHandle_t ulOverlayHandle);
	bool (OPENVR_FNTABLE_CALLTYPE *IsOverlayVisible)(VROverlayHandle_t ulOverlayHandle);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *GetTransformForOverlayCoordinates)(VROverlayHandle_t ulOverlayHandle, ETrackingUniverseOrigin eTrackingOrigin, struct HmdVector2_t coordinatesInOverlay, struct HmdMatrix34_t * pmatTransform);
	bool (OPENVR_FNTABLE_CALLTYPE *PollNextOverlayEvent)(VROverlayHandle_t ulOverlayHandle, struct VREvent_t * pEvent, uint32_t uncbVREvent);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *GetOverlayInputMethod)(VROverlayHandle_t ulOverlayHandle, VROverlayInputMethod * peInputMethod);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *SetOverlayInputMethod)(VROverlayHandle_t ulOverlayHandle, VROverlayInputMethod eInputMethod);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *GetOverlayMouseScale)(VROverlayHandle_t ulOverlayHandle, struct HmdVector2_t * pvecMouseScale);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *SetOverlayMouseScale)(VROverlayHandle_t ulOverlayHandle, struct HmdVector2_t * pvecMouseScale);
	bool (OPENVR_FNTABLE_CALLTYPE *ComputeOverlayIntersection)(VROverlayHandle_t ulOverlayHandle, struct VROverlayIntersectionParams_t * pParams, struct VROverlayIntersectionResults_t * pResults);
	bool (OPENVR_FNTABLE_CALLTYPE *HandleControllerOverlayInteractionAsMouse)(VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t unControllerDeviceIndex);
	bool (OPENVR_FNTABLE_CALLTYPE *IsHoverTargetOverlay)(VROverlayHandle_t ulOverlayHandle);
	VROverlayHandle_t (OPENVR_FNTABLE_CALLTYPE *GetGamepadFocusOverlay)();
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *SetGamepadFocusOverlay)(VROverlayHandle_t ulNewFocusOverlay);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *SetOverlayNeighbor)(EOverlayDirection eDirection, VROverlayHandle_t ulFrom, VROverlayHandle_t ulTo);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *MoveGamepadFocusToNeighbor)(EOverlayDirection eDirection, VROverlayHandle_t ulFrom);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *SetOverlayTexture)(VROverlayHandle_t ulOverlayHandle, struct Texture_t * pTexture);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *ClearOverlayTexture)(VROverlayHandle_t ulOverlayHandle);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *SetOverlayRaw)(VROverlayHandle_t ulOverlayHandle, void * pvBuffer, uint32_t unWidth, uint32_t unHeight, uint32_t unDepth);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *SetOverlayFromFile)(VROverlayHandle_t ulOverlayHandle, char * pchFilePath);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *GetOverlayTexture)(VROverlayHandle_t ulOverlayHandle, void ** pNativeTextureHandle, void * pNativeTextureRef, uint32_t * pWidth, uint32_t * pHeight, uint32_t * pNativeFormat, ETextureType * pAPIType, EColorSpace * pColorSpace, struct VRTextureBounds_t * pTextureBounds);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *ReleaseNativeOverlayHandle)(VROverlayHandle_t ulOverlayHandle, void * pNativeTextureHandle);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *GetOverlayTextureSize)(VROverlayHandle_t ulOverlayHandle, uint32_t * pWidth, uint32_t * pHeight);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *CreateDashboardOverlay)(char * pchOverlayKey, char * pchOverlayFriendlyName, VROverlayHandle_t * pMainHandle, VROverlayHandle_t * pThumbnailHandle);
	bool (OPENVR_FNTABLE_CALLTYPE *IsDashboardVisible)();
	bool (OPENVR_FNTABLE_CALLTYPE *IsActiveDashboardOverlay)(VROverlayHandle_t ulOverlayHandle);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *SetDashboardOverlaySceneProcess)(VROverlayHandle_t ulOverlayHandle, uint32_t unProcessId);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *GetDashboardOverlaySceneProcess)(VROverlayHandle_t ulOverlayHandle, uint32_t * punProcessId);
	void (OPENVR_FNTABLE_CALLTYPE *ShowDashboard)(char * pchOverlayToShow);
	TrackedDeviceIndex_t (OPENVR_FNTABLE_CALLTYPE *GetPrimaryDashboardDevice)();
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *ShowKeyboard)(EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, char * pchDescription, uint32_t unCharMax, char * pchExistingText, bool bUseMinimalMode, uint64_t uUserValue);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *ShowKeyboardForOverlay)(VROverlayHandle_t ulOverlayHandle, EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, char * pchDescription, uint32_t unCharMax, char * pchExistingText, bool bUseMinimalMode, uint64_t uUserValue);
	uint32_t (OPENVR_FNTABLE_CALLTYPE *GetKeyboardText)(char * pchText, uint32_t cchText);
	void (OPENVR_FNTABLE_CALLTYPE *HideKeyboard)();
	void (OPENVR_FNTABLE_CALLTYPE *SetKeyboardTransformAbsolute)(ETrackingUniverseOrigin eTrackingOrigin, struct HmdMatrix34_t * pmatTrackingOriginToKeyboardTransform);
	void (OPENVR_FNTABLE_CALLTYPE *SetKeyboardPositionForOverlay)(VROverlayHandle_t ulOverlayHandle, struct HmdRect2_t avoidRect);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *SetOverlayIntersectionMask)(VROverlayHandle_t ulOverlayHandle, struct VROverlayIntersectionMaskPrimitive_t * pMaskPrimitives, uint32_t unNumMaskPrimitives, uint32_t unPrimitiveSize);
	EVROverlayError (OPENVR_FNTABLE_CALLTYPE *GetOverlayFlags)(VROverlayHandle_t ulOverlayHandle, uint32_t * pFlags);
	VRMessageOverlayResponse (OPENVR_FNTABLE_CALLTYPE *ShowMessageOverlay)(char * pchText, char * pchCaption, char * pchButton0Text, char * pchButton1Text, char * pchButton2Text, char * pchButton3Text);
	void (OPENVR_FNTABLE_CALLTYPE *CloseMessageOverlay)();
};

struct VR_IVRRenderModels_FnTable
{
	EVRRenderModelError (OPENVR_FNTABLE_CALLTYPE *LoadRenderModel_Async)(char * pchRenderModelName, struct RenderModel_t ** ppRenderModel);
	void (OPENVR_FNTABLE_CALLTYPE *FreeRenderModel)(struct RenderModel_t * pRenderModel);
	EVRRenderModelError (OPENVR_FNTABLE_CALLTYPE *LoadTexture_Async)(TextureID_t textureId, struct RenderModel_TextureMap_t ** ppTexture);
	void (OPENVR_FNTABLE_CALLTYPE *FreeTexture)(struct RenderModel_TextureMap_t * pTexture);
	EVRRenderModelError (OPENVR_FNTABLE_CALLTYPE *LoadTextureD3D11_Async)(TextureID_t textureId, void * pD3D11Device, void ** ppD3D11Texture2D);
	EVRRenderModelError (OPENVR_FNTABLE_CALLTYPE *LoadIntoTextureD3D11_Async)(TextureID_t textureId, void * pDstTexture);
	void (OPENVR_FNTABLE_CALLTYPE *FreeTextureD3D11)(void * pD3D11Texture2D);
	uint32_t (OPENVR_FNTABLE_CALLTYPE *GetRenderModelName)(uint32_t unRenderModelIndex, char * pchRenderModelName, uint32_t unRenderModelNameLen);
	uint32_t (OPENVR_FNTABLE_CALLTYPE *GetRenderModelCount)();
	uint32_t (OPENVR_FNTABLE_CALLTYPE *GetComponentCount)(char * pchRenderModelName);
	uint32_t (OPENVR_FNTABLE_CALLTYPE *GetComponentName)(char * pchRenderModelName, uint32_t unComponentIndex, char * pchComponentName, uint32_t unComponentNameLen);
	uint64_t (OPENVR_FNTABLE_CALLTYPE *GetComponentButtonMask)(char * pchRenderModelName, char * pchComponentName);
	uint32_t (OPENVR_FNTABLE_CALLTYPE *GetComponentRenderModelName)(char * pchRenderModelName, char * pchComponentName, char * pchComponentRenderModelName, uint32_t unComponentRenderModelNameLen);
	bool (OPENVR_FNTABLE_CALLTYPE *GetComponentState)(char * pchRenderModelName, char * pchComponentName, VRControllerState_t * pControllerState, struct RenderModel_ControllerMode_State_t * pState, struct RenderModel_ComponentState_t * pComponentState);
	bool (OPENVR_FNTABLE_CALLTYPE *RenderModelHasComponent)(char * pchRenderModelName, char * pchComponentName);
	uint32_t (OPENVR_FNTABLE_CALLTYPE *GetRenderModelThumbnailURL)(char * pchRenderModelName, char * pchThumbnailURL, uint32_t unThumbnailURLLen, EVRRenderModelError * peError);
	uint32_t (OPENVR_FNTABLE_CALLTYPE *GetRenderModelOriginalPath)(char * pchRenderModelName, char * pchOriginalPath, uint32_t unOriginalPathLen, EVRRenderModelError * peError);
	char * (OPENVR_FNTABLE_CALLTYPE *GetRenderModelErrorNameFromEnum)(EVRRenderModelError error);
};

struct VR_IVRNotifications_FnTable
{
	EVRNotificationError (OPENVR_FNTABLE_CALLTYPE *CreateNotification)(VROverlayHandle_t ulOverlayHandle, uint64_t ulUserValue, EVRNotificationType type, char * pchText, EVRNotificationStyle style, struct NotificationBitmap_t * pImage, VRNotificationId * pNotificationId);
	EVRNotificationError (OPENVR_FNTABLE_CALLTYPE *RemoveNotification)(VRNotificationId notificationId);
};

struct VR_IVRSettings_FnTable
{
	char * (OPENVR_FNTABLE_CALLTYPE *GetSettingsErrorNameFromEnum)(EVRSettingsError eError);
	bool (OPENVR_FNTABLE_CALLTYPE *Sync)(bool bForce, EVRSettingsError * peError);
	void (OPENVR_FNTABLE_CALLTYPE *SetBool)(char * pchSection, char * pchSettingsKey, bool bValue, EVRSettingsError * peError);
	void (OPENVR_FNTABLE_CALLTYPE *SetInt32)(char * pchSection, char * pchSettingsKey, int32_t nValue, EVRSettingsError * peError);
	void (OPENVR_FNTABLE_CALLTYPE *SetFloat)(char * pchSection, char * pchSettingsKey, float flValue, EVRSettingsError * peError);
	void (OPENVR_FNTABLE_CALLTYPE *SetString)(char * pchSection, char * pchSettingsKey, char * pchValue, EVRSettingsError * peError);
	bool (OPENVR_FNTABLE_CALLTYPE *GetBool)(char * pchSection, char * pchSettingsKey, EVRSettingsError * peError);
	int32_t (OPENVR_FNTABLE_CALLTYPE *GetInt32)(char * pchSection, char * pchSettingsKey, EVRSettingsError * peError);
	float (OPENVR_FNTABLE_CALLTYPE *GetFloat)(char * pchSection, char * pchSettingsKey, EVRSettingsError * peError);
	void (OPENVR_FNTABLE_CALLTYPE *GetString)(char * pchSection, char * pchSettingsKey, char * pchValue, uint32_t unValueLen, EVRSettingsError * peError);
	void (OPENVR_FNTABLE_CALLTYPE *RemoveSection)(char * pchSection, EVRSettingsError * peError);
	void (OPENVR_FNTABLE_CALLTYPE *RemoveKeyInSection)(char * pchSection, char * pchSettingsKey, EVRSettingsError * peError);
};

struct VR_IVRScreenshots_FnTable
{
	EVRScreenshotError (OPENVR_FNTABLE_CALLTYPE *RequestScreenshot)(ScreenshotHandle_t * pOutScreenshotHandle, EVRScreenshotType type, char * pchPreviewFilename, char * pchVRFilename);
	EVRScreenshotError (OPENVR_FNTABLE_CALLTYPE *HookScreenshot)(EVRScreenshotType * pSupportedTypes, int numTypes);
	EVRScreenshotType (OPENVR_FNTABLE_CALLTYPE *GetScreenshotPropertyType)(ScreenshotHandle_t screenshotHandle, EVRScreenshotError * pError);
	uint32_t (OPENVR_FNTABLE_CALLTYPE *GetScreenshotPropertyFilename)(ScreenshotHandle_t screenshotHandle, EVRScreenshotPropertyFilenames filenameType, char * pchFilename, uint32_t cchFilename, EVRScreenshotError * pError);
	EVRScreenshotError (OPENVR_FNTABLE_CALLTYPE *UpdateScreenshotProgress)(ScreenshotHandle_t screenshotHandle, float flProgress);
	EVRScreenshotError (OPENVR_FNTABLE_CALLTYPE *TakeStereoScreenshot)(ScreenshotHandle_t * pOutScreenshotHandle, char * pchPreviewFilename, char * pchVRFilename);
	EVRScreenshotError (OPENVR_FNTABLE_CALLTYPE *SubmitScreenshot)(ScreenshotHandle_t screenshotHandle, EVRScreenshotType type, char * pchSourcePreviewFilename, char * pchSourceVRFilename);
};

struct VR_IVRResources_FnTable
{
	uint32_t (OPENVR_FNTABLE_CALLTYPE *LoadSharedResource)(char * pchResourceName, char * pchBuffer, uint32_t unBufferLen);
	uint32_t (OPENVR_FNTABLE_CALLTYPE *GetResourceFullPath)(char * pchResourceName, char * pchResourceTypeDirectory, char * pchPathBuffer, uint32_t unBufferLen);
};

struct VR_IVRDriverManager_FnTable
{
	uint32_t (OPENVR_FNTABLE_CALLTYPE *GetDriverCount)();
	uint32_t (OPENVR_FNTABLE_CALLTYPE *GetDriverName)(DriverId_t nDriver, char * pchValue, uint32_t unBufferSize);
};


#if 0
// Global entry points
S_API intptr_t VR_InitInternal( EVRInitError *peError, EVRApplicationType eType );
S_API void VR_ShutdownInternal();
S_API bool VR_IsHmdPresent();
S_API intptr_t VR_GetGenericInterface( const char *pchInterfaceVersion, EVRInitError *peError );
S_API bool VR_IsRuntimeInstalled();
S_API const char * VR_GetVRInitErrorAsSymbol( EVRInitError error );
S_API const char * VR_GetVRInitErrorAsEnglishDescription( EVRInitError error );
#endif

#endif // __OPENVR_API_FLAT_H__


