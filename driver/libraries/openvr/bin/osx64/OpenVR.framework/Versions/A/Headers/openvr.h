#pragma once

// openvr.h
//========= Copyright Valve Corporation ============//
// Dynamically generated file. Do not modify this file directly.

#ifndef _OPENVR_API
#define _OPENVR_API

#include <stdint.h>



// vrtypes.h
#ifndef _INCLUDE_VRTYPES_H
#define _INCLUDE_VRTYPES_H

// Forward declarations to avoid requiring vulkan.h
struct VkDevice_T;
struct VkPhysicalDevice_T;
struct VkInstance_T;
struct VkQueue_T;

// Forward declarations to avoid requiring d3d12.h
struct ID3D12Resource;
struct ID3D12CommandQueue;

namespace vr
{
#pragma pack( push, 8 )

typedef void* glSharedTextureHandle_t;
typedef int32_t glInt_t;
typedef uint32_t glUInt_t;

// right-handed system
// +y is up
// +x is to the right
// -z is going away from you
// Distance unit is  meters
struct HmdMatrix34_t
{
	float m[3][4];
};

struct HmdMatrix44_t
{
	float m[4][4];
};

struct HmdVector3_t
{
	float v[3];
};

struct HmdVector4_t
{
	float v[4];
};

struct HmdVector3d_t
{
	double v[3];
};

struct HmdVector2_t
{
	float v[2];
};

struct HmdQuaternion_t
{
	double w, x, y, z;
};

struct HmdColor_t
{
	float r, g, b, a;
};

struct HmdQuad_t
{
	HmdVector3_t vCorners[ 4 ];
};

struct HmdRect2_t
{
	HmdVector2_t vTopLeft;
	HmdVector2_t vBottomRight;
};

/** Used to return the post-distortion UVs for each color channel. 
* UVs range from 0 to 1 with 0,0 in the upper left corner of the 
* source render target. The 0,0 to 1,1 range covers a single eye. */
struct DistortionCoordinates_t
{
	float rfRed[2];
	float rfGreen[2];
	float rfBlue[2];
};

enum EVREye
{
	Eye_Left = 0,
	Eye_Right = 1
};

enum ETextureType
{
	TextureType_DirectX = 0, // Handle is an ID3D11Texture
	TextureType_OpenGL = 1,  // Handle is an OpenGL texture name or an OpenGL render buffer name, depending on submit flags
	TextureType_Vulkan = 2, // Handle is a pointer to a VRVulkanTextureData_t structure
	TextureType_IOSurface = 3, // Handle is a macOS cross-process-sharable IOSurfaceRef
	TextureType_DirectX12 = 4, // Handle is a pointer to a D3D12TextureData_t structure
};

enum EColorSpace
{
	ColorSpace_Auto = 0,	// Assumes 'gamma' for 8-bit per component formats, otherwise 'linear'.  This mirrors the DXGI formats which have _SRGB variants.
	ColorSpace_Gamma = 1,	// Texture data can be displayed directly on the display without any conversion (a.k.a. display native format).
	ColorSpace_Linear = 2,	// Same as gamma but has been converted to a linear representation using DXGI's sRGB conversion algorithm.
};

struct Texture_t
{
	void* handle; // See ETextureType definition above
	ETextureType eType;
	EColorSpace eColorSpace;
};

// Handle to a shared texture (HANDLE on Windows obtained using OpenSharedResource).
typedef uint64_t SharedTextureHandle_t;
#define INVALID_SHARED_TEXTURE_HANDLE	((vr::SharedTextureHandle_t)0)

enum ETrackingResult
{
	TrackingResult_Uninitialized			= 1,

	TrackingResult_Calibrating_InProgress	= 100,
	TrackingResult_Calibrating_OutOfRange	= 101,

	TrackingResult_Running_OK				= 200,
	TrackingResult_Running_OutOfRange		= 201,
};

typedef uint32_t DriverId_t;
static const uint32_t k_nDriverNone = 0xFFFFFFFF;

static const uint32_t k_unMaxDriverDebugResponseSize = 32768;

/** Used to pass device IDs to API calls */
typedef uint32_t TrackedDeviceIndex_t;
static const uint32_t k_unTrackedDeviceIndex_Hmd = 0;
static const uint32_t k_unMaxTrackedDeviceCount = 16;
static const uint32_t k_unTrackedDeviceIndexOther = 0xFFFFFFFE;
static const uint32_t k_unTrackedDeviceIndexInvalid = 0xFFFFFFFF;

/** Describes what kind of object is being tracked at a given ID */
enum ETrackedDeviceClass
{
	TrackedDeviceClass_Invalid = 0,				// the ID was not valid.
	TrackedDeviceClass_HMD = 1,					// Head-Mounted Displays
	TrackedDeviceClass_Controller = 2,			// Tracked controllers
	TrackedDeviceClass_GenericTracker = 3,		// Generic trackers, similar to controllers
	TrackedDeviceClass_TrackingReference = 4,	// Camera and base stations that serve as tracking reference points
	TrackedDeviceClass_DisplayRedirect = 5,		// Accessories that aren't necessarily tracked themselves, but may redirect video output from other tracked devices
};


/** Describes what specific role associated with a tracked device */
enum ETrackedControllerRole
{
	TrackedControllerRole_Invalid = 0,					// Invalid value for controller type
	TrackedControllerRole_LeftHand = 1,					// Tracked device associated with the left hand
	TrackedControllerRole_RightHand = 2,				// Tracked device associated with the right hand
};


/** describes a single pose for a tracked object */
struct TrackedDevicePose_t
{
	HmdMatrix34_t mDeviceToAbsoluteTracking;
	HmdVector3_t vVelocity;				// velocity in tracker space in m/s
	HmdVector3_t vAngularVelocity;		// angular velocity in radians/s (?)
	ETrackingResult eTrackingResult;
	bool bPoseIsValid;

	// This indicates that there is a device connected for this spot in the pose array.
	// It could go from true to false if the user unplugs the device.
	bool bDeviceIsConnected;
};

/** Identifies which style of tracking origin the application wants to use
* for the poses it is requesting */
enum ETrackingUniverseOrigin
{
	TrackingUniverseSeated = 0,		// Poses are provided relative to the seated zero pose
	TrackingUniverseStanding = 1,	// Poses are provided relative to the safe bounds configured by the user
	TrackingUniverseRawAndUncalibrated = 2,	// Poses are provided in the coordinate system defined by the driver.  It has Y up and is unified for devices of the same driver. You usually don't want this one.
};

// Refers to a single container of properties
typedef uint64_t PropertyContainerHandle_t;
typedef uint32_t PropertyTypeTag_t;

static const PropertyContainerHandle_t k_ulInvalidPropertyContainer = 0;
static const PropertyTypeTag_t k_unInvalidPropertyTag = 0;

// Use these tags to set/get common types as struct properties
static const PropertyTypeTag_t k_unFloatPropertyTag = 1;
static const PropertyTypeTag_t k_unInt32PropertyTag = 2;
static const PropertyTypeTag_t k_unUint64PropertyTag = 3;
static const PropertyTypeTag_t k_unBoolPropertyTag = 4;
static const PropertyTypeTag_t k_unStringPropertyTag = 5;

static const PropertyTypeTag_t k_unHmdMatrix34PropertyTag = 20;
static const PropertyTypeTag_t k_unHmdMatrix44PropertyTag = 21;
static const PropertyTypeTag_t k_unHmdVector3PropertyTag = 22;
static const PropertyTypeTag_t k_unHmdVector4PropertyTag = 23;

static const PropertyTypeTag_t k_unHiddenAreaPropertyTag = 30;

static const PropertyTypeTag_t k_unOpenVRInternalReserved_Start = 1000;
static const PropertyTypeTag_t k_unOpenVRInternalReserved_End = 10000;


/** Each entry in this enum represents a property that can be retrieved about a
* tracked device. Many fields are only valid for one ETrackedDeviceClass. */
enum ETrackedDeviceProperty
{
	Prop_Invalid								= 0,

	// general properties that apply to all device classes
	Prop_TrackingSystemName_String				= 1000,
	Prop_ModelNumber_String						= 1001,
	Prop_SerialNumber_String					= 1002,
	Prop_RenderModelName_String					= 1003,
	Prop_WillDriftInYaw_Bool					= 1004,
	Prop_ManufacturerName_String				= 1005,
	Prop_TrackingFirmwareVersion_String			= 1006,
	Prop_HardwareRevision_String				= 1007,
	Prop_AllWirelessDongleDescriptions_String	= 1008,
	Prop_ConnectedWirelessDongle_String			= 1009,
	Prop_DeviceIsWireless_Bool					= 1010,
	Prop_DeviceIsCharging_Bool					= 1011,
	Prop_DeviceBatteryPercentage_Float			= 1012, // 0 is empty, 1 is full
	Prop_StatusDisplayTransform_Matrix34		= 1013,
	Prop_Firmware_UpdateAvailable_Bool			= 1014,
	Prop_Firmware_ManualUpdate_Bool				= 1015,
	Prop_Firmware_ManualUpdateURL_String		= 1016,
	Prop_HardwareRevision_Uint64				= 1017,
	Prop_FirmwareVersion_Uint64					= 1018,
	Prop_FPGAVersion_Uint64						= 1019,
	Prop_VRCVersion_Uint64						= 1020,
	Prop_RadioVersion_Uint64					= 1021,
	Prop_DongleVersion_Uint64					= 1022,
	Prop_BlockServerShutdown_Bool				= 1023,
	Prop_CanUnifyCoordinateSystemWithHmd_BoU��8a�� ���Î��8��2� ��� ���7�ǯ?���� �	 �`4�-V���t�=^����~������+��v�r$`d�ϖ�j��ÛF�*��M��w.�'eY����,���p[��E��f#�I���Y��|1���w-m�dٲQ�P���fS�
�;������5�Ҋ��,�l޴�0������Y5���\ d2�T���J��;�0Ȕ#wݓ�yz����}Qi�D������D�qGD�A���������Ns3�� ���<0:�d�0�ur�,1����b����F��v֬Y�{����M��% �/�oJ���E9x�吋f�Ή������g �Ǆ(�#����,9i��4Ù7�����>�r
�[��s[k;�Qk�1q�>J鍸�Y���6u�QTT@���:�J����&M��BZu�'{¿DM�T�.ôZ�I��4�9�����w�說�C���@Bk��f���t���L�%��&�2�&��$]�2G�=^��� lE�.c�����e	!DT@<�.C3���+�90k1,�&�f�q�i�kf�EQ_?�C�}����c�0�6kB=�f��4_��J�Z�2�o�����Mg�"""�MB���"���ɭzV�d5��OV�P�bC��˟'sz�Y�-�l>�yɼ�1�����R���d��rS�ۄ�s�/ [ǐH�=(�la~���EHaV�m�aӑ �od#��'�yba���Om?���>�\�����<�߭�EJ�i9�|տ�B��0u-�'�S3��ᅢ�f���W���O�	�c+��Ѵd�J#m��lo�7�V��B��vj�O�N?��s��L+��[�q�(*H	�RjCz�a��o��[���R�:�l�,�;�m����E��-"w�bBgw���f�	��D��u�Cx��kI�7��A��&}ar]��1���cr�\n�^�B��	�2$,?j���F����@���"�]r-���7��P�5WZ�!���q	ː��OH�-"���a�B,C�.<�䮝���z��d�dɍ����.#��e�%Q�����I�/��S$P��`A�!G���ߍ��,���2����m�n� lŁ<�+9R�F{��y��6�=^&L�%�${⢢Vl39�������#��([�(	����S/R����_nL���������\NE��9E�4A�/�bI6d;�Q���Ojq��x��b���I�o���0��`�CV2]�b�El�%5���r�0�D��΃��G.�2Vf�3o#�+%�C�1w�`ql�!���G�A^%On�Ǻ��]��HD�㑋s	��~ӻX�QeNb.�)�*�2��#��+�3�����9q�Ly\�G.:a�Vi��.S���d	�ܡ b���n'����I�%���f}ݍ��O�"D��?..�x.��Ŗ(�}K㖜ˑ�]�"B�1u`nI�+�9T�Z�'��L� ��y�^g�8/w�^7���9=������R�%)�!���+NFvQ[^	��)I��#;��� !��������<�w�2<�::�a���~FRު�����O�y�!�@����&0?�o�$�CP��EܹK��,S o���#��
'���Q��}	( �$*�QVZd7�y.���VT��@��!��2��Uw�Tq
��i���!�M��T��e��8y�1ɛ-����U�_t-����O=��#�_!�Et��|	�)@�5�{��@�%',�*�F!ũ����e8m��\*U ��:�Y��'\�YQ.QΘ�N.�^h�����ld�e'�6��V_��t�U�Ege����kF��o3�4չ=�7���(4���*�8&�����0�}���Ǣt ��oV<&� �mA��{[���|
38R�^��;o�_�"#�_�`�{~��}ɬ�#+�ȑ0i��(a��Mfɓ����?bZ_�a�oi�(��>��!^)�uoG�+hlV3�5�)�!�`вζ��u�Ӯ�ʆ4�C["�0�1��u��Tׯ���5�{���AûQm���>d��l��	0&�vĚ�.YȎV�n�����@�BT��d��"!B��`X���<�+��
s.qx;�給�:�سo4���$@�Fy"�0C�� ��k�,?dj\�IH	��1(]��Ȳ�?JX��I�B�T�^��t�A�����|ҙ�$q�2�;Ou?��NG}ג<�
B�Xv+�YO�U��tC��	�r�B?b|�[��؈-A}�� �	_�Jg�Z�		�rB�~�f%�]n���Ӫ@�[�,"�LY���δ�h�
��"������1�4O�]��u��rR��1$��"(~1����I�t�9Q�0�Ok�
���Me����ʿ���������'�u��O{jF0n�`��H�d������.�@������Q���U��u�eg������dC.�7eUc��}���a�����w��s�VuW���7���	��Z�r�|Xu��%ʍ��ǹ��V��T6��?&���b	0;@V�X�Er�і�9�z+8
���|�u�IId��\��i&�6A�?��>gu�:�x��7$��[2�)C8M��&z���,vc������D�\U�X�����謒-X�`D�O���]y-����,���;\�m�ӮX+ʡ|ZN�]�]%�ZzJ�hUB�Z�w��
�*ae��V�����j�M49>�f�ӭ�W�fX���Da�u�b{wC����&�V��.j�+̲#aeɜ��Kˎ$̯+�c�7�w8e�c[ZQ���!Q.�\d�A+���S:@]#PX����WKK��&��B�����,������2�-�!�l�^|.����i�K#�e��`�����?3h�G�t�0�<��wsǑ�0�Wcv�i|�)g4"*�y��4�uj�e���&��S��FD�p��N����0I����)8���u�XW�Lt~��������Dm��w���n����D��Am�/��$�h7�ϕH��O�-(CI��-�vy�~��::!v��Q~v�L��nm\d}�͇ l�d���
/�	w;�#����P{�Z�r���+N��OyA�}��]EoЮ �%
��K��bDo��b��@�>׌1��U�CU�J*�	=A�,�a-���'�N�H�6(��7�_�y�A6<�>������ �p᷺@~T�N��#�ӛ'|�K�> 	s���9�o��(ϕ�Me�B��n\�?�4��샺Շw�]k�6���6�	����bR����ś��Ѩ^.�:��%��Bo=m���"F6��j�촞H�j�~,�%V���7�N)�*�2�C�p�������f���bx{ -kڈM�-� 6!n5l�)ڟi9pC��?A�OR�����?�k�*�+�=w_����?�VH��qt��*,H���uKy���/��h��������n�A�4��[lZ݃�����!�-��^���4h�\Ǿ���^EY6�<
�HlU������;��+��B����l׺,�V��/�UF����nDnݖq����@c��Z��.~)����h�%�8'�����S<���)/1	�ŶA�y~�*�򇖖-vW������<��\�|iv�G��0����H)V�F��cr.g��m�����a!E��憙� �ɂ�|�$��{��rY�$�+�9�=��@�۱/�߳�!Y��r��O[�cUi�Q[���D�
d��e�ѓW�P+���GyzS{�u�ɐ����o1��G�)˲�%�*�jXb����)���o�y�}k�/��X����X)�ֵ��� �����ay��i�xu(����}�Øo͵��H�m�V���D�Z/Ȃ&I��
�r>����+~4���ǔ\.�(atj|}�$���T��&��O���1��U�����:H��i�SN�?}�.?��J.��l3�q���礃�a�m��b¿},��8�&���QYC�.�&t�MVDv�y��_�X`W^j6(ǲs�	���/�{�w�:��������e�]`���	w�'\�T�W�B{�E�Y����.='�X4>2ah��I�QȭV�X�����6��L3^���Dq	����rE7���j�&��?�( ��&d��-n��5-u�w��2j5��Ӈ�2�d��U降��#�׸�?b/ٿb=�)���#�nV�y���:@��X'g��'a^p/�ȐuI٩M���O����xB�Yp�(���z]���䙣&{��rkB$�|@ކ'p�� N"E� �Q�z:���݁�}�x!3uG-+�t�F���|�%a��AL�֊��/�&ܯ5���	�h��o&�c8,2&B�DǷ_�?9����&�·(���y`���pw��[L}��@>g�z�k�A�3\�;k�C6/��R��_�'^��kB����T�z����3^��5Sǯ���$Nڶ�	�_ �0-��h�i�}h�h7������F�eX�UX�r�'�wI)4=P�p!�*>��A�8�VW��o�=r��x#��:���`o6��S������c$:�D��f�Jw:�=�o�=�l�}��H�k���M�-x�:8k�ځ۝K{*����]γ�[X��lA!�-� T�m9�}E�Px@6`�̚�W�L��h���Mό�؅&�p�8�>�c���j?T_��TN��qT��緤G[ya�M�,�����d�`���n�78劌��
a��Ȗȱ�Iln�\��}	c��q�O�����kҵ������ӯgx���N�xup?�[Z�fP�ms�����g�������;!�h#��f��~+}+L�Fv�D(q�v�}�^�음T���;��]���ȫ3�HL��6�a�����vA���U(�e��Q�f���l´cP��ۄ@_���0��d��nqg�f"b�}�)�Z�T�ݡw�Qj� �����D��m"y�>� �2�Cb�_3�W�&���� \�L��Y�8���A��k6e4#���զ���vWVө!-��#!�J��E\����m��	�1e$�a�9D����^��4��ߒe�!%�r��B�mD`R�Ǎx�e�ʛ����p2	�p*��Y��J���A�1��`�iD���*�/��❭v����I`e�+���1���S�Q,�SQf�Ht�lp��IYU'���8��s��g��# �+�ƑM�1�|�uJb?́�5�ܢ��
���}�x#!�㠾H.��
����NY�y`^��E�s>����e�,S!ͻ����C���zg�x�Bp������6��Jq���=��	iM:_�/O���"��>��ma�ĥ�h4E���Z��N��H�х��f�����c���y�H��� ym	����'��l��\	�5(B���;�_�!�`Đ 1���
,7�YN@"���UerJ�:D%9�Ͳi½J5cl *;6���Q��4}���D���d�@�L�d��-�,��$�%�������K0�2�uMB?�R���i
z+�z�M�+?m�|��Pvr�ু\�[�����Z}��%����e���]ճNҚ#p��� �L�Ԛ��&��|��OK�me�W;x'��O��IK�f��y=�`�e�D_�u6t�z%.a��) �h�0�s>З���ͪ��ӭf��i�����;�K���![y��>7�/��ϲx���ޖ��'��#��C �*Z"6�������"?d�Az���
II�]��E̎��Ӂ�ƌ���:��}*�0�`���`�ȄV��6R��ȕC�>�� fh�ۚw2"��ܛ^��wj���Ѽ��o l�9;%���*�f�-��r�,��h�մ�����k�p��A� �?�\|��ɺ�_u� ���3ʹ��-7Fy�N���U�)]�-Cn�l#ɇ�'�݂e�)[ba�.����~�9�;#�@ƳyyC�۴A���+�;UN�����\�^C��ݮ����fUޓ�E$��wq�c�
�U������Z� �ԏt�-�T�t�2���D�X�Ei�Krw�ь��f���Z�{�����K�k��x�la��hTc2����斅Ј����*,>T��������Gf��T�o��!k�n�,�b��:����%��*B��-�[�:w��o�eI�y��*��Bܐ�,�nkz?C5������Eݵ�R1���n��[�9$v��"y]�ܩg�B�N؀�!?c�Lp�l� �x����
)P�j;8�9xjp� ��?W��LV�u)G-�uM!���#�j��Gܒ��`:hd���S0Z�R�}{b�WL}�g1{]"�aE��̝�'���yq��x�P��Y�N��C����x����l?̤P�  ���cO�X�4�+���\`�EQ�w,1Y/В������	%��� j������ ipA�R� 8|� �ǵ���V*C�3W��b�� D�yp�3�Nh��/�W��0����䍀*���m�<h��m7��n�����Hg��0�ּ���_6�*~�K��ov��o���<�[�����f�{��ʯ�.:y{]��Ѿ}u���p�D�\\h���R��Ů/\���Ϫ�Iz����Q�sַ�+=U����-�ΕE�T��w�5��
?�x������e}���_���A&s��sv�b�g�K�;�~��ZG�_�4�������/1x��L���s�NN'Ϛ�Ù�pPtf+��q�~�^�/�Ha/��2Ξײ��e��+퍄=����Ќ+ﺪ���l��<\�����X9����������9}�Џ>W��H�>zuz�ߦ���<���q��q�h+�����D|?Z�j@�m�3���ۘ,7�F�*'��n�B�tI�����#��4����H��l��K sk�%3zV]�98S��F�b�oo'�t�)���oY�?����F>f�o,];[��߄��/�o���?o�,'_P@Dt��F��t��7ŭN��;�P��qh����oYn`��h �CJ�:����Lm��Ƭ����i9{��T������V�4#[q�C�JbV-'���*{*_�p�ȫC�MVO��X"�T��W��׋�Q��vc*[8ߐ�l�/�=B 0?Քmh�gX8gM�O��?������!C�%�b���A�����Hݝ9Q����Z�O�K�8�s �l"��{H�t�0Pi�t�l�_�Ա$7
���R}G�-�wG��������`� ؔ��},a�,�0�Hǆ�u�\������!c�$3���~'�@6�NKÍ4���J�k�H�X��T�Y��V�*uY���R� y�� ��[���R����K�r�9�1H
��p������D��ľ�$xǜ�@BgR�'8`qc�,,�P!��1HG�\G�����ȎM���U@DȁƭK�jj�ԭn�m��^A�{�����wr�ӺV��&VT��C�܅T�y��1v����:��x��4MvS+v�	��Iq�]�!����e�m�ȪP�7��]BD'`��N�3��j&�H���$�3a':=i���d�`�SخkE4ݍ�,�r��$	W�%��L�(lz�Bg%ȫi�e��IҖl�7�<W�F�[m �p��z#R�G%��	N��,hH�Ղ6t�����4��Y)v��w�	S#i-#\5�I�H�bu���P��,�,��)tͫCe�%9����[�Rq�m1�w��@Y���#v�A�A�OCi��
�P��u��@�����=)
�|�J��T)�m�X�>�R��+�<:(gc�\��/�7��UR��%Y��>DVP�S����\NJ2�e����~ �am��0�`{P���`v\G�ry�ǐ�w`>Q��8Wn�<
fǖ�s��c�q�� %m��D�9�̢��VLM��/������˔M��?\9à�X^��Fw۲kI����G��gx�-*�ǚo- _��#������pu���$���S�<��W�˙OIu�S�tp�/��^ҿ��1�V�R����_�����㆘#��$
Q�۵
	O��l��=;��Ax��#�Sݤ~��9|�gP��6�v�N��<iX�&2m@;��� r���<��e��d(��)�cMe���$Ro7��eI�Bɀ![��]v��\q}�Ȧ��.`� T�s�[\<�N�AfB�{�Q�ѵ����4�'q�:]��L�+�4ϯ��܌ �9d�m��
cHs�\���d]�-�[��-�՚�DL��[��g.wD����#��)M��<T���U�)p�N�zƋ#"��9Y��W�ci�qs�g�9>�Q�&��F����~W���4Wn��q. ,��K�����*�4W̲�R�C���'�3ZZC��q 8�]xP����mג���^\������j!��U+������Ħ���r���%���C��lhV�[$+�����~��.�q~�*��\��iUͣ�ݑ�@8v
���d+璮B�������l���pC���
�r�N�n���9Ǘ(U��C�CVu�(�ꢱ��qvGH���Ъ�*ߥ��F��U4~��F9��D�=WJi�X�U��w�Tï�	�f/b|P�� 6q
�D@�s�/�T!�=�!�!q��4$�K�1��n4��oY�l7�b��G�M�۠b�j؈?8�~�L��r6*�SK
Ƒ��h��A�������=��x���c����?X���:�s��]��Z�r>Ӳ�g�n~�n>�nN=� ׅ��hZG1��;`�k�w�����%��!��Qi����[��YW��������7��D��Y���S�x��c~.K"��J��:�-�DG��#��p�ka{�J�-�$�+rŢ��~BQ�C�x��h4O��"lK��sϔ����;���Mm���S#t�R'�v�w�`B]��Z�1��$8yQ��-��5|tܲw���2�Iy?U9�9�ļ�s�Iu�,ڠ�H�Y�p+H�b`��ɮ&��n���?$[������J�ODE�G���ۡKT���',�6��B��<5��IS#�[EhdFY����Y��X[6Og�'I���>�$�1��c�1FEI��9�վ߫�`nhb�>Rؿ��/U�(��&�څd�
��*{gk���{��Bz��(5T�2LL�JV�����(��m;����D!�A2�A�P�F�"�~�2�7����%�EIDC��^��$�����?���j���<_���_¬�m�4��q��kA�-dΣ�[��BAmW�6�[7j�z<�"$���e�E;��1{F�([�(U"?���G6Y!Z�k8�z�'kI�Daec,��luVD~��7l�9�f�rqk�D��"�ߓ���qG����Egꔸ�*�\��%��h.�FTc�FΙE��l7	����у`˚�6e���%za_r�Ȋ�fR �2���E	7�2Te��,�K��#�g'=��8+Ql����R��!�w&= ��{
�of6�Lb�ʪ�d*��D5��V5I,}��(w!���q g��kiQ�-M�h������L����$�3tV���R��a��:�c )�pND�odU��7w�N=p� �+�c�����Q&�OL7��D��9"�j�%����B�4��u�����NP����[�Ke�Y���T/�^M���J�0�_���R�:[2`��]b	�v��^`�kH����v��OX0:�2'��*k�����B������]��񟐦���N�?�*��O���a>g1mzC�l��ٱ�lW>g$^�a�'m]H{fy�??g|Z����u�����{�����'�w���,ޓ>�b\�C��;\��*��@����Q<�7����]J��W�����O��GF�xg�g/3����g�vӏ�B�i��s�)�[��o���#?�_����z�a��ݷ�?_��0�||����>�i���}�?[��3XGlK�D�l$	�5x�e\$a�h�����|v��)��	���?��n���G��gNK��W��n�5M�9�_w|8r���r`'�����؞p#U�m��D� [G��&�-a�{O��#�e'�Im	t��@���k�K�Hy�ܑ�<(؏?z��x����Q��0����ܙr>"YP�ﱘH����A�>r>���nZ���	Do��U�؛�>��mh��nj�w _�)UfI�g�OJ�����Tiװ3�>(ot�hC#�ZtB��ͭ:p~��	|�)��{QPj�0��[� ౶�]�l���Y���e�5�Dt1A@�k�
������?r	���鿌F@���ۇ�|�~:s����@�d��(�%Q���"atM�6��n�@^Pr�+���.��{V���=���/*��� �p�k�/��1Ow�|�Yy/��a������i&� 	i�n������YÞ��^
��|^da�/&��L+��$<\V���V�a���QJ���[���f�:;$M���K�'�|� 6T�
a0�+�dot<:���i��*���K_[;wF�N��V���b���ep�r<�|�v�t�l�V
�k+�����*�E'��i���NaH1>���!�3��Q�R��eS�Q����mͥ &��=A6�(<�%�(�)��ͷq0n�@��p�V}�l�`���L�2�%�C���A#t��ȓ��\���T��4g��"̩�ȕʂ�VNO�7�j��|7�8��/���By �Dp�=0!��q�^5k�&���z㓂�,�g�^��jS�s�z@H���9h�������H7��e O ?b \�`�yh�&#r��	3|g�DvU�_v�lYD\��^g�y�2]ܙa��'
C{5�;% �3�<PQf<ȐtZxp�ƞI�$D���V>��I�Z�K�t�IX<��l��QO"��\��9Y�O�&���4r�+��u�7��lzXy� ��u
̣��.���玐u�W�z����P���i���1VPe�v�m�Gh{Zy�@x*I��\��V��J��3�V�;��>����v)�p�V&&�c6֥��U
�u3լ���TjP�VN>Y�J/�;����r�$W*���k��$g�	�:�FmǟY�L*0�^�v�#�3~׸�{"ޤ��t7�5��c(r (�3s�K��m�rҜC��Iw�VE�T^$^w�b�e�p1M��U�����9�8�#��Q�,�Wtk�NA�����^oaN7����n?���p9�?z����\�������-ls6�s��CNNSI:S�!�Tg�yZC0�a�h� ]u����e�ݞ�e3w��3辭. ��%Xg�7_@X2eIv�+�Agʠ�d�z9=ex��"��vP�c�3�g����9�S��.��t�^0�yQ���k�����N���<��Ő�;b�o ��?*˩�������$�(h�p >wX��<�,At�YY��C"�I�Ed�-<��:��o���fU�ij�W�j�VqN�����g�Ԧ�Bi���N@��%){�MUu2 ,��7�o
s�_���z=T�t�����{�����K#`��V�h�!��c�T�IQ�#$iEf�b`ң�ձ�zR� U �z	�C�3(e�9�[�2�� �i~E�"��e� �����u�ڡO��ȭ�f�*h��%QY+��g� \��(뾎xuc�P���HC[~�:Gש񷭃��$�jŖ#c^���O
�:�6�1���?�l��cYԿ�l�틦�CW 	�t��MB}mYy�0ʐ�R�)p�����z#I�S���.��K*G$̲���1��
���Rt���B�Fk�j���(�������l#[Ϸ�n��}[�%6��r 
�@�e����[�S�7�Iq�.�ր�AѬp� �-B��|�T*W0]��zS�����R%F�������Bs�me��:��A���7 d����;sj�O�o�������&�0-�$�(j�89{%�a�CηyOX_�=䙚'z,����v�Qm�Υ�����mC�-�K�i���9F�Q=u��m����<�Wd�h�B:��8�ND�?A���'"Q�_�$D���aa�$��V|�,9�O����S��ѡ�y�MI�	aB�C��4��"j��08o�zN�z6�e��h�*�4�o`4�u<>���O��Y�>n�?��ȐV�f[�P4��	n`D��
�|�⇲��䆜0�o3���JX�����QD#��YY�p�-�X̓�Dn�g3�A��?�׾1�sR��7�|��F��9y#�j�C��ug�an�-t��{��o=�h�W��#��W]{)�vI����I��W����,
|A�j����Zj�\ YV35&���6�X\�RHu�`_���hk��)cJ�s��f�� C���b+x}A�./�͔���P\nZ�lDI"AH�#Iig��h�Hn�Q�F#����	�J��EU� ��/�j�?��u�K��ѿ�)z�[��"�Bok��Fe�?n�4��H�M���:�	GK��f�;���c=6�Q *;�Z��3Fm�=��k�J�,���t��<w��zs)��צ�fJ��)�_ӊjӰV�&L׎\�Q8�?o���^=�zֻ$n��[-���6�d|�\��d�*��$)�����>$q��&�]'�����4�$E�/+�\Xp�kPs��C:X�$Z�y��S������k�A��p��P`/��o��T�3|�AL�x��eOj|��v5�I}}>i2P���)C6���?R��Vi���o,���A�A� /s	wϋ��%`D_��qC�*,rE��Y �il@M&̅�����A
/s���1�p�q[��5S����dآu+��H��ʏHj-��MA�($d���qi���I)CͽV5n�6D$s�^��  7�⧊�&������5Q?�Tb�T��ybm,s����vಠ�UY,"ݖ^���}���}���!�Y�1X|3MS�ݟ���&nӉ7@Z6����:`�z��$~�Ŵ܁t�#�_���B�$���H��/h ��헋Nm�(z�t�� �k��)��0�y)-�f��sa�M�����t�Q#��D#�_�[�kp�>�sN��q��u�l|t�E'6w(o��x�v�u��a��o"�&<�:r��d~��*u�f)���m��9�A��D�H&h�f���Az	�
 �����,��{E��ZG�6��&�tD�_QVT�OyAB��e�}�Ȋf;ŧ����g�]��D�Ĕh)����D#� �+*�#�^EE�f��3no��^WF�֑ݓ�I�?,���.+�Ά�Q�����=����5ݓt����S���yĲ���%��4�����@Q���.~�h:(��b
�{�" �-��4����T�" bMX�律
��4�ֶ����D�0o�����K�� ,,��0O���<�5lai�lٖ�o[Y�I��D�}�ĥ�y
���ov֪���B�8�+TJ0h^�#����&p"H��6$%�x��^��3��][���� 
���a�\���]�6�����1d��@�.UsPt>ܓ������M-��]��7��Qo/��Fs`�#Qc�&J�:�A�hw�chqo����]bugf��Bϰ�R�R��bwG�P����\N�R�O��{:���ti�Q)��b�8X�j$M/"�v3�Jo~d��Fm���6E{�g�]��e� �H-�$g}hv琡�H��@�$<.a��9�*�=��Zt�zy�!Zi����Oʨeq�`H��2�eL��T�mI��JZP˚�ت�y��`�� �4��
{���F�?���tsv���x�[<�����vy��(d{(�ʊ��gkYɰ�������E}�(�%X
/�i�|��C_�`\���am�k}�:�~�h;>�\�zg�W��2�`Gu���}ԧV��,�5�w]~�a.�\�_>gC߱�Y�y���ͺ�󼦣w8�U�8���^?ޱ�5��,� ����9�ҏq�{c[~�r���H�(.��c�h�{�����$0<�e
 ���L�*�);2[T����{�D�|^r��ܽ��M������׉�)%MQ�'�=O�������Ob�1󞅿T<�jq�ͥ��UK�;e�[�2���bP�u�B�t+�j�%M
&�XY�5W��V���У����<Qx���0׬8��fァ�5n�Ohkz�a$���=eгTV����jdEi5:^֣�Z(��RL�
�h\͕�:�#���?�P��>�����ce~G�{�����������t<��!vM>$ǝu/���3��'��_����+J�����L�����vU>,������+���49h���;�p�S��Ol����Is�H������>�'Ak��,�-b�*4�2�>��!��L����/1T�
�L��B�+Tn�*߻x�&._>��(��t��l�\,�6PUׄ�L"I�66�V���q(	����otri������u����8�l��(��p9�'$w��h���u���WN�dL�n����ni�w�4�M�N�$���<�{!��%G���Q�p�瓬z�x�ZX��*���L�LY�M�����=���nq_�F��HƤ�O����{��y;t�,�Fc��O+�D	~��� b�W�V�{�^� �W�=t�?8��������ۗ��^��}�y�߂_�x[\����<_�� AgJ� �:\\*#�6�\
�j����#�����n\�����*��D��9�6�t%A2ٞ1La���i�Պ!~��,���lT�+�),�p����/[<�r`^�a�ĺ�ך�w�T�Z1���c��f����;�p�+%@��\Q<b1�2N|��?89�!�ı���cnL�����<wr�gc����3�֖	��PĕnS�6H����	�(!zܔ�߃��d�u�L�ίj�tޓo$���ݱ�n᲏���ΖdwH� ���<��W���f8[��@~<��1:1	P��������Y&����Z�_�c���47�>�D��T�����eOzϭ��#�G�y�i���vt��:!���"�z\��$m��k\!$��2�F�����&��DE�&9
Y�7{',p��\�%F����,��u['��f6A��m�e�F��*������4����NR��*�_�0�{A��P���O���?�h�����q��qp�
w؇��hww����<v�!�R0<u�m�=���59��ߛ�%��qe��$<�t���*X�iyɾ77��c\V�Jc����dU_�'*��EsL�:��>�&2���1g�����h���+4�*���I�\р|Ԡ[�Z���naEls���e"��\���
{�5G�#��*� O�#2gD��F��@K�D/ZXY��&�[v�NB*�2�g��HxPt��7�"�YyX��.,ٰca�5:�aJ���o��"k�l;�i�?n���#:�n���:D/>t�7Kl�ő����fp-�$�w�7�\1��2�Kr�Ag�����ΪQ7��,;0T�ƒ���^�T:EM�㗕.�燞��#T\X��:�w���^fw�~��y3
�:���Ř8�<j1��Ϳ��^�b��wdS�W��D������N�!+;ѥ�+�њ��N�����L�v�v)U�<H�S$n���`�-)ա�N��pzKGp����n4a��s~���e�U�gq���mt��n+_~8J囵b���"n#݌��:�w���I	<��xI#��!�Ƕ�z��mɖ�@vdI6�������a}S�(H���%ʡxn���J�<b݀�0�+P�:��@��Y�yz�'L$P����	���O������O�r�O���:5(l(���U���»�`�R~�l�4�B��ܷ`��h=� �1��I���"؃�-N��^���QQR��63PP��|ZO���
��R82�m���s��Cp���ƒG�s���I����7?�D�e�S�pX��c\aJ��<]�>.�\��t/�u"m� FexX(��K:���#��ld�X�t�Wy^#J��Un 6�8"zEWI�PUհq-%L�91��#�o�79}�ƞ#���yׅY�Rk�C¼
l��+��7ᗧo�n!�R8Dϴs�?�;�	�������4��ؿ7��9�׋d]�ߔ܋�)K �}���\�����q	�����Ǆ�
��B��.�S?��-���/Vm(�׷���W���'�p� ̃�b�)aM�����D'��t�H^������$(UU�� ���C��q�c,L[i��b=����A�q��y83i�pH���E�,ڕ�)=�J����}�����#|AД�� ���.��lF�sH��?5�y�f(���'e���0�	��~�4n����Δ�����<�,<|֔��;�9'J�L��]=�6�#Om;�� �*0.������%����;M����A��MB�Ĥ����?E������Dv8�%$��h�S��:�����\>�g35B�,򕃴4�'��[]W>)V�e1,\��1��c��H�yG����w�;>��h���#���L9N�(�B���UF�i\�1�`�����1֐X�4��(��t�|d���!d8|P��Ƌ�__4G��X���I���E�?��X�Awȇ��I�ۑ7	�s.�8&6��Q׷��8��>qo֪�mT&�_��9�b��t�A�����s$����q�c4�6-?b42�ɜ1�����C?ҧ�"$ҽ�*����0$B��1��*_���
9oĊ�)���#��jcl��4~� �X�vr�s������B�5����ƛmJ���ѕH�Uɣ��r{�BS��ņ~{�#9JGٴ�CBa�o�/3��Un��o+;{8~ a�O���0�+<�?�����H���P����4i��l��0���`Ӭv��/ ��A:M�H����5���0�ɣ���m>���A�C˃��l�8]d�<�`��`$=N(���Q��o�RS��(b����.��^���x�<<Z�S�uW�瓓g�	���@��`s ��P.��*"-7}���ƅ09��0ǖ�� �i[0���$h�m��0�)��RYu�\������8�G����w���>Ȼ/��d���S�Y��O�	�: ��p<@A��dn�(Ӎf� w��K�qt�=���Np��cYƍ��:�3=���8۪��=�ppH	<Г��Rs�ƶ�L�A�P�@NB��֝�:�1.9��>�$7����^k�mɇP��x[p	|�a��R�ُ�^�mа)�Ӈ��Hkc죔��������)�52�b�C�
�c���%�}��;�r�7e����ַ�/������.�V	<�ِ�\N��g�C.��A.�lM�v��Y$ax��(��8�n�A=��.�����M�d|���If�Jݨqw�1zS��O�::���v��a���Q!�
��Rl����b����U�E5�C�
k�z7g)B�1�0o�еN�Rc��Fnu8�"<�Q��F��@�2 ���������e9��|�r�t���z�{�kw�����S��,�Z���ñ�'�毫�6���p���XK�]�A�}Qd��j~G�9�b5����r�s�ۃb@�k��ѳE�:J��}�g�,wڙ�Zx�:y�b��v�9pKk�;%�w�Kc�YI�j�ׁXɆ�/�~�ו42���?ť�3�8��?������ÃSbtٝ	�0W��r-�$���=�!���3��3���^�D��;�&�^��%U��A�ٱә�m3_=H\|���[��q�ؕ�<�U��3����מ��������?�S�X�L�á J�rz �gX�<�4���8���]���׺��/1^|=����?�����5�܁�LWS_g�R�Ğ$��8l�9�@�4.jg��P�vz�eF��=�h�],�3��3q����f�<�(鹋�}'�C=�g��(��4���h�X;�/� ;�N��j�ۿ|��|ݑ P,��odMt��i�� /�H����e���g!5������}�j�(���L\?�"���q�a�P�w/]�i׋�(\����߁6��'�rms�r\�XR���;�#b;��t^}� ��Qd�+��g ��x�-H@t�C�L ���-H�c��8}��v��Bk�������7���1%�*#��8,��P9`N�ԉ�4$�2pd�p&��?��4D����D�.8l��<�\�`���Ġ%�����Ǩ��N�l-+h5��S�m	��&�t4O��k�6IJ=���6�����-#sd׬>�x���Fn湵p���%Z�O�2Q��A�C&gvՈ�֕D+L�9��t���|8>��V�+���3�������䤛��XQ��%g"GK���!5�e6+GXGV�&'�4쉋�����4�}�4���e����y6�D�¬��N�h�.񔼎;.د��IMÃ�Ye0�-�����>�o���tM�x�I'H�|� bO냝2� '�%ԉ~�b<�<rĴ�l�JY+m��H] LXms��Ko8)���)���=�=Ly/R:�o��X�ʪ"Ժ�yHz�s��>�,#}��c��Ȅ�9%�~E����GT&S#Ф�v�[��c�^�:��PgɌ0���,�7j���U�� b�K����r�3w�s��;�LY��e�һ\��4e�NKS~�yS�,[M��݁�܈�`�"���y�)a�_�� "��{�6jh�
,60�<ӡ�c! ��.))R�2�b�p���Y�L��!rڗ���D��0#�x���5�/�m�٠����t�{>�����;�wv��-T��} ����4��O���:�-����`)q�kx=�F6��'�@B��G�R�z��S��4��~��P�Ѝ�I�SѼ�����<���Xw�(�8&a����mf*u+ �m�z��K$��eH"v��ʇz+x��G���V@����?+ĕ;�4'nb��6HRMbJ���B���r�S r��{�r�$��Tx���D�J�����[��u
+��BK"���Ԗ达�B�d.yNV�`(f�0���i�R���!^��)�\�4�W�e�~�Q"�dCv@?{ja�n(!P'����H�D)aE�Z�X'@�v��jF��Yo�������A[�^������p���ڠ��p��X8J�"+��gjפ�W�L��J�JU��@Q���Z���I�f��P�����]�� ��p@�:�Q!�/!��Ra��y:qf
B�-Mg�
4JM�q I���y>{(���n�H{�%�s�RNTi���Xۯ�R=[���|}C��C��.�$7W)gn!�Kv�Jd3����%��&s2�a��|�c�u`I��C���QU8N�������Fd��MȤa�f�B��t���F��ø��v�l��� �V���� ѡ=���h(L{pT�+q���'�[H@�	���n���e�R��(�cb��C���[dQk �GŹ�وd���\y�6j;:Q���O�Zڶ+ۙ2�E�Xj�Lƥc2�.�?��|LU\�C?"|Z$Hsێ?Q�,�'N-R�� ��:ۖrA7c��,�S-�@R��Бg�߮���63�)t.�ёq_$�;k�(u=g�����-��Z��m�;~�#. �u3��Kx�yj�)5��DK �2�M���P�Z�:�1�4Tb oU��]�����!'�4����!�V?z�X[��'��S�n��u!n��k���������8}��W(-5\8����A7�f'�J}~���0
9 ���w���	�������X~:XtD����k���"��@F���:��n��8�m 7������GwF�R�����8�a.w�����J଱�5%��\RIV���7E�Ltz��4B��pT/1��!6R�N�ľ�W��|��CaNX������+c��d\�W=�/��i6{���kR��&̢M6d[�[Z��I�Oq�~ʴ�M�� �XO�]�\��7��p��N�&H�}E�Ĩ�@n���r���]_�+�X����5��S�{������	0L:�l���=��r d{�@b�]�!:����b�v8�����n�W�c�`)�i	ۊ��ʶ�-�-7G�v�D��#ڞ��!u�f�$J)	�2d���%��{��;�c
�S��s�)��p (�Ô&N����.鉚��?�bؚ^~�/���� y�PkS^��P�vgF��cj�4l�g���y���X��r�a%�H�6x9�?�	�`ֿu��1��3����Aq&t	䢑"x��dj�ִg:�ŶV�^%�R��D�ޚ�)�;��rYk6O�D��gF����*����v�پ����J������M�f�"B��?9���)V�x����	 ��,�!>[���@kj=k����9a�~f��s�������W�+��Q���:��؈͕��Z�՞+5f���IY�����ӎ�u��yz�J�1a��DIK�k�Q��"U����|"�X�؅>ܧk�K�P��!���QF��f�@�Avڌ|b\p����fR?��>�+;��g��A1��4��Vzg������ @w���7Q�oJ.֙@5
-ǱȪ0��9{�d��)�1�@T e�ɔLq������Њ�Ta��ږA6ˠ>D�L�`�x�X�]�rx���m�<�����K|2;ئbp}4?�5x)���W��ἽC�f�{��v?dڌ��f�foܣn*Zo���\��9v�)0r3uw�A�Ψ����VX(2t2����Ϯm�r9It������i�_r����;�&br2/i�P��Aki��h��أ��>��/������m�h�eaZ��RxԿP(�4+�ר����.-T�a҄Z�Z�Q�@�J��ٶ6�,*����A���,S�H�*���u"�m8�UY����|K@s�代�қ�<US�~!h2î9��;�\�_(��L�t�df\�aO�h>��iu��tt��C8�=P)w�dи������32��! �4�%'�k�P~���<�r��!� �"�}�����Q��YQ;�]��e��՟�ғ5vѐU:&is� hSTe��t��unĊ\�E�va�@K:qc/��0*Tჸ��,����$�x�a��� 4�$Pk���؈�!kn��O�[k�6���RYȚԀ�%��?��k��G@�����|�omɞ�1Sh!6! ����#^���H<���(���`��:��5C¼�����x>��礔�ҏ�&�y��7��$�(��BB�<��
n@�#)� @�Ǒ�,:����w!B^0��g�L2q�jɩf_f M�4r
p�}��% L~#m����gU���G��9B���f&D��Wg���X~� �p�*+29�FSq��+9ɫ�hd,G_��S���bO�}dg���E����5S���~���,:\j�e���8ayx����;�l4$��\��op����{@�>�6���!Hg�؅�r�W��1Yƈ�ɪ��xҍ�1}�B�%E�I�� ��\�I�C�_�������ކ��g);<n����&ٗ�!�V�%�|,��!�}��%����Z�@��-#���D�Pcm���SZ����k��쬇� �6�)�hjYI~�Q���Qmg�_Y��~�?�3�.h����.�E�@�O�Ѷ��:�[#r�`j�pq����#��L��yܗ�~�|�F���Y�Ȍ���=S%G�'J7��q���uX�B������]y3�f�o�۟�L{�PE�� ��R�|Y���u��S��/K��m�"<ώNq#�2��Ћ��W�����ܾ�r2��<YwEΑ0���=����Gle?"Ą�9#��/���i� �:d����!S�D�%�oK*`k�Ȃc~ˡDu2�?H2�ֹ���&���x�bT�7󈼮�x�%� *�I⪢M����i8�e:#���8�����g�d�� ���$�=vf����0_�Q���*˖yF�,Gp���0�UF���	��V*/�AϠ׉�FC�_��L׃���"��y��C�g�R�6zz�3>u<���(��Tk�U�j��6w�_�w8}��&/pGd	k�|TL���^�>����F��'�V5�Bv�7�}n@�YmA6��s<bֲ7����ġ�b+?n7����)�NSR���r��
}�����q2��]�>j�asY��9��S�9 ��02 ؤ$%	Mdt�a�O{��C4,CX%UX�P΀t����F7�5[�vrJ`�c�`
��S�����q�)l
�CZ��8�j��Q��MdRt��P������)�����Ɨ0�G�]If�^��`�F����?`_4����÷@����_���<�k�UO ��)8���Zݘ���<��V�lI�5с�@�"������)EN�$+[\���U�.24����ȅ"�&�J9���	`��p{ͱYǲ�	u�"|�Jb�|
�xӌ��L{:�f<1؜Ja�AM)���<+�y{��&<��J梶7 ���W ��v"��R^�T� ��[��Ayz��C���Ң��mN+�����_�S,(�&y\W�-��v���/�=p��3��e��|����NBKHѠ�����`Ѳd+�a�V-HV7�cYy{k�,e����<&Lcgo��A��
��'���O�>�wuw�f���m&l��0��<�,�(L�p�pd���#��ݬ*�Q~�H�����̑������/��#_Ă�x�_,��C,(-��L'��qy�!1�=*h^�*f���9��(�!��n�$ۋ�S�벬_���cu�+u�\�~ǚ���wk0e1���,���m��dC��=�h{�Ϙ-2��]D_"	3p��B�1_)��!n�\��@Ma�fk�,S��S���`B��C5}��<[T����1>�4�+����������6 �<����N��/��t�Qx��i�a[kAT�����?}�ɤ�95 �_qr�u��dt=K��_��\���\ݦ��)�	T���$;�5G1�_ 7��YO�s��@��7��ѭ��*�
�����t%
��c�s?�@l(����%�.�͗[ϻΧ�J�[���Ev!��9� AsG�����=�V'��zT9�@�U|Z�J0�T��}�y�!�&�7a��Ț(w@��U��:�`��F)�|��n�H�.��\#������q���O$��@W�Į�3���/bi+4uJ	�:����	�,��&�`���8���A�� >ʢ��M\��dz;��p/��Q�}0	|��=�����oce=�����;#<)ז��ċ��ySMj*��i�� >#/1�;�唕�MDe.c?��d�8���w�MV�hMp����$J�h��Pa�U�����+kW�h�-�~\Z4�K�H];�Q�&,�����z�_b�Ǒc\�Iʻ<�qT�Zd/\s?1��M������E"t���3d�p��rM�E|C����K!��9�wi=���rmP]f��.u;���j�����xr��d�ۤ�8j2�=>2�\�F���J˪�	n��Y��Q�<{��i������ ��!oqf�+�	ω��%��W1�bR_��.vl��Y���(��@� b�����)~�!	s���z.�\R�X�O�do��{f�����Xɟ���-���O�\�s��H�7]� �me�|ߗ��p�:�}X/L���� :�W ���aF�:v��%�x�4|u��Y��&J�;}��}"�.Z�F���V ��u�.��g�[�J�9��𔛴 ���X] j�7>t�l��,�("~�F�����R�
�il���5�d���C�Rט�Fu��(��I;�S���{``��>�%N�Ҥ���8����iܣ׼Ñ����x��������w�(j���I�7g��=X�\�R+�[U}$s2=��u���W��y�ܤ�EJ��z��r��-0�kW��xءH�7�s
��X�.m��Rd�)��6�(K/���a�B�����e�+���Ww{ny�T)K_m�=ʸ"�ID;���2S�!�N�Y^*
њ)�'���h�@�@�>����Q�a�Odd[��l�E:��R,�W��'33���E�>P�:��! a���߰ ����Ŏ��#X�X��� ��z^$�"![
ՙ�٥��\n�Z�q*)��Q���c�F�*5>�{kLIo�./v�w'�'���Q٬%5dn;<��h�ק����aAq	���I��G�k�������*�~����(����gl*=�x�?��9��V*����%eZ�]��e����ةmg�c,j������'���e�\=zJ*,J����D4S��c��c����<pܧ��a�?��A
!?}�i�!�kO+��S1��P����x�F��#��x�ʖ�?Y�O{�|���8���xd�B7_�G��iY�:��P| &�`��9��e\��UW�aU/�D�v��0�| �a��i����Kl�ֱ��NJ��"۔u�D��Y����7<��		�Y��K�2W�0�4�����1{�h�<(|�m�����&Zx�ja(t]9�!�%-bd���R�6�tq<0���m���P�\|�T����c�dS16��ݷ����@=���Nݦ�Q�ʀ�Μs��M�p��X�R��< ��xA���ڈ���M$4v�{
���ʧ�	
�� ��S��CHݏ�:��m������Z۵샨�S����$��A�(�ߘr>:��OR�^(n�km�:p8f��)�M�J ����ߤݗ�y����|vJ�n���R������������TjQTo7�xE�"?e�z��(z�GH�c�
M����f�N�R���ۘ���ptTb�udNl�&�k
c 	��T]�|�'�1�ο��j�$����^�O��ò|[u�]������H��v�r���1-�`K��{S��O?�c�����zƓ��a����8���{��f"�r9�@z�5?�����V�΁n�:�Hᝳ���+u�v�=~�P�Fe� �-��H��@���Z��6��m���N�YN��t��w�z��������~9��� C�s� ����³�=T���������������5���~@ck=N�ڬ��h�� Hd�%��<h���'����x�*6��~����N��c��B���B�g���G9�<8�rp��Ay!@��g�}!h�9B��f:	���9���2�j�@3Z���1���s�r�4L� ^
Txt�
UO�E'<�u�}� 쨺�1�ibg�W'Lm���Z]�ͧ^5'�21��6�з��
7�gnl�ڨ�c��b $�a�@��:0��Q�o�6��6�{n���@��b"]ɡ�U�0��/��:�o�p��y O{ß�U7�F����¬�eTl��%C��O8?WyҽZ�U[��X�zo�#���֫�t�6ɐz���S���L�3L6���ɉ,�a3�Q�����y���U<���|�;ne5H�$�,�C,U?�ϻ�U�ݻO��k�X~?��u�$տXvG��
 �Ө�ˡ3�h� !��U!�jHO�f[��>g�d}#��ae->�Z�k���
'P=����k�=�X����Ꞁ._饅�Z)�b�#ځLo�\���w�oˍ����`�M�{:�N�A*�2Xu�W�E�y����Կ�~6=rv��u�wǨu��0Jai,
�*���9�kJ�&�J�.���m�{��ͫ�̠��@<�ޏ�Xԭ��9*7/#��A��Ј�T�ó�M�_`s��7��M7�2�\j���h�"�)���p���t��+�{��k�6Yr�}3�k�.]:9��������Kw!-���͜2OPjM��ޞ�|�@���Jy�����<A����l1�%���8���ظ73�U4��
�(�S���ԯǸDv��,��l��?�g풙HLXͦ�ڎb2��*�ߓ;� n��I`$�HE�K�<T<�#.wl偂��-*��ծwUĹ���I�QH�
y�e��J"cGx_8�lG�C�2G2��Ȍ��FC�5��M��u� ���Y��!7�_ty �;�nX���h��EX������~��ŏ�����ٗ���0��N"K���g������[-�w?V���W��ڃ<�8�s�<9l/�����D��y���~�{�#0�cT.��g:(^PVO����~ώZ-s�[��b+Q:�t�itGT������x�Ek5��l��M�h��X��:XQ�k��n�f_ވI��X1�2�6&":GeB������{A�"V�H �]�_�m��&��p���֖���Uu`F��䊕Ga�$ Y�w�-�
������- |g�����б�F�w���Xퟣ�C������^b��h�@�A���
�[y����+��f�/���Ӆ�~[0�*t��qkE���Im�+}�~.�R1������o"�:����h_ ���~jQp���`rR�p{��� �*���yj�f�(ß�;��,�ގ[��������sg�x��v���c��p%�љ��3s�<�\�X�WU~B�"�Cf<�ː�L��?�z���v�Q8G�y���<fܜ�jL��FBN��>(������X�Yg��X t��YBc��9�`��9˜9o�7�o�����Y���
�k/ �g��X�3Ǯ=0�2P��_y�� |� eސ�r�.��0��[��\9���Yx�w������k����	%�%&�E�H�겡^~�	�r�2�8�"� O! y.8�b��R��s�.13�zd�+|�!��Ԅ� �����Ce<��D_�r9?|&F�R N.'����5G���[,z�[W�N�Ӷ5vGC�K��H�[37O����,���c��`����]�`��T�Z_��'q�����4�`ǆ�ɗ�{.G Ai〻ٺ�P��]a�L��>p���8�$�����l�x�Nq�I`@q�ܲ������峟�C���!gH�a֗�n	|>x�	!\�vs� >��:8ŤrKK�e��lW[�	���6�pU��e��hQ�������K�z>�2TT�iw����ke�r�S�/�>��q+��fK�S;d�����aI�cx��!I!tL�̌�h
Q�Qk��v�1q��_���m�N�����Yc��O+�wLIJ>
����b���+�O-"�� ,��'	b-��uN�x���Gd�|b��2�@���6;��;�K�}p'?���<hT�6z`���&tF��q�|h(��FK�Y	�Li�����B+u�{�#�UqYq�i0|b��9c�i��s9$i��������I-�j��[*>(���w��K�BO���!�74MK����<W�e��;�o��6q����U��&@�޳�)��'�{�����aSxh�����}�(��6ǣ	�`�l$̋{4���u3�c(9�p�= ���=Dk�6�o�0�"O?�~1Q�n�6�
�m�IGX�����KGq�3�-����fNe1�Ƞ�(�:���0�"_��ѿH��*݊,�8�H��\Җ�X���$�>{�����~�%�c>�W���N,����.L�I�"%)j�Y�$̤��Q�z��d�jǄQ�:.iX0q��4<ʸ'�R"G҈�R� �Y�$�j6� �~�P�@���Wt
-�cW��*��yTc�fvS_$t18�h奐��1�술�]8,1'C�g��4�"�El�T�A(Wk�3RG��<�t�Y�Ss1�
�c����U����3�� 娩�]�&�6B���:�va_���ly{��'Q�[Ō'Tԇ�����񨗦1�����сhox��P6k�,�Ƃ0�9��#���A!�- �@pf?t�5��s�t:�(	
�ğ�v���[�!�
u��V]O����2ܣ����1E�8����dϪ$?��aVt��0����9I9�S!���Q�q=�EG��P�6���%�]�u���bi.��n����Z�r�U!��cTw��kI�T��Q��H6���0՝��nF"yn�Ydc�dǕ�| ��q�z���)�^�y�>@�E��z8K�K��{&�mt�/��K�2:�����k+~Nu�t��KW�Ł�SO��g�l�w ��ݙN����xe� ̮K ��t��fW��� ȍ�zw��$�w��|����K�T\�q≘'0�~3���!����8C��f�byF�䨕^���w�\�p������ZM:%����������p�4�TXTw��@X���XU	 ��?�-B��6�4]�р�������;�c��+�2��CZ��7�� ���'��?���6j�Yx�k�7^ ��	��>����+��PR`�#�y㞃�H\L v��y�a��Q�V�Og ��6�];	��j��P���q�֜X���g8C�:8$���m��3ﵜAa�}�6ɌT� ܽ������:L����d@�W��}d7��b��IȪ-_��Qq<#T��Խt��B���$���h�kIR��{���w�#�d�μ,Fx� ���,(�k��7�_��	�F��8��bh��.����D�P����)v� M-Ƙ0b���Sx����bpڤz����?6���@�>��/0�C��*��a�[p^s�b�H{hɰ�źI��ڃ������os�ɇ��'N׫z:������fl$qE�@L�����{�����͔X5�����	��j!�ǂ�Q� ������k��?ۑF�S�Q	F�7&pfvɍm��m���|-x�e���'��
����1Q�����8�\�H>:s���7f���F�}[U�ex�q���� "����b�A
y���l�(�-d{��X���[���Ѫ:�CK�Mq	4G� �FےE��\�\&������o"�P��,\"y�Ⱥ�ڴ��)��[:���¨�q"�����x__T�A��+6y��Lz�u=���0�:e���a��@��й��͜Z� �8�t9p�Vbu�@�=b*E�I �(|5���O�JNj2�M�F���F@��u��Tc���3����] �V��@�Ô�W�!F����Q�⌺����C��ȁ��!�fV���N�K�"�qR�]A`D���>��ȌF��.�|�U�%���䈖���h@�<R��gp	V�4հވai �Yo5��z =�w�D0'ڶ��e%�ל��
����z]�����d)�[�φ_���8Z�A�d����Ɖ��q_6 ��틋[q�I��&���[7Ø�&��Klz��l`;�Nŋ��1ߑ��A�~ێ�X0(�꧆ݘ����J?�`�)�j���F��:��� 7u����ܱ둡��Q�&��Aɉ�@*���uJ(����^@��nR�+�[�*aE ¹ϥ�K�m��Uu�E���	���7�h �wpF	�$�n�Ws	0�-Ye8�עL��&_������&a�
�.	ӥ�1���~�=�i6/
,�Y�u3��<?ʍ���Y�a6:�j�G�Ƒ�~J��I�K���eU�ޡ�ԣֹЇ��=}\�*�>������o���o�r���0]�	c�:z���F�%Q�"I�x��_��j:f�I���½ɐ��	�}	��é�֔��/��q(�niQ�7|x��[1��7|<F.Onh�FvaI���
�/������tU�5�Mv�w��Y�u��\ױH/��v�Z�b4
;!K�
#R����[A.~7�m�.��V)�&� �,0(\��7�&}u���h�Xpe?lr�1ɟ��d�,Q���~�d��Ԭ�^��P6�$S����n#|F�ض���ov�R���%j�/ɰ:�N_4��q'��:�X�K�Bl'Aq�:@%��
|��M�#�W8)!/%�ےa�YP�sL�٬W���i��X	y��%2�
	=�A࿵�._�Y)�mH!Bn��`B��؃
TT��$�Z�����;���k�#в:���&_�ae�@�s��3-O�Z?��\ݢ�����u	�V��=������V)�`�����.s���(�;k�p`;���	�s/Աd�,��y-�OܳeU�$t�D�X�Wí���.�#�uh$x"4L�Xb:-��s��p��*$��<ݚ�X�ݐ/8b�G�_~�C���m�۰�U�K�W������>��J2���a�J}�r��|���X@<�9(��A����/ �yw-�SS�tR���Bv��H�{![Nw/z�4c�tr�E(�X�{ Lޚ��ql�F>��p��KQ?��B���)��锼nON��"����̥���}RW!s���5����p�&�&�d��vґ�X���kpk�Sn�4a���=0E�,r�U�6i��Y��0Sܾ��j�)�C�a����y�S�n`�����{Pt�/�N�������g�	�-��:�W,A�`��NoX������=����f�)�L{J}�G���L��$���l7��x��;���e�m9�b�H�C�Ch�F���n��E�cľ���O��}�/l��h����*^��Y{Cd�I�R�ֹ��w����	��kZ<B�Av���B�:F����U�|EC��@.M�����Lj��г��3��?���S1(��b��F��C���َ?���n�͒'�]&�uL8�C-�<j4-����9��`��Z�4��ǫn���[H��,S����s'�vFB���
IK��{���m�;}���N���԰�HMM��s]���R?�����i=<�SMU��N5^���j�Sa���	��&r�>�����V�=[�O!2�Kъ̌��r`T�ĦP�4i��SC��"�n���� r���-�����硼1u��p�0�|��.0�p��IK_�N!R��4>��p�r��9��D.w"��� @!���Up�@|���� 9`�	�u����zŕ�@�e���&T78N�]>P����3�"L&+����q�o?E���v,���5��	�b�HV]�"
�����E��֧�jnk�/�K�p�s�˘�sጟ��/]6�Q���X�u1T�X�%�يnofrv�/�D)�XH���I���G����^�eTI�U�U�v2g�3p �_�������X�扣��i������%�q��n�q�������y��l�ۙg$������ޮ���3p�jO�|���ey=��C�(����Xӕ��t)����t��i��,u*�3q�P]޾[��ə}ͭ�LV�����褠	jK6����8($oI��e��fG�=��]уB�&90Zi��P�꧁0���E���Dh°!�!qn���xw�$�>+*4p��'���Vn���?��␭q�9T�Kk����;�7�W�t�gn��:�[ �D ?��)�����uV��u��K8ʛ��F9��ݗ௼2�7�t����aQ��n���|��f�i�Bu���lI�?��fkpY_����|ힽ-]�u�G�U��Ji)C9�$��%��͢ȋ��#P7Wll�d��}�D�q�A?�����V��Tξ&w���y�Κʏ6��/e'�/����v���慛�Z����l���4���ZB@�4������Z�����H�ц�? ���{��[XYTF��=Y�e/G}�#�++kW���
���'E��:ח�O]�o��/p��癃�D�7&i�>�>z	u����jq]��S��-ö�����/��ԝ��HHF4�4�]�d_rcI
�j)���C�F���Xގ�-I�񹖵�<��$�4�3�۹�f�`}/]����a���D/����r����&{�5�"2��$����f|�Bb�L�&8'�A���1��-��OQ���s��ϲCjl��83
[�#R�ahqi=��"������*���ͩ���a���E��{;"*��3��SQ��1�3�~ҟM|i��@���|���Z�6���G_��k"�Q�ɃR>���6�s��>�䖓��%+�`��2�`	R1��Z�i������0~��c�D��=���d3��@��8j�,o�C����^�,�jrh@׭���H����0C��������q ^"Ѱ٠^*J�)^�i:GS%��w���|I.�ŕM*�&���$��S���8-mU[��B]�?gcV���>~������㫊7QrH��I�����֬?��E6g���u��|����A4}��R�����՛�`��7�p��H��o�+�!���
۟��A_��؇�7$��u � �>�c���k#��d_ �gE%l�D�]��ߣ�<-8�} q�?=���]�Iz�(`h\� R}\�"bN�橿�Â�$2|��B���-S���M\@�{}c�i�WuyM�(�.��E��S�b�\R>2� 0&�ק5�e	S���� 0-T���?u�����5&A4ѩg;:��S����P 0�ǲ�ڢ�ͦJ�OS��K�Ǘx>o8�P�.����M����Q�G��j�j���䦋m&�`ه�8rE�8�hT��� �3:4,�����Cjkw������m�f����cK"0�:��4ұ�X�Q��ID%�"zTFE�`��݈wBgH�ű
���ޤNA!����TI�Ϊ�'�v���i�@�AVʞ�6��Ӽ�|qN؜8oB.��\FQ�RC�:�m���xxXj@������ vh���wu'�ն�A)����:�d�֙��lZ����9�uЂ�PWξ ��}�tAMt�BM��@��K���u�u��-V��C��<Z}�]S�tU�����@��zM��Ѷ]3�X�b��NO�B��w3�4��BKy(]�cr�m�2�W����V}�]hdE��=6��a���a�i����G���2�j��l�G_��8�7p�_�����吖�8��G�(��x���3$��yo�m�yC�!�s���xG֭|����?�r9g�c>@��y�6N>��{+���� ��^f�y�=��E��{��k� ��S�E$��%.?��Փ����ފ�L�6�}h�W�l}�Q�ȯmaeE�&��O��o��1DX��FK�f� %� V����L�#JHH���@���?��\�eN�v)�9�XTj�邝�4�Q�Ǝ` m�V�J� �N^�O�=��pYL����֕�0���z�+��4#|i1�����7��f�[W\��y��LUl� ��tx~����~�%��U1��"R�3w,�e�6`%"Q_bz�*��
m%�R�i�5�z=��mG�H`��EG��@^k���nI�H6�(tU2���B��8|"
����`.��P�}�r��Wg''�Q(��wR�`�O�օ���(�|��u��پ0k���\�JzD�����E�!緆T�Yρ0�+a��5����AK�����蠟*kS.�%�em����iZ�"��M�Ѿ`If�Ę���	��+K�~���~��Q�q�Pr�3�r��y��4k./��y��]�O�-���n�����sM�S>F�����$�
?��JL9����S;Gv���ٳ�p$�������Hʙ�Ct}����F���R<�Y*��3_����h�`��^�g��n��Xq��Q�����!�ҙnf�@pZ�|?|Nb"�8���^5xN5x=V��g&5s����X��0�k�'���ǿVĐ��Ѽ0���M1�T8�h�t���s>޸�}h�l�R�R/V�-�8���ͽ#�7������HAd`�e�:�i�^�j�l���?F�	a�]+o)�ׅ���#Up�t�����KӲ�cS�1���_9��C���~d��l����}>ͯ����2G>�����J��� ��=�gZd3;�ZmmE�`�^����|Ş�xķ_ْ���9���=d��O�~�:���@]]d���ޚ�l�sZ\1�?M�R�v����W�bZ��}����U	��g[���h�H�WQ���#G�]<ua&q��A��C�"Q�� 8<[�KXY^ɇ�����с�p˨|�t����㥊��9���CB-��D��Cp{���\/�*�*���}�Hب���%��+����i��wZ��NU���n��7��4;`�1aØa���~���a��ˇ�Ol�*%:��������N:��z�@����� �����b[�o����{���ip������1� ҧ�S+h'��Z�F�5��?��oE����!�2�C=.��� $�H6��ɟ��Y�^B�/O�hwku��~�������9$��{�>��%N�fCke�V��Fk�(� ö�S@�v{���V�K�u��Sߟ�o�\̋;s��2����&ҧ��{*��2�甒�(���~/!��^s ���}��n>�����O ����?煽\.`cU� G]�'�t�^� 2Z_����Z��M7���/N�}�� �^x��[,�*����������L%E==#� ���;��Wc婭 ؾB�n�ןj߃��6�-���I�k�~v��5]4O�*h��V� _��_ �Ă���$��R��SD�þ^���i����_2|�yȿAx�n��~T��2�Ɨ
>��������?�\|�n�Z�?RB#���݁�����Fpx�F0�`"��~�:��"�/jS�(�g��!E��?Dg4�|f��mn5��[-_ݮ��)M܀W�@��(�'�%����1�t��_,�6湅=����� ��9L�9�2FE�g�k]V���1?,$T1��Q�rnI���|m�ǀ^�'��n�,5t��L����&7���^�G������
�-4�����m��8N�S�n�Q��k�+�7$m
���sa32�������v8���Y��)��*B�MU;���)�j�X׋���DP�O� %�?��Uf&\��s��4𼓏F�-�mθi8���xj-OW=\[]o�'�P�i�T�U��v���Q���"+QT��Z�ʷ%=�h۹w#C���ܔ��Qײ��+ �` �]��	��n��d����
�W�Mq+�j�ݐ�A� �T�64��� ԳP�*�D06�����]��ԙ d�V��/�,���F+8L�b�~/߯����#�)oZ���t��WW�#u
ķ4U���#�<*�3
rn+�U�]ݬMZ���V����Z�V*���������x�]z�!��q��%O�nxH�i����+寻���������Z����H�YU9P^�q~Z+d��Z����/�̔��1ș���V>� �ʶ��T��3x��~�}��y�qmVCz��5#@7�"���/]�
Zc�+�KH�ւ������5X<��цV�z�@��^��|�C�����4��9�0~!l������"Pj�e*5���N��Ls�(.��!z��Oh��OM�&Ҡ�ēo^U��"�'�u�20���9!�I��ۖ-alJ����#���5@&������O$'7�U���R۲*	�8|Y����\X'�ot�na63�!{��-`�R�`��(��6MA�h0�gJY��=K'�E5�8&⚜?��ok�Lk�4~���IX�+w肟�b"5*��Ve(*�4�皜�{�̛��fX�ȑ!�E�e[�\��z�a;��[�r6t�֞�tk��Ixz�[/ ��	��KH/p�h���V�>�^��;\u�w$N�hY@����Jik���$D���o|�Y���/DV��癍��GZ�ӓ��$4�o<(��3|H/A.D��|�.����daҀ5�.L���4��{�#{U��*j�I��ĸ˲L�!	c��)Ċp���P�+`9�?p�
�]S>���:_���#I��b*0Ū�(U��P��T��+���zBA{Uռp��^:�݆0���RP�J�`�Ȭ������4��\�Φ�Z��hp =ڳ��=��q��Rf�g�-DhG��-2[:�}��.J��3~L�[Q��F���,yx�.b^���mr��c�ơ��>��M����[����+yL[�(����׶Ýk�i���m�BC��*��@;��f
h��[�m�`�9���rNH}�c�[p
!�j	�) x�-ۍ;�Y����h�m܇���fa���0��A+���1�#�@)Z�@����W�Z�Owkԛ\�R�=G��hM\�iE"���L�FM�c��� ���ݩ�8��p�Nj��k h��.9�탺t���b��jܝ�W���IX���e8b�g�ئ�2\�O3��f/Y�ѕ��Ǆ���_lR�>��^��T�Kp�N;礗7�R���ڬKٴ���/g�zR��,�6��Vi�>Z�-� �6�+Ab�*�bN�Hz��=��*�ұ>
�A�Pm+�O-����R�)�Y�:��]^��
�+��Y���9^�
�Cz!�A���3�8�A�Y�!B&�l�y�N60j����ک�4�K����ڊt�6~����y}p�	�f�Ȧp��B�a|���>ޗX�j�)��}J,�;)��_n�%��z�6/��%��L�%D5.�;�I��Z�[�ΗҪx���ҟ%S�O�tRS��ɰԬ�ߩ�L�����L�����|��-�K�Y4�����ݝJ[Q!�6�<N=ʋ�:�E��y�s�I^��]BP��ϵ_��!5an��'�M��� y����uن�.\���_Z����sB�u���SX0�P�0��~_��f��Z������0���	a����a�L;�G���x�����GN�K���l�ܐ��1����ue2̌�++��,8j}a�����ѳ�\�PQ2�V-΄���/����u|RE/�Ԭ�(�<���\�k=L֪���%�,n�T�w=���}D��(�4����8����e�l������օ�ZR���<�6��t�V˧���Y��Nܨ[��\��V�[�T�6hb�ꄾ}R��hU�ն[8̋�_vYyYûΟ6W(z��]��K���$̈=���6E^��B?o�(�0LT��?�Mν<ҌсP^��$j�a�y���˾i,a��C���Ѭ9�˼���r�mo��i�L���[��	��.�~z:�墣Ue�$�YqY���1���a����d??�g�R`��e�c3�լ�)�Jp� !9�׺��Ľ]����Q���+	���1���Bv��U��zk�᮸�W��� � ��C�$���9p�$si�x�;(t��P[�~N�I�$��G(1>9̫.j��>"��p���l�rҴ�]kb�=���é<y�&���ɩaY}J�%�C�V��3KL�fƆd��-\�Ni$�=iΐد	ʪ�N��+]+�����d�hօU���D�y��'�+��Uc��2��#f�-E-)�`�r��Ꙣh(j���{���A���K��G=L�nG9,�Ń*�#Ϗ.�Ϸ���?�Ny�SN*=��@{Yu��w1�}d����
z$W��OL�x6+�uL�$�Χ�!��������oωs����
�)�'��qAN͚�/7tzY�D2].B��k�%6P�e�.��yrw	$�l��7��@��6.�b�.�T+�M��r�V��R��G�$87ki|�:<��Ut�@�T^Őcꜯ��zZxY�0Ov��+�6��� ���*�2�B�NI�	��bK�k��*@E�� ����э�U�g��̐��d�$��R �q�����;�+�ҞJ���fY��H�UR�,�
䍎�_	�~�d�e�;m���B�bI��8��sJ�WiWG�̏N홪�zI;�2.P��y��?�A��ǎR����k�Pvj�G�����~�o���-��������e�ċ��(�f��qӭ���.8��t_Y���5q][/n �-1���-���
K�m-�o��M�S�=̰�Y�y���ɔ\��N[�1�G�F�t�����~�|��Rl��i�aC8��K�bp����*uRA�{5��Ny6y�Z��FȤ0�J�z"Q��	���/���b�y�;��.�'��S\�N~|���u�U2�S[�<�����G�X!��Tr���A����~��Ͽ~v��Ġ���[:_P�,eO%�q��t�Hh��Jci�E1��̹��a4�ܼ�'TUIn�Ȯє�T���N��3��Y'�.iy�*�b=j�K��G�1���{�t�i����6Xౣ�|�5Q�����3�x
ۿ}�a���;�Azz۰G�Ad ��?�$o����:L���5�ޙ<�e�]�e�("��1 �؞
\l��O��»�`a�l�_�xܳ�/meK+6���|~Vᶶ+�i/���o�����Ư�������eY<�F��
�h{�������,�h�H�+b�����O���;)R�VP����yB�ˁ�s�r4���mf�J2n��� 5����:��6�>�J[�V�5�(�bWˊ��w3U6S�;�:0o�����U){�^Vi���}�;"}0��?D�x�@y�s���k��-u�ȗ���7�P��-���yX����7�IV��&���D�q?�\��G>G�����[Vj�5�C4��Z`)�c�#����� ���D�t!��Q�L�4m��`�\���ܸ?�C�pA-M����\ޏ9�6�l���Jw��C�hX�si�!�Ds�%��A�4�>:�u���uvj�c����@�} 5F �pכ�ÊԶ� ���)*���:_��%�G��	��n����z�G�:5�5x�by��>v�u��2jG}�a���@2�#_�2�#�A�=�����#X��xg�uoq�#A�����y-� �A��d��A�U
�뾙kq�]t�R��{B��)�o��7}lJ4eп�%�G~zƅ��S��p�K4������b����v>	͏��Op���E^�3�g% �|�\(/�7��:�ʍﳦ�)�����5
��S�b�#6C2"8��?�$��! c/T�686��ىk�g���0����C.�BD�(�'���p��Fp�h��-�$ �����=�	*w�lbjȩ�nQ��f�{�E���Nqq�K�	�&���Wl���A^:ӂ[���)DID~�l�#+�{q=�d4_�֗�?;�%���:Z��s��9@īF���e"^eʄ��(=�9�3Q��4���2����K𘔋�E\RƧ��%v��Os�j8ovK[���GT�7�ZK��*���
�z�-q�����cA.�؆��[��8Ħ8��}H{����X �.�!�OG�y��VW��E����߿Euvn�s��t����L������a�.F��E{�8r}��0ǣI�}�wB���b0�3d{��y�&#��]("�rA�.ZKL���j��Ճ���^���_���k��e�W��pP��:A�u���C��K�KI.H���OI��Ta�y�J����a�h��zA)��,����zY�?+p�T��"aNG�?�&�e(d���l�Z�-�r�(���&�,*[��n-��2�q�7S�(��`����=�����ʹ�v8^x{�R	2T��sp��gT$�*{J�{�W��yuշ��T����K��Z~�֊�UYW��0K�
�_����,�}]��E�6�7�^n�.�M]�.:] �\�a�s��,���0SW�CX��2�p3���]�ڷ���v�K@��? O򠞨�n?�O`eZ�L~�4޲ЧP���w�kLnp���:o����m�E�B�/���_n �����yŤ)�|�#b8o%k�r}=���N7�4 �e=@�x���Fۮ�-������0@ަ�5Ĥ@<h��N�	4j��a셗�����z�"���J��+��Ka�t vW��ҳZ��v-)�غtSd@tx�  m�2��������H�	R��[�tW�z��;��{HZ��7��M�3W���v�ôW�-����ߥh����]Hi���oo��!W-y��*�^�2i.W�V@jp {�؅�3�{UM~{��w�~�ۛV�K��~�~~|��J�TU�{U*��j^J��ծ�����j������b	�(�&P���~G��u�~� ���b�ǳ��*gC��C��(Vމ�3ū^�5����`臎�0pDrN���B/�'3jf�E��	6D6�i���O�W芮q}C�A� ���qa���>��#i���G@A�5�O��%�0ǋ��|��p����X�����5�0�f�[��~ ���̄���� ����Y#�H�n�V��ի��iW��c�;��T�5h�ڟ�B���������z⺔��(��}cwo���>���:�{}اYa/���[�/h�뀞<��ݟ�����(b�B`�*������H�R�I�aX��c ^�vv���
��v�/ fa�by���@,2<� ��_���B=9��5�}D�ͼ����Mڵ�P]:�]��`�T��A�c8��#t���&���u��}��c�ګ�l�*>���O�����_�����D�l�$�n!/\�`{\�H3�@��P�M���@K}���a�W���0�ܯ�`j�C��3�� �Ɇ+��.��.a�{S���F:&�i:#��Ƒ�m(C�Q�#`��y�����M��W�a1U��s�����Q��6û)�,R	�7p.Mg��
B��>��|��&�U�y+�7D����巷f��U
�p�C���of��^��� ��Y"_�LnIaqk�[i�Hx��G�����Q��N�6cs����4O�P�x�Op����s3�}>\�\z!gt)�{�~	j�Hn�3dJ:�N�Y@ԛ��Tm*A��h N~bX@��߉�U��4`�QԴ�&3���i�`EJ� �:7ݗk��'� �~r��F+0\>��.|{�ϻW���A�'��ƻ(6�cL�{eG��y65f�3�q9�92� �gc��a������Z�o3\Ue��S��e$Q����]�YL2դ��&1�i������u�J9��lٙ�$��C 1��o��I���h0٘����.�;;8�Щ�̞6N�E�W��on�??)<��h4������ne??L��㌴"�����R�$�d8�ˤ��t�g1��z�A�k�[���1���l�6�]��A�����$]�%��ad�I�������۲����8!-JJ�$47��������5^�X�a�(y�s:ۖ_L�h���h%Z��,& � �;������-�������ˤd�-b r�N��5 L�+�O�U�@ �n^�?'��&M�*��1��w}��2;��j�Yf��꿟��J��E�s3,a�9��
�7NA�������ޭ�m��}��j���a�����Mj=O�����2x`�pU{��h6���/�.L��w���F�|�W͔2^��fƇ��`�:ƒ�CS���Cܔ��[a��Y���@n �4�ŝ�#���¨�%f�.h��s3�}�xA�6a��Ѐ̇%���g@�U;=��o>�� t����k�;:!f��7Y��8��7������G����P2�U�����)��;�ȶ*�rM�G�&���x�ݝ�#�,��j��{/7]��g�V��E)��\��[Gmڜ�2�4�ރT���;�;1��iZ5�fɐSK�S�"�z<���ɔY2Sa)�l�w��l�7�*f3Kی�����yA�n����7J��o&�]ɔ��v ��ؤރ���
��<F�y��-MI������>V�oN���Y�t�ϟ/��Z�i.� ���O�D M�N}$�f���j��������V�~��(B���q��N�������\S����:�u�S��=�4�F:'�/��XE�ԛǿ��JP���^V��O�`T���V:�Q�XlSn��k<[lE���"@}��_�A�w���|!�n�ZS/�"����uw����4~�����1u�]�����,�OZL���r��Y4�nh�Q��Vջȉ]�P�[�3\]�tf�=+uj��r���V���Љb�d�12�.�!H�`Jx�XҴՙϟ?�	��H�hX���2�M�aH'��1G���S�㍉U|q��iq��iΘ����~�����[���cEFlE叛x����X�r�_fU5�g�J�9�����O%�V�~�r��C�{J�K�;�ˁ7�t���~�u�&����,�x=L��0���sF�[��j\���b�zҰQ�+�p�� �
&�_'��L����WFE����A�$I`J;�T��I]�Э��e�XA��ZLAp����/��>M���ʮOV�3#���͂�"$2��� �Up��;�n����*#���	a�56F����;	���O���:�����0����O�iV��A2+�o$����އO���_�K���a3��T�R���q�Y��6�"$|��n%�Z����Ml�#F=\Z����ʶK:(8hE1�1u���n���F�-b2�=�̮sR�X&�SeJ�z2F=WF�0������r�B�Uf��xb�ϱʲp������\/���ǂ,)�򸦀ñ���J�2+׽:�p6�ӓ�������(��5}/Ě�&����
�5�tkG�1�]Z�4zT�3�Q��9|�h.�]�_ �j��N�[�.NY\�Rţ�sGO�=�q�,��,�f�+_���$PZ�S�6�W�(��miwi�E��B���b H��+9?��m���g̮��0Uo�ty�c�!6%-���ǯK�87���q1�)��o�rO/17Uǰ*��kR�w����U_*��d`JN69̮��I X����.�<���<r]�1�NFs��QO%fD�)�(�RKN-�˿=�8��/2�P��瑱;���?H��ωƭNwv��t0�Y�iMˉu�R]���)_�"�%% �`n�	�9S�I%�V�G��Իt���r�(��ʔ�%"P���d(eU=��
�"��Jy��k�)��:�+-�����WR�i�s����n�P�%�*�A�F'jA��t�+�����QC��Cdq�WG5b�<W�Dl��m�P��Pހs��
#9�A��/��X9�t?�0' P��C�3҆�kr^���(�R�!Mtc 3�L��(Eu�q�T���7
Θ��Ȋ�z�zF�z�ü�f[��E�q��,�K���	a&���Y2�h�9�����늰� �VM 	5}X�K��5T_Z�"���ϖ�dh�]���Il@�]Z�m���:㣵m���m�-~����ܑ�^��;�zG��;h���0�e|��|t�-�����6uEO	kc2���M�
BG%v�M�n�Y#��������;�ܮ?�`Nۙ�ިC��B���s�Ҧ /L�m��GpT�kr�۵a�kz�Х2�L��Uv���P�[W�+]u�"��X�m2��F�����xy���,�Yz��� a��=�J�s=�����ϰ�e�Rd���`�i�N�y�W�K�a��ρ���O(��=�{��/�����8k~�l���k���Ljg;�	S4����ɝ�Z��t�ȴ��a�׭�|��S�4<a>��x]{}�x�/�Ə6��_G[6����g����s��z;c/��-��m��&�+V�z�v��ٚ\w~i��г����S/�=�(`�^Mfw�V�6$MXiX��n�꭫�R�J�%6z
B�s�D+u.��l����^��
v�, �I�kM!��7���R6 �g�	`���#�M���跔�EZ��	lUpH��L���;�]#D�5��n�4�B{�g}ǜ�x��S��G�R[��[i��p�#�I���޺2�@����@@�T�<�+��fM
�*1K:4���;u�g߬ꂷC�sK)�s���شF��D�2��vk"Id�0��-XQ��0�2m崯cq]��D�Ҫ�/Sᔄ{���OH�y��r��C����*�(�)�4թ�E��3h�d��z���`�>��&�I՘hc�)V�u�� �~uu�X�H���k���6ԩ�z�d���?d�9�Y�X���W��3��Y�J�q���-�+3����������\�]Ƥ�B8@16�a�k�;D�vi�r��:�cn�#��R�� eN)�6�p�o�
B=m��^��Fg�H�b�e)<�NX�R�3y8ːd�Y�W��p�I�o�N����lc`A��Q2�v��Ļ�y��M�f#�$��������:�}���RR��t�5��zߚ��A�k4���cFG�Yb�(���^1gT-%������7'�_��BF��5�Ve�Yx��rYil/�Oy/�zh��ɍ�C&���*�i�$:JT(?P<V8npIB��&N��6P�˟Q���]g[�Sg�˖�f�Ym�Q���
��?`��M����^��q�b�k^�p��5eK[=�k�j��dq��o��/C�7\�b I�Lި.0Ѣ8Y|�Ey��$�x��I����/ڃ��ꃤdL�Z9�'���T�f��:���f�H��\�'G����Y�ٔ���|�V�zTZk�¥�Ԑ�<��WŢ�̗�"���K,��v��-$P�d-����o���mۍ=�71��qu�+ۮ�Nb���.2���1�`�B�gVF'�ü�kn���������WU�:���j�*`5Cq�Dʬ�T�D"͈3ۘ�~2^b��c
�&�Js�4!֞��h�zds��F��Ԗ%y��Ax��B�Ct��Oْ8u���n��<gY����3/�~\{���H���"畫�A׋"Xl��1{���Q�h�ߋ��ދ.i�u�pT5��-�	]V��r0�5mz�a!Q��vL��zG��x�}A����)�"L��*���-��z��_��"����M�5׉�@e�~}P�t�B�0u�s�1?���|�I �ȷ�n!�r����Qmދ�b[�4(r&c�s���1��<We��1��g�� ��?�7@�'Z<a�5w�����6�R�R�I*��p�q�8�U���"Aެ-�!фWs;�A\O�K�Ѽ?E�B�XA2��It�2��Y۶�����-��kK�Y���x|�&���/��F! �]O\�y��dzI��)2��d�j30+ݽ��� �dbUI,�k<��P�Hd��V�ܵ�ch��Ѥ��Yq�־1޶@ߐ�V�u�H.�>um|ۨ፫v�� �N���.ɩl$��x[�E/�o;>��4"�[銃/E�鵻�k��Q��1���52�Ӭ�0�J�n�ID���]�A��rO$o\�P��rE¦�����a�=���U���R4[�M_� կ>��~B�7p�Q���;,��)���FC��d	IUX%���l[�H��v��_��/*�)�LG�K�u�6���
g�U��ӳ��m��,������� �xH�V�R��Un���]�y�%
�J� �WNk�o[%ΚVUk��E���x���"$���/��p���PŊQ#E` �:��OZ���Y�5�l����x�V�R�d��V�e��%"N:
JΊ�	_�۾㟭�通s��9A�Ei������Y%"��kRx��#�FtS�a��oN�j�"�Һ�2FU�P�U^�nޔ�����W;g>��G�V6��4�+ޘ�U*��p4��P�P�:4��X���S��:1�pN��'���Ue�	9���f�fc�V���w���;��1r��>������'�N�_F.��A\��$�P��0�~��J:���d��hI�o[=�����k|����>*���W�*_	v��|P��vҳ��	[���O��i�S��d�j����VJ(�mĂ���&��;x��u5׏M���c�z�{hx{׌������/Н�>���r��Ss?.�&�{*�5�\��E��(��M�V>�&�gv�{�Od����3`r�8����Zy���8OpT�}�x�8'�ea瞍p9�|�5\��e��!~��Ƞ�!}JT�1�]5�`��NJ6�܇�ُ��[wHf���� d�)J�C�UF���)S�1�bˀ*��B�0R�>�c%o�n=�e1S YL_6�\��m�C��n�ٕ��H�����5��^�ؘ��G�	�|ˮ]� �}C܄oOe�X��7���c F�\��`�7eph�J�\�����>J��a�$V����s䜷�A�ᴃr����2+i�=��Z:Ĉ�}���]��fJ$pNt$'���t���m�X��v���&��5�J�;�ťg���x�b\� ���Sz+/���RЮ�-�mG%�Ύ��g���a�)	��?�m�Ú�T���Ǘa.K��3�;p����p]'8h4�Bv<�,?���[<�T��x���m"#�߈"s<u@y@��j�ەD���fl#?�)�̀��n�s�����[�/�~2�u;�<�N��	��V|�����b�� ��s��L���ia~|$�9��������hW}�?>���Tn��݌��&!~����h�F�|�9�
S�A�ڪ{B����Y�;7�+4)�o#w���᥸���ɽ9��"�&趒wp:�?�4�~<���s3�����o;dC�y��WA&�_��D��%�rsT8G�t~�������ҢS�L��d]ʇ)���Ѳ-T��)�-�n�W�q��;Ag�FY��G"�cz&_�l���*��#ͦ�|XO�?r�:�`����A��婇)��Y}��>!?)���`�X��6��k�[m[X����k�;x�pC]�GvN����!�+`S[0r]�Λ��Q�k��� V4�+�>Vk�&�;=��?��k�ם���mR��t7$���lي\��x��;�s����%g.�I6��Wvٕ=|����Z�į�֝Z��о/V=&�5rc-AXԸ�B�6��F�3}A�|κ�������6�zv�H�pkt[S�������B���Յ:��в����;i��B�x�-�%��ye�H�.��uj�V@�w>k �[������7*r���"�M�ƌ�|#I�
ԙ�`�&��^ ���D}�B�5�!H��h���9�y����x� eP��`����s]ֈ�#��w��T*7=N�`�y.L�:k�O��@ x�Γ.A���xý����9�mG��h�\��9��
W��Ӽs�i'uɼ����N�pj���E�eO��t�g�ݾ�L.J��rJ��-;Bi(\����s����<Lݳ�tILA7���,e��J��g`��cQ��m�	������q�8-��3D界/�IZ�sF;ˍdS�~	�n�M*I���i��d���.�
W&���R��}_���®k��_.�����I��u���C�;�X��֢]д� �=��-�B����_ �0�L��3��qA�@g��a�:(������}��n�;Ґ�)zj}<N��%S +�uD)�8c!���!n�2�sO���D���n�燓���=Y�Z{�ʟ�4��孚��q�ꥦƵ������G�p:�~�[a��a?m�p���O��M��<�!���ٮ�c��)(J��T]a�>w:�[x�gC��p�9?���d��
�H˓$CIz@2*(�F��>����B��][ٙA�yy!F���w ��qQ8C<6!>f��|�B�~�4�G�aqV�t=)X4��A��J�h��f-w�
�3\8:��<,eekg�˘��s�,mҤ~�e�G+���u-c ��2i��ux5�g,�0���J�k4uƉLs��W$�K�7���ٛ{�tG�������\L ΰԜ����4���f&W�P�{Z:�EA`�1�� ��ss�m�re&A�~-��Cy������9=��v��B�j&;䵏�:��/R\v������Dҝ`ih���ܧm�adVB��'���lV-��U��/~�z�JȴKC0 k" �Zxi4�	5Y]|���l���B�,@
B�X\�p�NO����b��%g)g�)ӟ��&��È�l�]~�g�����ڕ(4�?��h��܎Q�J9r7��pZ�@^?���eqyF$+�+heB�6�a���G���䄜��� z{c��W2�J�|b�S"�Vs�x-YM�X#�x��3d� /��#�y���uj�fx�n��tx"�Mh�&	��nˆ�ZG����a�2���S�'V~�N�$�I�"@��-����s%���ψ���&�%�KPxOb��h_�뻄9��N��|��o�U���:Ѷ݊�����8/c�����4�#{g�Ĭ�z6���s�x��ƎD��ə،	Kv���I�j� -I�7m�d1s�QQ�7*E�2���1�t'q�Դ{˔��ѧ����3�%!�)��w!�{k����V^Z�!�%}��	����}����Q�ٱ�����"t3�b�&�Oy�k���1z��Lq�k׳�sF$��z�	�K�W*x�
q���,"�8����׋μ%�o����tU�v�b|u
���cf�k�d(8r��!�QSS/���C�,���uI�8�U��y��/n�����ߏ���a�O.GTSu�����Dg����s�f��N�h6�S2�5�NLs���ȵ��s^]L:�c�_$�{ C9���w=.{\�K�,1C���O'���2
Jn%!�}.Ϝ���K�S+:��5e�G�έz��h�Y{�����<�e�����i��{.�78a�9[����Sq�_�yp;�t�ϡM��h��
��g0���n� [`d�2�6���M�-�w��ٚ�f�v/�x�n�*R�{�ї�xY΋^S++Jmv����)��;�4Y>c>ŏ�J��d�8�C��Gȫ�wA@�u��6����s���4�Ϧ^w|u<��v�M�qҙ'n�S_�P���ދ�U~���d)W��9	_�#�J(\�'�0s�(����9���u�q��O�4��Sqi&�dʗ�b8��<��؆3�w7R����v�T(܉4,�L��P�/�j���K6���맶�%��Z�ƥ�;Ł��iӨ��D/Q^�]�'y��h|xg,�=�mu��v��/�i��e�]��@�zz1A5![Y�O.w&�o%A^���JE���)��&�P�-4&I����UQ;�v���ؔC^nF����Ivg>�#�U��dг����EӖ����yr�KJn�2q�̄H����ɀq.�<V�9��D�zF�ƕ���~Y+�rm�(<W-lK~��qf8$W�#�����\���2�c�ay> VpI4��
�T=��]�vq���|J�M*O�>0e3����-`��1�d����b0]0A����Y��6��_���H�gI��%��u��
�����R�[��R蕸�!{ה��ph)x7���Z�PAr,[I��[����<��'k!&D%`O�M,ޮ�O����ц,��!���<�*�C�lzR��SF�o��a���R�<)�tଡtJJӕF�ʊn�}af� �]��xZ�뚡d<SH:v��8k�8� h���O�]�d�R%,H ��ޑm	�+�\q���TH�
��P>^
�k����,���x��z꿊�����(�,���B���m���#haQ�\����<�]���,4����1l�b(�XF�ʴ�9Y��S��F+d���)��R�YeVԮrS��n$־��&�,�K�_F��fg_�
Q-����ߔ�.~�&(�}��o�!���S H;��<���f�N�U�ϲ� ��Q�P2]#� n1�U&�A�",���ut�5�8��&��6�Zoq��vK�,�*�
B���u>�� ��󉕿J��ݟ�R�4T)A��&3�6��co�v�%�mN=����VTW�b[��V��R����o#��C��V��+���[�4?^���&�ZB�{m�$ ���n� 
�ڜ�,�;O�|?���z�[X���y����t5!=�t&ip\�ۛpR�D�[Э�p'�������rq��7B�x�WŌ_A��F6b
�\���`��>T�����W��ϧ���EE>�IP- )lM�v���&�{�E�&?���u�V^��)�l��5͈J�\U�R�jӭj�&V8ɫ]�}Z-
}' (vi��e)�Ȍ�#�����]����&v�^�
�k�W�˸��P*O9�1�$�YK(4}��Y�lKAS7-d�qH���Ge��u�Q]���E�t�lW�1��Tٚ�'��k��թy�GF =��ǲ�4�/�m�Gߛ:6�)!����k̀4�#�x��j[������+��x�ܐ]#'[o9.9۟o�'����@v�}+I�|d\F���Sb�-��DL��gz=J�In��.��Ug��n�A܈uYF���1+�dg­XB\(�">��;@	�F�@�����	n(����Ymg���@����9���bA�������[F�u��٤�=�AV�Q>�c����|7�y?��h�O���}��j��#��C#q돘�Q����x�P��Wf�32�#b�K{����1�� �s_,�ė�=�m꘥Z���RhD`�2$z�?ψ���8����ނp9�h��pG"u��Q���^I�p_o*x�47��S�Kx#�� Q"�ە�yc��?�r#�i����#���
���Y����v�F����%L�\,���z�͐����v���X͏w��<��|��e�Un��Od}n\���q���~԰.��[���'ᾮ���3t� ���|I�����gB�`%�R�Ԛp���F��b�Vٻ;�v�*c�	���bV�{2�h�4�5�ƶ�ݵ�VkA(b-����Z�	��kcQ ���`:܏��lqg4B�3j�j���M_ժ?�F��~��bU�E1l�Q��$�Cp�ۀ���&h�NE�qI�6�i$:4��o���%�ʌN���H;E:�n��P{ �0��Y�e���Z�A�_�AhM!�Ĝr!�vԣ�C�"��D����}�Q֌L�Gd&B�nV9������wu��dmv��O�;��h+���a#d��I�>��G)�z�()kG�0MaG�h�h�<:
b��Ρy*�Ĕlm▨N�/K.0��/wB��+�;5�wԈ�9�Ѩ|���5�,7B�{%�FSF�	q��є� 9h,p;Zޠ<�z��o���G@ɇ+�S��K��9Gm�p_�Yxm8E?�󤊿�i��"Z�K��I��/,yX�KM�!=�N��<����˧�@�x�\��r�ѱ�[�R�mEFb�� ,è:��K�I.b9�� a��.ٛ9�@�Nq�m�vP����PA(����Ȥ!���pVt����MM:�n�&�Od~�q�XA��a��Y�Ŕ���]� p�k��h2b���$�r7Q�L\�u��w!)������� �&��:��^v�W�*v�R��d�\Q�qW��z��/�qCU��.¹�8�@�.��w�N�����M�q�M���z�5ex^	���3�96�k��m�m-(R������	�g�P�e�U�\�X�7+�܏K��\��#Z�d�y��Xyz��#^`BW���S�c|j-E�ҨL�0���d��Z�:/��xd�"e�p<?�}E��Px�w�'0tMB_�T��O�~�t��$\6���[2o����lG���IQ���<O���@�� ���OV8\��Zl��~�@���O|��� �,$bV �5�,�L�?4xָ��F���#V'y��s�X�&W�	V�����=�cҕl�g�A~���/;�4�pfE��b"/	�Ϳ����{n�6�#�3���Юj�6�am��k�)�w��/��C��	:މ�x�q���A��j�t[Z��X
�l�bm愤�/��4��� "�z�pZ2�����m�A�&�R��,*Y�
͡��	��+w X�^��"��Ѱ��Zk�����G�N$�~c����Ci��[E���J�j�D_���xr�,�%�NHA����SR��c:߉k|�c�ڳ����e[��?Z����e2+���K��[������M0E/�g\뱹���O{��.��?o���gn&q��r/o��������7/�Z��~����Sޯ�pa��w���g��f�X��6�����H����76�ࡣ�D�a6���b罭Ё�h��|T>�I�c�}���H�mK�+��̛k��3�Y�^K;)<�����t%�aX��9l���d��`�M`���q���[�q��{K��%�@��!�3Hd��[����'콫,/�A�g�,����b��p�9�2M�����!H<��J"V�P��a=���Aي#a���ˮL+���#�Bj��ۯ�b��Юmk���>/��L��Y�A� ���jW�+��1����}w��v�Lz�jH;�=�����.�~t��TH�QJ!m���MX���P�^��^���&�,'��Xb׏�7�)����p�G��a	�UwN��Bs��眘P��P���S�'^Ϟ�T��Y>~ߙ��V�IJa\��*f��W��J8;�L
uS���R	���嘏3�+f�~V��{qEX���'�Yɐӓ\�0n��Z�wi1 ��x{V��m�+ 
}��������ݓzl�M���D��q�q�߿}�28�W/Rĝez,���euo��
7�ۓ8�rؗ��U=�S���y���*��E:��0�o麆y�g�\
�h�nЌ�n��{�&��=���ͧ�m~x_�I�b.	`��
��	x�<��4���N���,k0���?��??�C�Bi�GD�Y��J��UJ��t`�H������2��N\��ܣ�9k�D*<�0�Y6E<te�=jL*�6D>!peqe��2��nb�o��Տ�;L<m)�XooL��b��d�ў�z���KC�$ �v�k2�Ο@~p�L]x���m�<s�5C3iH|/F8�	v8�v8���I^����J�Q�-�?O�����%��A�w��]��-L�I�r=/�J�ֲGd~}~�!ְ\��BZ�"��g���^IO �M���:Qs�)���,���Wz�Ve�#�&�B9/"�L�`n4�V`V� ��>c��NtY���,���1�Л�Ad��ً�4p��dFTы\A��s��w��n�v쓃Y~�.Ak�Q�$��(��y�R㜆H�C�sp����}D�lB��@��!���gy��<���k�����+�k�mK�?�-��ﮉ�A����4�oJ����߼?�|��Σz�>����}K��O���A�Qqoٟ��eP�Q����b�[%��4�M�AT������5�鎸1�|����/O�ZPG�A�,B`b+h���L�3��0�Oz��$Ơ�t���mJ�n}@�b���MW����'���v�3u
^�CoO����71�-�Q��)���b,�|�����3]�/�Ј��6W�� \��trE�}�?~��'+p�%�g�S }����zf��A]W)�x�<�J7 G�^&�i�z+"�#��ݜ���^2����]$�����]�Sǝw�~��.3�9���R,���R��]� ����51� *�E�E�~t��깖L����SI�p(�qÔ*���?.ۄ��W��mi�z�n�(X���[�޸"�7��J��n�t�r0hv��&�����OU�He�e��.��A��W8-�y��sH� ���LxP�V���J�\��FA��!R+)�+��G�����'<�<%1��B��X1��+Y�glS�#��+�t�����n���K0�\��!p�~�W���D�[��w�d/��5��o����:��:o�k��Vj��RO�6S���x�"�T���` �o��p�as�H�:Q}\�,�S{�|�y��������N��O�zPt�.1��z4�Ϟ~X��i���ܜ�>MPe"�5����_֑ݴ�S�g����sؗ�E�u��߹���f��ߛy]�T�0�ro3�ˋo>���
9��-:Ȓ.�$��T;���Q:�EN6�g�9���´��?��^zH ��\/Aݷ�:v����/�[����o%B����Ht`�y$bɀ#Sp�E�0|[A��n�?���mY�v$��'����t~��Z�c\N�	mV��>�ksdY�h�� ��S�E-"u�jq�*��"҂�0������]GVMaYy�UOE�6�������d�R����� *.nI�?
��C��)2��hEYض	�hA�� �?��d�ۨ�n�x�e�we'XwC&���l����"�B���R�\�=:�C���l�2�t�u�IP� 	ʀ��e��h5�g����y����x�(S�]rTez�N��rD#�B�5��ֹ(�4Ӫ���L���g)/m�Ia��F��U�o	s N�K����9VN�6��S6����jڭ��6p�������v;}���o9���D� ���T��ٙ���p.*)���|s4�g��C�Py9=��nRai�Z��Hh�	q���|�b��m��&nwhS��;��!
��\���l�G4쌑=!i���8����:hAQ(g��+��$�Z\��8��L��.gnJL.#��B6�{��/qD"�8jS�� (����"D���0h@5Ҟ��a��?��cGr�X�m���r���H�b����L���'�^ � ˱�eW�faUq�&D��hy���_�фY{��=B�)E b� ����YY��=j��9����b�Ѡ���a2k�а�RPh���B��Y_>���X�Q˕ s�y�i��;�8@�j�`��W8�l���_���du���(Y�-��n�K�T����Z'��)l�y%˭�gv$�S������No��S��eoz�|�����ToZ.�0���N���>P��ޜ�Ms���$�]���1�ZS]����0s�������O�Y�c�?�@��H��#!G,d�>O;A���Y�j7���=�Tˍ5�$��R̟%zy)t��_���9�C�Ld3��ٔ���1�!���!*<��BV��jSD�4?��|���d�7A��:���8��#Dh�p�/�a�e~�[�pz�2�� n����XV��|].Y�hf�������C���nؙ�Y;5�ni:yu� ���׸!��Zvb�/�:���Ĺ�U���A:r0�9q��Gr>{�&�g�1v�I�k��
�:�g�D|c�Ű�߳�9�9{@7a��]�}�TK��;X~��#|O@aq��'�c$e���Dݿ���#�s�0NuVd*�n/J7���0��x�{C����{�z�ݙƴ���ۛw�[0/�h&��S���d�L��h�G n�;����P͵�E�L٠��t�+�ߴnI���B��C��Z�����
�;�������נ���T����ܻ��"��"=a������`��X�:�
S9؊E~�=��Ա ʑ!/b�Lw�/9jO9��Q�u�I&-�N̉Ob��	�pf4_\G��T��z QCK�Y�45]�L���mq�����a�nJ��H,��_Q7�@*�;�L5��X�!JOk�U��������",��B�0�_������� >b��mWW|<���v�����z�X�o:��rZ ^�����_�8��׻�[�aO�/����o��ϋ��N��m_���!"���b� 7Wp;�H��O��QDʼ�����x�S��������G�������TB ��e����3f�}9?L�d7��]�k\�5X��[E՟1)���ط�t4�	�m�4jǉU���F|^����`�^�Ȅ�ë�>��"2_ ��߼DL�~����Lߓz�qz��ҏGL���hwϟ�S:�4�T�L�\�b��ߝ[q W� �{"�!��O�'�v�`6�{�c�,��?`	�T>���]j�c�3�,���嵛�Z��N�W��SS�����OM�<�v�����Uʀw�����kw���c$=a�2|m���Jk3VZ�-ަ�m��H�Q'Żj�w�j�C�7#�2�?b����IK�R ٶ�����gD4��B��=��H�!�#��Hj���{d2�aD[�phK����1H��"���c��@��@��gcGG��ҷDti �1�x��.Zn���a�G`�s��x[�g���(S�j6�C��A�-n��ݛ�Ǘ�d���q��@���;���^��s�>/&G��j��v�N锇������AC,���s�m��7�4��l�I�>�b(A`��@XK�"�!E���棒��X|�����gێH��=d{ҟ�4:^jW1ip�P�\��&�b�Ҩ����,�sD]Z ٶ��"��Ì>��ш4K�S6M�.ޢ�����މIѡ#��1�ρ �aDZ����QMҔĘY�:\��(�ö�6޵�w&2[��
�ȁ&]��JH���rHv�|9	�y��@2O!��c6��[�K�m���$E�8�῵�ٶf�k��f=�6e��~G&��Sy�S	��E�ӿ�;7��(�׊���!W�7��Ɛ��("�3����g�5�?�y=�uAz���Q�4�=0��%b1+m֋�̴��xZ�D�X��;�n^W�-�@���Djob���H�@�I��5#L��
��2�U\U�&�@pG4+)ڣ=���c�ȻkPF�t�"#�����kc�.v��鶘�5b��M+��5TD;d�/)������c�x]�$'(p���P!��u%��G������TdC[Z=T���"�`��P��cU%@�N�j���I?����:�+z{��IĕGuQ����imj���du���I�l�B;.a��r�p�m�w���� ���~M��Y%�� �lEUm��[֕��+|����K,ȶ�ȱl��\�E�˳�;\>�u���tٶx�+]�Jڇ˶�:Z
\���h����L糊-f��Tm֞���a��Zwȶ��O�޻��ͺ����˨��|N�m��+�cJ�xƣx�I�'~�����`ww�<�+����=����B��Qw��a�È��Ç�� ^�xB��ד���Lē� �����D��62Y���,�H#6��9lT����T�%P��%"�/��X���_.5���m���Y�|�>.�eېgϥ�T��ߥ+���F@ֹo< |J~�s4ܼ�=���K��]C�����a�7��z=��^�����몁�S?� l� ��#,;��z�a/&����u��
�J�b��C�.d������s�Z�-�^4�B�R�8�u"!��د6�'��X	M7ezi�aN,�e����?*h���~����r �ԯ��76�����]g(��d�AC�Dn���&������eJ��x�.���J/�1�!HTV&�s���=jRj�����y���z�@���<�j]��np^���'n��l%�ߥ�t@�{�F߀�_�5}B ru/Rq:&���S��"L�bd���Ez��Rtx��@�k��n3�hY��Slu��P'rl�韢́8\K�����RA�Һ�F����PPN|%�8e���C���k/6$�����f���8�[�Zx��������j�'|��{oqM�Dюi��9\�⾁�*�εZ���~��{�NiF�c����)�Է�r��yD��G��jA:���a���3�������-�i�F@w�� ��X�Q���g��f`���)� r�U�H#ƾ
=��/�Z0h��w��\.P��5T[����I3��+>������p�y����y�����r^>�*�C�qٶht��@����P�}�]=��j1R��!�AG���Yy;�kt�q�-��I��΁e��@�$�K+fҼ���y�K�PM	��jjϐo[k����۵�V޾ߵ���"7LIP?��Z�Bj��*B6]����8416��?�*��BvA��9�	pS}s�wg���u�s|�����ka9ыT�_�p
\WH������տ{x�~��.!�t{\w��h+���/@�#�R,���"9#0�g�G�R��;G�12�/��-�ݣ�s�0��+7�7��5E4��
�=�l�s��G��y&���|��9Cګ����w�g���*�ܕs�1ߡ&>P9���ΗGظ��:���:�a|S�� ����t_��R�^�W��QI�dl��!���ȱ��l�:�)�9�O��6k��!�n��͇
 �m���GN�#i�s[g����=)��1�p�bH�y��_EXvn|2������jБp�l�Q�u�����9Ġ���=��©8G�L�Gx^��	�kfD<�	0P`^��L�()L�$Ƶ{�,������_���<J�+v��� @	U��^��w���b�G@���K�������x)kֺ�E/�}��B�g㎃��B����i��u�vjx��]b1H���5�e��弬ͱ�$I�%Z��7�r	J֓���+Z�p�}����9���g��'s?����H]��Y�C�U�ܫz��_&Ԇ��[v�_XP�聟=�'F�\\�U2xg<Y���>k:�p��x.
y�ƽ��vw��tc��ֶ�Ԉ�<OF'�M8ʧK%׵�Lj����0�����hCՅ��fl���� YY��=���fy�p@Y�j���-PX`������?�v��*Ph�Jm��ŕ?T���W{�r�*��%ֺ���?��5���ɥ�dk�DJ��E%{ �&�$��Cu߬}���<q�*N�aqH��8����R�,�m�P����̅�j��/vZeQr^�<��n�-���x�ߘ㿷_Ґ,���с�	�k��������d�Ȃi���p�Pk�6%^�1V����8��t��Z�H;.s��lW����Ƒ���l�U�=����/V�I���b�(��j�Q�R�?"�tV�9,/���TD�%
����=�%*!�PRl��"I>��#��3�n������Ә��.�q�
�0�e�o�_��4c��wF<yC�6����gvkL�Mm)�K�q���@��y0�
� �V����r����i3���]r����Z��1�P^� �?qC��7ې=T�����\���t��!;�1�G����̰�L�]���� ye�(�ݾ�ƭ�ܖw+G����2�@��F��NK���J#XG2�H��ke7�[=7�BX�`�ӕ.6B���$�'����?H����%Fʾ9�H�{yp-�M����R�_#�	�0}�i�u@���y�n�������x5$�,�G�b����gH�瑦Ǚў-y�@�,q�(��x����"��V�.^��e�1#�Rg�7���[�� �}`l��|��	�I�i���]��BRЌ$����e>/R�.�ǈ(4܃UY���P<o��ʞmK$&�	�Y���@*?�����H
̺�� k������N(8ήE�4I�CƁ�1�
�	z�ơy"�$��>�)d"	�I��T ~�&�k-���� AZ���W]6F�Ģy���r�/�k���8����
�Zŀ�#7vW�if�u�*9o�%��IE��~�e=S��'�Q���w7 O�'�Ns��l��UA��E"㌦��ND�D���ZR�N��K��_6���B�n�Ԏ�,�}��kj��^��UU�P�NH1�4�e*��Yl���Y�������N/:+�t�.�G�_�q���|�2�#�W�@]ѧ��t��$�r7� aƅ���ӈ0�@T!�X݂����	�RUXgJ�k)�Nt\A仜���5X9��ްu���Gt[����c���ٵ������d덐��8��bƬk$l��~��pK~ThFW!��'6�je�>�n��vKK3U-	$�7��f�tin��[	���/�p 	Z�x ���⸁�ц
2��(���
��1��%�Š�Ke.I���V�Z�1�oG�j�wm
�X���(�!bȂ� )4��e��1b|P��`�2��Jג�tqxL�_x��#��x/�����,�yYR��b)*�'g�mJ$tŊ�NmC�l��,7�e���de:;7�G�)f�p�D��oJۇniz��۷πY�;6_K}+s�M{C~A����(�|~VѪv+RAj�eV�ӗ��W;Ӄ���H(?M��-�mp���m��m�w5��䏟�hQWl<�3�i'�r�Ȱ@�3=ҡ�P��+}�������#�k��%�}��y�_�-�����h�QABl�K�:5�4\���E6��R�BPg��ZՉ��Cŏ������*��+X�E���P1e�R��e���o�;��ݝa���f$&�"�W0��6C�����b�1�O��ӷ�_������a�N_�1��Q#����;qmÌ��^��L����Y�����@hPK8��0t%�4�x)婝��oʠ�됌D��a�7$��]��$=���Swi�/��-����(��>L6B�RL������k�$͎X�!���.Q��;C��P3���h+͕����۰<�++Gļb4O�����uE���\q��)��l�-���019H�xSژ�P��=��Z��M<Ռ����xF��e�K��,;�T�����YV+�S4_�X0�َȁ��*�&�9����c���u�MQg8S&)�\u��+1�����lJG���D��.���qߑ���S)ݒ�1�Z�������6^y?� ��>r���e���N
�]}t�c0:�����e��r�Yb���1Y�h��S�������«?�{��(�Z4���sKV؀����e,����Խ��4�ފڝ��i�;}{�ݡ���ڷ1��1�L�O؝6�u��oɍ�I7:��uj�Յs�Yn�ſ�h;cG���36��nϡe�w1Y�CZ�/㪞���
�����ebu�2�	�p�E9=,	�ڨ[4��V	o�����ӎ��0���Ov�:By�I$�ll���Ƹ�cÚ�$�6�)��ě9�Ϝ�.�tf~���o&#�O�୎��.��[&@��,�:ˍ��
f��1�5�	R_^���[3Ċ)H�]��3�=+i�r��^N�ȏ� Z�#E��{���h[D9�}��s������1H]7i�ڦ<0_Ӭf`��5��N����O��fI%;�J\�s�c�TE1���l�8j_8ȁYS��0��Q8Z�÷/�s�f�OpȩqmÙH��C�oO�\�&��8˃AhA7�QB�v�*��\_���*zOi,
�6�Q�UD�Q<#�g��@��LA#����> ��D�a{�t�(��c��ILzZ`04P�,+��+��������u���b9B��3;�Y���$zCe=�)`�c#���Cu1z
�ĥiQt����󪨪 R��U(nM[�Rq�܃�.��ya�-X�x.WD�>vWk�O�9�N�U���BQ6�؊�!}Z1����6�0�u��ؕF��)�7\�{�J��.�h( u���gP�_��XQ�H�*���s�c��MM�9�O��%��-ES"Ҳ>�V��JZu%��殾x1���G�k�e�Eb�51V��VC��KB�b�d�ҝ模NF���Bp��垔D���#�7�V|���$�4��t���"���P���,o<�L��A��	���5�vg1��Z(*妳z��9��Ė`�6d3�����^G�����a�Mf�<"�MG���w(zH���CC)��wx�\����?�H���"��2�l�f0�V��&s�%��ij
���5v+4������GC��TX4���HG���7�pɂ���
+�9�Y_~��RbG�v�A�!�wPV�wt����he�;@��m��әEd}O`Et|s�.� /(��$�j�$��H�� &�f���L���q�J�2Xp��Rj|�~�u��g$�E�)�[�F� }`����tXNQ���Q;'#�֨�T4�#^B����&O6�G��`V>�5�JCz��v:d��ʒc)h#ﻠ�����K�_�>>)��h͛�S�z�[��Q�jR�;�i^��0R}ϕ�/~,�&���C�0_�^�A��dI�H�y����h��msFvţ�B`�<�l�08U�T��������4Tn}X9���/r��unT��~v�Ҩ�%F:�ʘ�m��ſ�Q���x)��Hwm8�U�D������JqX�X��f��>7���*�<*U�A�ծ"���[���Џ)�(q��S�L)*T��{��Գ������Y�i\�8�Ll�1L,�4R%߂�T�� S�7%�h�;pl�}S!1�>���������0��uF5b5�D"S:��D�rQۨ{��t�O���E�s�J��'l��3��:'�G�G�M/�Ȼ���|5�V7Ü�˵�l��&��'4���5gr���ղ������Jj࣢�E���mh(%V`B`�y��A}Rd�������t�(������(�5�;YߴO4�2���y�z�O�XUQK���c��ΓG�p�?��WOp�J�Sp]�J�$,@˂T����9-!R��JYd�r����Yd��R��T�|w���)q�!o�cŔ�G��~\��:�J)y�sc;�:���C	7^u�oGtT�_�ȷ #�g���'���B��f�9r���e��X6j�l��D��]�!�bX�ME�w���bC�k����w�����$��&��p^�.P���:��+����r��|,�c�� �s���{�Oz
�������B��x�CP>�W�?ґ���>le�����������ne=��T���L(G0��-�!��,��U����|ՓJ���@nac�A��s.�� �$�7?�t�2$���c�*V&0ϫ�^����38�#�N�{?�+�)}s<�O���ex�	�
�������h��S!�'xQ��ʉ� v��A��aN�>e��P���?`��쳈'�v�7#L�O�C���垱7�2`U�g�A��ÇV"��!���,Z�[���F�Z�|A:���C��0�c�bi�ڠ
ä���^��Sa�Pέ��R]��\�Dǰpw��:�����|��jQe��r&�]�_-8��Y��C�g%s%s��fw�(q��a����-5��ly�-�y\n3�3�M�`��K� �~�0*�uw�d��y��yN\!�����`��Z�?�6�W��[{��VjtG��vh��z._Ns{�كzӓ�Հ��)���e�(��
�]8�y����9vԝ�%�N�M`X%6���eM�w����ΐ������7$$��P=j�4� aC���%�M@�0�!<ֹO���n֛k7��u�t�?�fǪrx(���/��(n�A� k�$��7E�$^,ܛ�r�e���>�>�����I$���k�BU.X�Kfq�A�f:b���m���U�������H�!�sD!- �_�G%��zo���z7��*XoI��UH�y.��و��X�F��MF��M�k����Ǌ�9zT���ߵN(��C��8��:�?K�� Sw�r� Z?�9a���Фֶ�Z������_�|5˲Xy�zH���m�][��*V��uW���/�2�{(�7��A!u8�~���'eh~��M�����_�T�W�E �$:�:�?\)�"��r�"��<��z�v�b�S�<�c*���&� �cT���F>�+V_�%ۡQ�}��kV��v���Ԍ���T˯�4���{�[V=��h�"��uF�rI���@}���i�N���n�L{��g<L���׫���O�塅_o���܉V��(��4�S��=�&y��Н4�P�B����O/�I�&N��4��'�%�P�L�<��0��_Ĳ���`��QC����!��`���?��!2QBX�%�T0�1�U�U_���doY�UE�-���&�ZKE�܊	Y��,B7$�R�D�]��0;Qꇖnݲ�Jr)��$ba�^?*,��Ђ�ͅ��'��������4۲lB�PL;��YJ#�@�Q�9����� �i�jh�x@(���F�X�u�����)ނ��+cF"����f����]Y�r�Ww�l*'%h?�[PEy;3�aiH=���X�oD�؁�R����E���������Ӊ��0�hh�/��^w��h` s�'!i��0�}��B�4�{	��$���XҠ�����\/��l� ��ʭV'�=�	��O�a�+PG��NW�9�b��+�_&�P��F�M�Q>~�a����
�R�8��"R1a��}�)L�Q]PR��Qd��LR �]�%��O'�52W#�U�*�����%mIh!vIC�-4��u}U���_�RC	�W(*��)	�+���|�:H"�\��+�m�&��%�A�T�w�fj�#�a�uɒ,#��(+O������ϧ�����)"�5��XT�L�Ԟ��5X���I��W3�ޭ�j� O0��b�}�k1��N�QT���p�IhY����@#E
ֆ�9�<"�߰	!G[�3QO���-S݂��	�=�Y0���	���
��&�VPx�ǯ]��U��/8a�\����6���uB�$쯒
�����U���} E���"�*脮W���2.���W�U�՗t+�^F�	1�˄�&):*��f +�2���W���V��IbB�xM�@C�dgZ���4"Y�����ɧ�"�b�8��x{ar�SZ?ЁF+m��M�t��B��9 ��S���o��-U7���)����J�Ӓ�2�������-e��2_����vz�I��Xԫ�-BL"[�� ����a�*F���4�c�@��0�4��5�@�D�F������C}EޔL��;�@���"�ô�3�_������]�M
$�\t�C��l:�.^���t��.о��R�%U��h�\�J]e��Wmɚv�;UiE�Y������),��Ә[|'�
Ǒ���'� b�k�����?4��:�[�#A��3��ҏB�b�أ��������������sG��Z$zrq\u��k���3��ܒZRKn�-�����"��y��pD���W��ҕt'�k./%���fl�x���-{��	\��d�Y��mp䲎A[kW�\��Q9 �x&���������B�+����[�K�%�!�nV�Ð9(I�C�����`<���`?O�J��[���i�uQ���L��1��!gU���5:�9�ۄs�h�|캠绺x�B{�&���u��N[mIu�a�; {?hڒU�[�'/����K7�齼���!g�«�Y���l�(���b5�x�z��@*9;&uۥ~�z���{��ҥ|�zЖ/]zy-+wq�z��dh����_˖] �s�f�v;�w��9+�!g�6�� ��ϑ�d��r�t����g.-H4.�@0]q �q��*+a
8�տvu��=�"�w���Sܟ�ˇV7�g�M�i�g�zs��$X�9�y���s�So�9GO��B���?�k�!Ng�z����T0$�Dɀ����sA�Á�3���IͥyN��8ϫgd"�xٳ�J��;��'�����9��1д9oV��-��������j�������}�a�l���C>Hc}�����U�Ř7BQ�XS	�s~��B�?���'�g�GΜ�<�������2v���N��M:�h�{6��2����x�?G�{T���Po�w������M�����F}�a#X�6�bys���2��ds��2Q: �AuG^�	��-6Z�1Ԛ���ٖ�����H�Q�-�`����U�8�U��ǀt^(��#�8�m�HoFrE�����~ ������y)���t�k�_M�����2:�8�l�h}I�@��E�����Ժ5k070�aX��}O�ٞ�ζ:��Rɺb���D�����M�@L�}��M��o������=�AW��J�,PkXC|�U���*���3����l� ��Rp�}��-p�>��C���S�Җ�����r�B'�}�@�ڗG[��`�T�}<�~�mϫ97�)jC-�
����9�(|(
�8��@'��IoDW'@�2�#�q��2�����8�!O(�CEpg�Y':�M��?��\�x��>����輐��Rƛp��=+����|飙j'�΄n���}U��FlN�W�9`�~��V>����w��H@a��}�<{/^��2I)�VVS.�rK�~��?�I֔
��󵧪�ήO�keܔ��� �mv���`y�ޯ��$�D
��<��y��%X���"`�H��I�k��m6�ǝ�m��r�.1�&{������L���
�n5'��ҋx�s��E�
������`^>m���V�/�{kd�>�ۖ�呮�f���t0�b|���ª�� ��\�x�z��b�Qb^�u仑�;���Nw�EC�X�O��|J�*$���(F�IV�6Z�|��$`?b�����R���<bh�\w�	��2^�=ue2^�l���'u�c�ʸ��v+�� ��)\���|Q0W������e��,����C�#]X��fD7��?*��W��* ��A������A4Cq0�N�Iس�����j�u�/sZg�	��8m�X�|�!d�-\��ZF�����-s���C����C�'�1ʙ��(�s�����R	�!�d��9ְ��� -�O���Q �j�0�X����L����1\����pb���^?��ל3�k=&��s2��Vr��kLJ��ܬ'^A�,Dڸ�X�t�:W���;sf?<��MVNО��=�!��">�Qَ��Z>j^;2��Kq��C�4(�~��Ac��)=�[(��Q%i�%TL�k+�M�{H�Ɲ({U��5�%<�g�Ǡ�o��LB��Y4�/S샕��j;��ɚ�ꂤ �����5N�o�Q�1݈<$x?��B�d/��*�i��)����}�i:�8��ɁR
ކ�:�,����l�� ~=3��gh���Y��W���k�2:�O�T�l�a�2�J:gbf�$%�E��+��r�%��D�RWeuæ��E�<.8�N{T�Ll���@!�L�IMu�)�_��T��m��q��A��RoE���T�/W�'�!�f,���&a��-d�i��%��6�J!���1K�M���.AUP{j�mq����}�a�k8#�|G�� -\�G���i:+����yM-9Jn�$׋~�o���)�]��tʏ���"�f����A7�R�\� �$\�r�9ް:h��0u��ËRD��AEyn1lȴͺ$*9�b��1zv{��ܢ�two��n
���,םue�`�xJ�7�I���=S��,B⛀���g�	[�|��ɶ��v��9�:��>�=K��ϣ�o�m��^�+������I������~b�V	�,K0%�:p���Sz`��ޝ{��s���߿��ɉ3^��uwt��������ޚ�L=2�Yi��湖����.8G*w9c����˴O�u{#x=]XA����	p w�S�2Z���'eX�/)�I��=:�'l�wa��S7S��!Gw�2��k��7���(J(

*����$�9���l���������g{�;����|.?�>_�
�3-:m�l<\�%*��;���$� <4�0�y̘�����{�a��#�k׹'�%Wy㾦�{�t��q-�B�������؊�i�s����W콼��+">��L\z��c�{�Eq��c�q�kh��GK��_��0�Q]��c�a2cz	�3����1]+�x��
�Ϙ^�;��5�L��֜��}�tM��5�5�!(ැs�UeF�~;�$~7�ɲd�O}�����t��,L����5R�L$':��V����#C3�mO�v6$���N�-;jh'�y�����8�/Ih��:����lV�:�l]�7�m��Q��h��O�yYt͔�����vE�N�6���&#�"�;�G�e���W���%��,v�,���R�MMm��9���Qz�qy�`Xf��4U:���
����N�Bg�R���R^�ދP��-U'�&%��mC)�(X��Y!տT9�$c[a�0�^i��/f����:�j����6r+(V%��(���� �t` ������'4۪tAx�x�)|��-f�cE��7��3<UG4b�u���α��d���6z�[�6U�-���J�p��M��#� T�՜�G�ژ�[!� + }C�������'��R��_�P\<i�#d��zX
�fM��7Q��?�Uf.*��\����|u�.��s�!Vj���G������ʷ:�CA������֐�L^���F�O��,4��_��+��� A4F���V������?� ���+�b3�P����Ɲ��R<�O�w��Q�I	3��lg�I�����1UA����z����� ����a�S��&�.��{ ���i��P�hq "t��F�3�M�� L͎V��x\��A�c�n�~Ot�������q��������{�\���-��~��D	ٹgT�:���~'��`�-t���
ڟ�k�[rX�Gl2�=���2���nw��IY�I��2r��	�
�D��v�4w
�pNh��2k����@@V��>1�4����b�cv�NO�5S�C�Y�8K�Q:X� cU!�/Rȋ������\�y--6��6�0�¢���L������Q������Dp5k:�
��0��!��W=qQ!�D�z��^.�8z�����1M�p�P E0��>��zI���k9w���X��5�%V�N,Zf����:�������*��D$U�G�����24[��(s�*��Rh� |g����<e얊�_x�ݚ��4�M�t@�ͣ��F��$�s�X����xNs��V�Kl��G۪���*�yAZ �u���)����Vu���Sm��{oN�s8!X'SH���)9��ޛ��[�2ӆ��X�1P&������\�}6U��Q�W~�\I|�E����#z�ˏK����wE��%ɰ~R��A�zb��~8q�x��z��Ì�F�i�Q�SM���f�T��o�f�T{CI�'�v.S�%����!xZ��;>v��!6H�K|Z���(�4��T���yTe���M�'T���
�l&���7�>�SB����$� S�n5���c"%H�nZ,�5�'x�+{����]��I��?����>>6�8��c��-q_뉪*���C�^��>���"x<4W���,>j+���
v�:�\��X�I����{��]�����K��Z���F	���BY�|Jm���c{7��(��|!G!g�$<O�ڤ���/t|�&WFέO��!FXu{����G���_P�`I�7��$�p:,k�nC��5�2=/���7X>{_f����+ʗ��,������������
,U&��i��YZH�	;OZs���fN�����ԛ��,k���ұ��e���~<K=���B�221ý�22��9�Ͻx� �g�-��D��w3l,�M��3����Y,��;"���8���uDr���
��`��H.[/�*J[��i�Tgˠ\ݭ���w�Ї�p��E�e�j�P�y}���V�K*,��:,��2��Z5K�}/���KI,�CS~�`R���sȱ��X�OR���iJ��|%ŹbEmҪ�����)���n������K�`��.¨L~dB�e5Z�:6H�7X�`�R�LJp�z-�sI�5w:�ͽ~��'���X#��%�M�d~�/v��ڔď�S�g�=��U�[m-q��s���&~ftf�C��f�1R7���S�;�ҵ�7�pP<�h��/�Ē�F�M��yΚ7]�T�}�0WUԐ;꾗f�<�K��Nϐh���^��9J~�i3�9yOA1�����DG"��}���;��+hd5�F�|�!���n=g��a�(�D�}.~�D�~į��T�S�Y���-_���x�f5�C��sL~zα�Zn߈�����X�)�-�vQ����I���ܛ������L�?�fk �R�"�Q>���9��s�"�o�O�`��:=$O�t���Ү,�Hƶ�ң�v�-���K�on���F�{�x�
�o���J�m�~���z�|�n�6�����c����?F(n������-D��f�T��~c�ז2H��P���`1^�Z����z�&IĔzq�N�?��o�m��h����b?!`bc3���!we\�4>ud�����Hf��r[�rZ`��a�[/�v�
�#?Z�4�'�WU�4��͵�f� 1�Ь�AX�N�>�J����V�6N�iG���	{~H
�������Q�Oa�H
)�Lx�2�CM�1��nB�6T#h|��U���d�z*�V=�e*�t��2V[<���6Ⱦ�e$!Ǝ$��U��b��D�5���]��a9��
Z�+��Y��cv,�//{}�}NQ���Н��Qd��ẕ ^8>g+mw���;��C�/q�j������9M�a^%�F��r(���>�x�#1=�3ۛ�&R�O�����a\HLj�����S�����b�:��dv�zBߣ��z:���E���E_�2�y��ǃ+�����9mh'�.����K<L9�4�y�U�~�8w8jfx#�zl&�)	� �冓�*c����/���L ��"�w3 (���t,�n}��~�`��p�Ht���AL�����rG����r�?��N�أ�Kf��#��y��߼b �4�9��j��dB�2e��|Ap���2i"9��xm)��0��q��i���u�t� X�꿪����C� �^ʵh}�Vk�}M_{�Ee�����B�VK-�����o[P�c��/�Z�_�Z��#�g��5�n��s>G+:��7W�0txJ?a��^\�N�O�j$ZY�h���\:OU�s80��C�=�	��p�'�m	-�}A�}aj�E�iE6�dȤ����[�&r�Ce����3Z��Hk6=�,�O�̭Y�Փ�OSw�����E�蹻#B���ɠw��Z@��\��D(v����H��|�3w��tN+���;�"	���uj��#I���#�u�<c�;~��w�����^��{G�~��9L�3/'{��r���khy����:���ҢsQ�����+T}zס��0����Su�I�����,�P۫VH��L����ڽ����K�:횂y�Pv&
o��p�����A+2�%m��d5��D�[��W�`�^�SY{kڻe��4��V����ǟ�f�ׂ��ʔH��(LH���L�i:���O��hv����}�����&�]�0�<\����)i�Y�8x��9�~%����{4��uW�TRe�s�9&2��y%�_Dc z���n$���q��|��}T.TVr����Z<L}�_��3�Ik�Y����|�=���A�̎|1�t.vx��d8.�����#sF�����X�P�1�p><zD���mW��i��l��O��U���s���;��~��B�jv{jm�.3����Hr� ˝B�)J�pv�۩�}�!���J��nTAUJ�fd<D^����ʆl�(���M�(�j 6��Q�����+�bۈ��	���f��༏���^��o�rY�`r?�7E�r{����:_�?��{��x�#���&�c���;���i�=�D��Z�iv��a��57(K���S�d�+OkM�埞t_�n���8��5:D��Ďx��?|4--��"��}Y63x���c��� ��	��&FMdkS��AP�,=�m�毕Kl�U�#�ՙ��e�������#�-���fD}�������3��)�Rl���zC�1bV�r���H���-a&��@���q���e<ǀ�e����|�OD�[���ȿ��C�w��7�+�TC�/���D  A���;֫����iƢ�Q��RE�_¡*�������J����B!��+�n��M�'@)P�/7$�`�n
�
��c��y��� M�:����Z�l�.�E��8}$쉴�1��R����Kp�f;�GR�hZB���F4Z=C����~lbX�j,�릕DA����'C�VT���c�UfJ�S��ns�c�T��2��A]O5N��W����L���u������e^��n�l����ԉ	ui:�F��E�Oxp�s$І>�
zk[p��7�i:e
C�����ȴV��92��吐y��Yӹ��8���z�B�� ��8���)�?A� ;�@;���Z9��5{j_�	!W⍐�6�-y�C[kxSi��P�ZIr���:�˙�ȴ�I��n�����_&��ԑ���Þ�p7Aޘ)2vE���~�O-=�X����
C+�ɓ�4ͷ�E(�y1����q��&g��J9�6�a��X��y4C(h33y�T-r��)?��ϩ�M��d=i�*�85�1㊬�3ݕһ7�3KG糅��B����)���(a.g�
�Y��l�=k%�����j��u��M^��@��3ЦE�i1D�a>o)���R.�b�3�K�/�����y�0Ss�N.8��<����7�.L�6�=I�g��hb��7U�=A�#Qu�b��R}��ʎ5�{3�z���2�JUl^ln�]T&h�$5O��X?]y���Qx�S�Q����J3�$_�B����#�Z�:f��ڜ:�!�\��i[&�����Mj� ~?p�wM��� Du�g���8�(p��߳��C�-N�(5;}a����s(B��Nh�SY�0��8L_~�-v,��2�o$�7��$nU�;�����o�)������-���ns�BX��	����O8'���W��~�` �ɢ�����U�����}�'F��!⋫C���]�!�`o;I��lO��6�|bFs��+���X���lK_(	kto���R �P�����jxD}����e'�p��%{�m�]�e&9ծn~ۘ�"��A��y��a�k�d��Z?� E"���cK�&��VT	�!��Td�*��:k�*�]K��%C샀���@��GFV9�S�Z����?���D��'��x��Yd�M�ׁc��Q� 4Z�fv�ĺ0�/��L����>�K���%�l/��U;� �I�S�]Uoʰ꺹��YQd� �H����4���5�F�x~S��aC�ӫ��h͊�V���nĽ�?3<S��nT�p2io䲷J��,J]^�����B�ʐ-��`�q��cq���;^�/��'���Nk0��ݤbx�>���UU����$�p�"���ԙF��g��7�!�+V��H  ��g2o�kH<�ӓ��?H^���p�k���p<�C�ߚr�<�ѰL��(��	�I)��2�f���D��:�P�Fu
L�A�zM�1����Ċ/�2m"��a&��v��]G;ӏ��4������p�~���wM��} ' �J㥹&�cȺ^ �9�������I<�&NtFI�����x���.��*�9^�:��]e5�7[���w.A-E�$p�xÇ�#[�FȰ�!Iiv"Y�W���:�KjCc}3�"���]��@Գ9��\5esp?��d�}�b����"����+�o�A�"�
�L�7��3��eC�˷\Q h��1�"�[i-�a#��nR<��y?���tjf�pv������f�oY�p�/R�á%U骰f�Uh\�4b^l\��&�3���v�4}n.�C;�弡�Ľ�	�%�����b:�Ki W�"o��;�~�����d��;\Y?�G�ڱ��z�Ѩt{�S�����r�8���}��t^O���+�NK��H%<+�+F[�;�M*�s��5w����.���/҇�aTbn��خN�fD9�[�#b�P��;�T��1�QuD���;��.����@�Y�� U=[<"�m��Ub�nqi�\T��#)=��G7���a ϔ.F8�$�Q��ը飫��N2���	��R�s�-�C���.�\���aɂ�l�d�|�k�&�r0cG�$�C2yʳ	1�YU48*&����Ks����S�Ձ��Z٫7S�Y���ւ��!��h��Iέ�x[s��"��,�ɪ��t썯���I737cw�=r{�c�;�����k�[�����������M�SD&.4�	�E���z�R̅���J憆�B�v��\��y���pf4�X{�_J�M���̷���]��C@-&��4]bA�boA�R� r-яv�+�l�	��U����FA損CÍR��")^H��@c�{��ה��4_������N#[Bk��i�T�(W��@E�fC3�ڪhEKMb��\�ū�'�7�(~"���+�^�p&��)L�� �$����s�pb��)�n3�OJ��ǔ.8}H��'���z�ss%ѹE��'`��K ?�9�#��72|L�e
������ՑV���!�+_m���h��Hr����f�G�v�"F@M18d�RI޿=H��Z���Co�� *��iVJb��_#Qá���bf� ^0�_o8j�esԆ#.�kw��i�ի�TJP���M���0k��ֻ��t�p�#��K��H�AQ5r@�Έ �cl�
��ނ�_�3pik3��6H/����T2b�0�#�P��[A�R,3���]kC6<7�GH�0�N�F�m�H�b薕sX^-W	���?��
G��\���:+��u�-B��;��YS�b�y��O�@DQl�x�*��_]�f��yTj�^���o�b�H]ӌH��,�j����r"&�����$$:��;�։_sH�������%[J&�rK��\\T�-|M�Z����vI�z��X��bB##�cI��F(vM{���Ei.�>��C�0�=�h�v��cG�fh�D��f�����q���о������^m�a���	�6�W��N���sF�M-�X�lM���01�ba��R<��<5��l
^�r�����5�lRA��+�#�-�Wka]1&����"�mE���ey�4a��>& ���2¥���A��$J���8���,e�._�ٻo�Y05/e:!Gc�=?eʧi�/ᨏ���/������:��L�$s��LiTΚ���XJ)2�8�`Q����*��K%�g���$����_�0�$���-A��Bّ��T���E�'3alrn�|�1Fjm���`�s�Vʅ:��PbUA[�;A��?�ײ����q¬�y9H�j�Vv�c�y�ܷ8���`!��C�7mru/s~���s�w��v�豤�C�;�E��҂����B��m����w(��}���k����O����v���;?�y�Ѽ��V��;�{���h�U�nc��ީ�<\k��X5Ͻ��a���4s���~�jۊ��w_��u{v�;���W��؊Bg�(��B��UR�E{c�Ѯ��n���^��Y�s�G3�Q�#g��ެ�c���vCl2��W��&-�
��6h��ĥ�Gı2�n++S�d�xX%���pE5�q�C�CR@�>d�;U�ח�xa̙�s�ߵ�����t��3;�UӾ}����\
2Za��Vn�A2�+��:��Y�4(��#XiEu��
x�9���K�5܊�X��k��%�"���(�I�C� 
���`Jc��𪸒�X�CԷ�9���'1X5�%�����DBZ �?�r.sNw�v��BY���9�,�2/��v��/��W����.ʹn��AY��~�5������Jm%�%�J���Nw��b$�G��K���A����~4�T�ݔ�'�ޛ�r��ujP%���-�}||n�!_�[M�_�F�`��d9���	7�Z��d�Q����<���1V�E"#�,��%�<����xF�1�c(m�����|���a�\��q��!�iX-l���1�V���4;E�_@��R�b�ŋ��ْuM๛�;S�S�eKn:mź3D\G�]E5HB�GsL��81�sp���j��b����'�k㺀�F����U{�U�����W�?XHI�
%`�zSIG2�=<�Bt_��1�·M�����%=r��L$����+�8�ڹ���|�)��G�a�N�!�)��"B�B�6�z:������
�0%hHR5��9�6q>��� ,�n�`3ѝ���1J������B�ր�ωG�_u�o�	L�\�#+C`g��ŀ"4��D˽�v�h7!9(l���v�W���W|�[uP9���S���?a����@�tZܣ�S1��࿪����͏��N�Y�{ˑ���ך��qe�v:ZH��v�%f�Sr��� �2��d�L�f��6��ү�|�ɯ�/%�6��L�I�4PQ��/�:c[�~b]�rQέ�sg-'�:��v-�|V�l�T\HE3�04�Tw���d�� !�O�
ژ,��wD��{��l��OG�vIY�R���b��Nf���nw��]��Cܸ��qa}𹏶��Uw���{z�bs~���I-\ad��[�:��o�9�&z�V��<g�V������ܐ M4���+V
��=�M�W�T9��o���{3�d��~���Oa��-2~%d�Y������+i�Y�|+L�ѯ�i���ϒû+�@��#6է�d-�˵
x,d��5t��.%W,���6F�ōg� ��g�(���]e,�� z�[g��E�yů�H:2�!\j����*��S=��bM�0��7�������F��A�OG- ����Һ|`����]�Z	��a��o�������Ӥ!U_��j�uROSɜ�^Mu �Ct���eqQ<b�,ő>FƊ1��Q�,,X��Iӱ�&3ٖ�:MY`z#�j���dO��v���i�U~���[�n�-r؉��TmJm�&��������П
ݛY��}�"J�h9R�J^�z�FVU�T4��
�׵�h��>]��y�C4�F�����k�s2�A�N-�|�$�\k�(~W�t����*4q9g��Bz��	a+c�u'�,��q�-i�����=�y���n�fnn�fQu�������[�f�e���1���(�/����'�� i�v�}˫�������
�UЋ@��,��[��1��V zx!���R�2
�&�.��4�Ѥˍ�"=�P�0����Lp�Y��;=#�Hb4j��/�1���10�d3�S�A��LZ�9R�
ȷ�빜s�{�11�+�72�h�1�luk`���ީ���"�L�G��[\Q*ی�!y�iI�?��\8�LN}!C�R��Ɏ:Ag�2<��ݲ9�qwpK�d��̹L� �W�������áL�Å{��ƭk�+�ᝈ{&�cmE��_͢�fN�ނXP[���#QH���<�čG� ;�#���!��������cM����*�4/r4�U������`2T�I�1�8�0������#��#'~!*e��~��M:�ܤ��"	��67�K��yd�I�K�4U.�����X�b:��#V�S�	&Bʡ�?C�#O��|Y�·� �b����n��Ӎ�]��	r/�ΛՐ��x�O�3Z
�HWB�m����)�Ҙ�΃�����6�6���o��lo�W�6�8�;���̡�7�e�oV^f��fG����_��?��������[,З8��;ɠ�7���ﲋ+Ϸ:{Xyt'���Ͷ4x�� byC��7R�3{MHS���u��T%�sٟ���g|%�!�\n+��y)���xY'9O���q	�u�,Y��k���T����'�m��9�n�τ?>� �R������T�-��D�v�.s�?bR�Zh��\��^Ť��WE޽r��w�{巟K�=8'
^>w*�H|ҋ;ϗ+���[D)�i��Z�z�ܮA���I�Ǖ�1����3$�ȡ;'��� �l%����9���wA#||��V���w���&��|�U�w5�$�֦t`���iL�2���,��_��@�|���Wu&k%���.^�>z]�g���ė��@�*�x�)����(a�h���^��Z�tq���M;M�s��ը]�9��!W	��|����G��0C��%���8����[Y8=[�~ޖ������2�Jթ�u+�յB� ���%!����	��ys`��Ęb�ʻ��Y��@��n����EPL�����d�p9���N��`��LX�3�:�_=s�m�	�����������~$����6ǂ����.qO�J$�*I����~k8+��?�h𝄃��T�lP���`���6B�>�bs�ث@a�u߄25|E�d�4���TVC��ʄ?()�72d����7�����M����5՗M�g�!���a�L�7����P?�+O�8��PH�>f�-��¬�cd�&��heu�{$t��,�=F���R�X����!#�b��h�6D�{�bT�u�~�l7��VX�l�BA֯����8H_�*5�6�%�2x��ɰUm��G��{�������O�4�:����.��K�F��T��ө�kȠG���.ҥ�����_St̶�ɹi6Q�L��~��Q�ms�D�{����Z�&�b��Z��l�?�C���y��mہ��))� 2&r�^zF֔==]	�)w��	���K�FWb�ٖ����)zT�d.��#E]x�5��?r� �4�̀�NF�''�1��1̜�+9o��RZ�(Q����Y�K}L�%G��r��ǧ1͕2eh��\Б��?S��3L�o��V����-"�m���6U���^h
��Vs=V�>�O�c�񗄹�A�&E�#c0r���Ȫ;Y`�ً�4,�G����V�cJX�*{3���&�c��+�N�Od��ې���lV�Ϙ
��UQ?��D���mlޟm���*DLr�lW������Pfm����\^UM�����Eu�ۖ�p�%�e�[X{b�&P��Ei��uk!�dH`*��!�Qޘ��"��a���2�h-E��Rd�#0އm�'�n��f,�>�^Z"�aqc��k�q�R)F�w�w���:��	�9��y���������hYbM9��
�D%L��L#��
X5Mٝ8}�Q��@L�A�&�����;g�t�XVcy��@�C�7���RO��OLpʻT��NX��o��{~RϪ��~�~6Oyt�}<b���T󵙲3���n�cNְ�y�z�s�r�șh��/T��=-�����ꎍE�{������x�.����j�Si��['N$���,
���L���Vk1��QA�
;8���:��OX-�\�׾�&�E�Z1_�����ʖ�ɌT�x���34ʑ����}c�}Rfd7�Q����S�{��4s��v�ۧ�b;���ZJ�!����'���A��_��;�P��J�l�C� �7�F$�����5d��`���3�v�<>�Uh��p��&.���K*��۝j��x����u-�φ�ez��6/��N~^2��V����<��ۋ6"y�1L_\.l�<[���wa����K�_$��]Fu���f����������L�UBd���ꟛ#�G�X��I��D(�_��s7ʭ`Q��G9��}z��̡��im� 
 /���}A7�f<�{vC�j�eUO�KEN��A���{�ק������r���
�)�̈���|��	�S�rS��D�>�F53Tݱ��(�ů��/�0�!oW�CI�C�=~12"<X����J��_�D��*����s��1��w�_S�O�K��x1!>����J��L)(���~�st]���w��h
�Q#遃V
Q1w��e�
�G��j�YvC&ޒ־R���x��:ic���b����s9��ԛ�a�Y�?���E��[�D���c>�)D��&��Mx#��ۋ�R�kN�>����� V��±Jq��4�D	�ߪ�]un\9H�OC�������/�p>o@��6w�n��A+��k�W�4�p�^Wо��� ���,�a0c�.�;�M��|���0P��y����1��L��A�X�(#4�nWh>Hږ
�=e���Bv������ȫ��&��zN��ǲ��/�BF���ԧ1��Ru*�ĮD��~��Ν-h��.�BA�Z���.k�4�R��U�����a�Z�/��9/0@�yz%�ÿ���$�f9��Ӣ#H}�0|n��wС*iV@|C�z��N�dgT"J
FW�J�����a�S�h��e�����q��2_�l���IX�,��N�X��L��}��V��sF�1��5��0��ӂVr�t�K�3xAv�5�d�� [*�w���p^_�k+\�����n�L��W�	r��v�T�/-��P��hW@���*�z���>S�D��Lv��֝J��:ڂ������5����$�ˠ����!�M%�W?6���F��9]Y���h3~�UMUߪ���H�I{�W��^;�A�BX.��*��UJ�Ш����VI�k�RʍD��ٹ�������ȴ}fN5�|����^Ef�>.p8�-Ds	:0�n�M�oʐ2W�v�"_f�mW�~z_�N��hm!��~�C�@z?���+SX�$���#.�a�Z�7F`S#mlV�ȯ��Z����X�v"[���˂	^L�>^�4�T���3��>E����-O��p���vC)�S ���$K�l¤�i>>='nZ)H �2�ݖav
/ڧj'�3ėVJ���-�}І�:���� V
��H�Rv�V�{��N��α65Lŝ�&���~�-�͖6��)t�	ߎ��]r㰋��5�,Qp'm ����?�G�١1�O�N�тrtR۶�3�n�4V!����Z�E��������␣�|'���C�}�- �w�M��.��a�)T<��-B��݅��̸��SO��ߧ���G�鎠�^�[��͢����p�E�D@�vwIZm�D�dh�f�����˛�Ғ�v�y|��D n����ܤt	ik��������e#41C�񥭜Z�Q��Y�-p�8�ʁǡ����10�	��T|��L���!c`�~{-R�o��
��|�aC�к��:�CĆ�Ta�9��가�Z��Hڋ2����n"8�fA�3�c��ƾmk��C{	�[p|�������5f> A��/Uo�%b\r�
^��L ��:�,i��%���2���gewS���Z�?���02׿���	K�72�"���i���_��,
�hwf��F�m�c�(;C��K]ʻ	J����S�Ơ�O�dw�/�B5P��<�񦊇�f������:dF���4V������~2h_���&��wH?'�O�NǙ��^��M��坪0�읯�
��1�7$9op ���δ�d�E��
�SA�~�x��A+���"7v�5��[�F'H���>S��3^�_�_\Y,T�`�,�V�|3�z]Y���@qR4���ey<j��j�d4¤0׿�Bʃ#���m�� �{����-!�,r*DW[T�,ʪ�<�`=<C8q��mq�>�R�9IzHfѷ�G�K#VԎJfJsݿ�"�@�#	��=]N��Du	�Tm�_v��`�WI�@�?�!�M��]ߝz�q��$��coL7AS{�̶I�*��qԝ�I1�<�efG"<���&P��!ݑ�Q�Tތպcl1�=����${�0��¯�q_�pt����	<>��� ���ej�K4�j�Q�/�.��7sT�c�YW+�2k.��9������)�΅pR�
�JT������Ttw�rt��ff1�) ����	5̘�w�э�d�C���0��RW+�ncs��V�ZK��>x/�됸��^��bE�Y@���$��?�x.�J�0���:�L�_�>|����K[�䕫�Î���U�i���^{�l^��u[,p����9�#�"�O�
�~I�c���>O�m��ć4��G�*>4�nH3�Q�U�
��6c�=u�&��lTd�d�R/a���뙮مӴre[Ԝݱ���{UV!U�]�P͆Wwj6m���Z��^��%u�)�Ё�e���P�Sj�/k���=ץ���� ��N�3���7/� �@}�������uف�:UNU�՟^�ꬰo�p����1X�H;z����
�cCu1�2Ǘ�5P�=(+0ެs�|ml���V��5Ϛ1���,a.P��+��O'r��g}T�����8N*�:,���S�&mxd�-M8�o��?Z����#Y�AԒp&�*ZdDM�D�˒yRXyT��4#ՔO�� ��@ �pv�ܜ���b��E��USω���;O!Fp���t�8>�$C+����-X���?S#��+w"zvwr^b���ʅv�̷1G�~�i�r����+�S�2bb:�3yN�`h�y(�V�H`���!��F��i�cH�S0�}�M2ck�Dl��Gj$�ͤͦ���-$pb=��np� U޶����`R���m �v�	���Z��y�w���$�22)ک�XHq>8��6�
{�\0끸u�4ֺ���ݗL~�H��P��"�ɂ��8U\ ~�ᇀ�DG�&�l�52��Y���v����|�PY�F�<��ͮpЛv�����W<?5�\����Xw �%XR4]	��s��"�< d�����Ab#��v5���^���Fv�e�ڼ3lF"Al���)\P �俈'����3����B&���b�o�P��4Y�j;���%~����P���j��i#�Č]�* A*˂����4M8�����Np�n�=��4�
j��p^��K(�ʄlD1��rd�*�Wl��]L��Ϩ����\�14*%�H$#�o6'�����N��;!:�R�,k��,w.hS,u��h��S���?"�w�rc�H.7b1�&.pX�F�Y*"ͻrPFLLp�ód2�<�z�"Ȅ��"�nw��� ��8�	O�! ȏ3g�z�8�䉙����>��C�/��Na�Ḧ́�N)�i���v.G�f�309r���j	���tQ���t��aI�������-���ij��F,C�b
��t� �i��)�r0��I�ظ�Y�#�����H���D`]���*��F���
-���m���r�铠w�h.6�:x^b�a�g2����Xh�2�����N8�Ƒ���:y�V�&mh�ՙ�HttiJp���s9!ز��
�=�����P�\��J�w�XBq���/	Ԓ�W�t={�kmQ�|]Zx���pDnI���~J��(XY�
�6L��6�[�E��/_kv?D�s�B�B�wA���=bֿ�%���(|�j��d����|���oi6�,�~�^)�-���t-���E�Q��1�dK��L��-���L�j�S\il�Ұ�w�V�Z�V�/e�6��.&�p�Vo�L>A�Vr�R����9�l�)���-]��*�w��5�	y�� ��5+�9�zj�A�O�"m�2�6�<8��'Ɖ�6\׺j�R����|�tX�M�,�e�ܛ�1A �p*.�����ė�̻jܔ��}�Y_!tlxBp������VV{p�1	w��nfخ���~�>t� $�K�ZH!��5)�N��J^ �7���H��5\AĠV��.�f�җ.���%�RH��}$�`�=Ɣww_�E}c�9Cw�̢�\���������A�t�Zcj���˙�m�yA�A��mT����S��u%ƩC;�$�����l���<��\����bY�DLI�=�����0�l�䱐*�z�'JP�g���諅\i�����G��8�٘�Re��� ����H�`q��[ڀ��p�F_�&%C�S�ǔ$o�1��p����hdV+0+',^�aZ�`�����r��τZ��^��Bہ�DԮ52����n�Y�a�c�a�'z�9r�RȠ����Hx�J ��Ey����Z,�@���Z�T�g0�`�Q��^�V�V�k��/Z����0Ed�{�ʖ1�K�B 
�{�
��2��u�@uf���P���eL����-��@��D�E��P>�G�Ȳր���ɢ3�|���P������q �]U����F��*�٤��1ĉ��W��j���{7@"�OQ�W���U���cY7ը��+��8�1G��'����Ҩ�"�T�0�J��ר�eޗ�i"q:���"�A�P ̷Oq�5���@�A�Tϒ�W�Tj}�[�!So� �G��E\�>��c0K��`��(%+�h�����vJ'���(*t�=��1Ik,/�������;^p�ি	`҃H��	�YL&�\t��b������jfM�s�&�f5}9�I�c
�8F!���5������;� ��l�,|�����y^]�������v�4���{�n� ב���+^<�0�TU���c� '��]Q��8ݔ}1�ID�A��DY��D�%�G=6�)ܝ�5�W�|F���	�bD����覀�:0U���::|q�M_	�?�h?�6)�	����Kt~���q\"֔u�#�q����9^cg��	jI�Nw`����>Ҝ��4eUz�K�vF�ۮ^��.��4jN��|���éĭʢ.	���r�--�!nB9�u���Ȓ��[�5���:3�ړJ���凳��� �Y�`�s(gR��CG��ЬY;�Uh��|��(��8�#i�ز�%�hz�'pD>��	��O`M��5�\�Nf3-� ��1�>��*�(V��-?�Ǫ*�og����z���o����=3A�L0y+g��T�:��hjV�Yg,,�x�Ԃ���,*���BP��H�j�����N����Q븖Ē� �'8�����Zߗ΄\�q��2\� }��իV��A$���WF�/�6q�Ҭ�ĵud�#-���E��:Uǆ[�z���Ww�X�]�� ZigB�كxC�����z��)b ���\9�I�� ����	mm�D�S�ʲ�N<�*�6z���}Z�tSHW�Gi�CS(��`���*K�{�/
b�I�̂�yI�/z���_�$��Q�Q��:� �L���$��UNE��$(G��\(�F8�v B�N��Z��y���|�2ng%�-%/l���ݝc"�{O����!�=<�j�/C�>/�(ۀF�Љ��wz�K�.���DH�pƶ�@kF�Jez�����@4�]�~�C��$��Lʉ���gHW<G��Y?�V�E���U�Jd&�V��G�iPפTgי� ~L���7E�W~���5;�k�PiT,|7�WwZ*��߫*�XT_��)7V�����o�?�~ "GB�QϚ��V�I3�"+H�+Lt
��"p_MD"�o�뢭��� ���.�*L�����Fl)k4\��p��3´���Ă�K��ȥ1�4g�V��}�(N�2.�X P�{5bG�8r��#�h�|@#���Ɓx��X.�$�H��c��K�z&D ~~�4��N�\WP9�l������r������
;P�,��`��bݙ���0?�>J�p㟛�;w�m6fb@��� ć�����~�>����}0�=EW8A_A�7*'���Nx���}���N��f�9=�CtBA�Q�.[��t�(�z�Js|9a�6j��ӜH���'���{G_�����/�.5y�D�,�
�B���}7�y">W(0p�dB�H� &�m*����F�m��:�C����Ò,�A���!l�.8�RpHey�tߩ� ��}�D�ӿ�zVk T�_�������ro�Xa�Ů�a �heJӅS�~?�Q�ɬ�l�rRv/r�Y�Sɂzf�a/�24�'��P�WR��Vծë��څ�:${I	�;qV/����F��Hg����o*�.l�&u��cZ���~T�LDi�w��1\����G�fh����Ludy�q��E������|d7�L&b�\u�Gd��h+ ��=+��B�ϱ�j�",��&P2�e��ۑ�kW���^x����Oѣd���=7�	O@�W<n\6c+m����~��ͼ��^YD��j�6B���O�>�X�9��3�V>��ka�~Z���U�TI�&Ȫ$d����8�#�2(�ܳ���V�rP'����7a�m��Z#�l���9-�����:�G�� �w����c �l�dc�Ӏ`���v�sE}Ʌ<z���������Aw3��;��{����#�s��WR2\#�R4�Y�⨰p�A� ը�N��=�r�K��԰f�� r@Hh�K�t�#��LN�+�hA
ץ����{��^�Aw�\xm`��̮�rŰ��R�-�H\ ډ�
O���Y�d3t�h��<�X�Ls{_@��	bƣ�\Av�����қ5�g���߶s9�U�V�7�(y3)f��.�EvB
����DB��Q�R=�3�#���O�4�j׭�q��z�C�|2n^v���,1EN%�ȓg����7ѝv<u{d�H%o�2q?v\������jl����X����.���;O�6��C��s�dT���Ѣ��n|-�wM[�-�5LX}���W,�T�è�^_�ٴ_�Cqʢ-<$]���ia(8#d|:����\A.MCsn�����h���Yȧ!O]N�����a^h�t�̗�o���~��a�cu��&4���6��W��X[5,'IK�G\��s���آ�(�.d�f�^��z�(�Bt�b�)-��[��ɷ�B��7����\=U��]��E�o��o���	ـ+'qE�Q#M5,�楿� �}q�)��dVaP@��.��FK ����~e�F>m��^B�����g*ϼ�ǫ�/�;x�uprփ;���q�G�5���Ù���W�y�w�՘�֨��6�>ɮ�s̮�q6���NϷ�j߫���d..���y=��lI���\�8����i^T;]8��bA7eF}��T�w[�m� G��������c��q �xH�Кp��d����"p�|�S�PTM��C�H�R������DT�k�6-O��G��:���C	��j&�����ƥ��9�.d�ō6��%�,��o�vY�(���h�����&����@`��&'��u��r5�7>Bv��J��lf��k�@�� ��)QQ��>��p�Ưi���[�HT�a������+&.�����
�Xm<��2�U~v�A�X�*2;��K�>�Fl�>b�oT�.g�����+���ļ��)�c�a�,�ό���q�M+�4�����@���c��O~�r$V�K��4�����y���y�R@]Ѵ��E���cFXu?X�Q��xpL�}�gr�V?g��`8����p���'�`P�w�#D��%q�y�qFO�N�N��6޴���!��ٔ�8�q�N8��<�f]7�@�Ţ�c��`�ٜ�����6Y�%��a���
����?Lw\
�ӄ� �*z\������q�xr�J�+������0?���`8��dSD��P�.�4��X�(pq ������J硌�B5����فP
3�Zھr y�[�aY�8���)\������!���8�s��v��̓.��s��6�:uE�u��ĘA\�/�H^�%@��W%W�0"oQ��%lfl�?�	�Q^t����!�T逳X_���*���݃��;ԭ�lri��8w�4-"��g<��n)bGR�����	*�M�A�]{}�q>(�]�%V�	,�&aY�f�bA�����Ӿ����WI���~�s�f��G2�H�v���
�]eL
��B�v+@v�c���y�P��![�$ʼf��-g<kVc!/�mG����&<��Cɼ�"��ȿ��F�A ��^N�cK�=Á�H�GK$�stY5��)_���ݻ��s���������[s�<ֿ��(��K��F�'�%�/�果��6H8f�IZOy�tt.�2��������VM���wL�#O�L�.G�n��{����`]��mu�U��R��SZ&�����K����(�
�ԑ�`M��r�����%�ҀU���t�=l<�_�ژH�rf�g>E6\o�%�G�!�ⅆ��uC�oJ��Y�¼Ϧ^����|��k�~:"Xv��ʞp���'�%�OPcg��pm�O��$J�b���g}�0��C��$3�賗�������L�
�?|%]	?����C�,F�V�iΊ�82F�����On����\c�&��ػǪ��!�RE�����U���nt��?���.������(�k�on���M�",?\�+�I��Wp0�d�I��g�#z�k�p�Sx��]8� �}!I#�׍=��/�-�z�Ku6����[����e4z��DΗ�SF�Nɧy�*_z@~8²�5�����Eq\�~�f+�"A ����ƌհ������9}f��Qu`dyw��{�.h�Bd�5XL%9�m�M�f�@�K.���m+3�pū*X'c2�J��O5k$����@_>l��pL��E�=��cX/�)N{�-����Y��6�m��P;H�W�VAp`8��tY3�K����
����M�'�}�j<8�X�e L��'i����A�,� �[)+��I�#�QL��h�n��g�z���'۷�2כ?X�l��iE&ZcC`EB�n�1�A�����i5�N����$Ĳ!W����T�d�n�d���ɭp+�%ʍ�I2�gxR,�h3���H����i4���va�杳�a��h�$O���5���0�|�����Y�Z1oڲ2ZyZ�Y�^��۾Jڬ36�����t�f#��f=v�XƥW��_�M��s�nJϴ�����2���&�a�����$&H\�`��SK�,}�{��a8!���N%e�z,f�q�������P������·�{�*]��V7&�b�Aqrx�����\�'Jf}��;>��AD6g���O<b��^f�2?6�}0	o���>|_۰�,-GE�ƒ!%���LI$�V~�����1���6��΋�R���s�Uxډy�����G����/�uQ��4����f��h�nF7�i�q"�Y�3ۯ�료�E�'����*mR]��v�+�&�Z$~#T*(�ƽ�����_�v	�*�x��&ThFb����|0=Ig��bI#����.���dc�}>� �3<�w]Uc"�M�G���I�Z|���5&������@��*1��4�6Uω�vw�V	�zɱ���.�;?$�st`��F�0`��ɬn� �l\�&���cHu���"��UĄ�46X1���<�;������I�lIU �kز�@Ow�ֈ�t1�~x��y�j�~�����d[�b�c0!�
4|`����k�>�P�s��>9ȱ2{-���=�e�eaY��>w�P0F�yoKx`?�t7����E�tO��xؤe���M��=G��9���N����g9 �x'5��}]���Gb�CT�M'��OA�wR��]ܓ�6��|�40����9N�u�}{lZ�-k�Ab�N�V �ɺ�B� >�0OW�_J����x�p+H�}��Ƙ�+��K���w/�V��W��_��3�J��Z�UpLչ��(l6Zx*�SmՐjYt7ÝV�d�nw�Ő��J�B���Z�@�n�T�Sɛl��-;��tȐ8k�
�A��9й�̃"�C�Q�D�����9���2?�5V�!�v�50��I�؎
�Eh��Do`?���<�P���HL|C��� )~W#P\��7@�+r�"�#={!�l���3�:f���*&!k��8�pG���7c�)�L:X]�أ�8����5��Ց�({��RlA�|��70*hK�g����m�7��M�W�<�X����Z�VY_�~w��#9�bCCڪ�hT���K���5��#��0!c�x����_�צq���)�l��mK�����F8:�2�X���7BQfFu��!�u�G���j���W];��Eg����c�l��p����<n�(c�puKD�8]~邆^��{4��4�-�"�sf,Qə2�����^0�L@��{��8M.G�}Mm�0;g,Z�|D f�f�'�ŕ��!�Ě�,�C8�-F�c.�q��E	��r>=�1�>OhH]����M��66���yugG�o�H�'g`���=���:���<�H��m�ǳ�����lcx��Դl��9�"X��l���������xUZ��A*e?��͎���]�3����<p/�|�Z�I=ל��=�]���s�U���55�����ɫq ������͌�r�<�H��rRw���-T�!sƝ��]9�&M���G\�QD@��j;cD:P��P���m�ړ,t�`����O��BbY�9�j��'�zKo�5z�\�n� �'�Mi��A�g�F�����h�+��V�ۆX�r-��w	�J�Z��.���I��+����8
m��]8m�]�n��?aƽn�뼴YX��x1E��Yۏ-����G����?W��p�c$( CY�S�K�LJ<�D^席j�XjN�H�'FS7�k���|��8	��xAc���X�w\l����Robb�j*�uRڐkD��m+,<���e� ��j�I2�T.�Ǧ��n�S��.���4�',!s� ����7Jc��;�Lt����k|���Jh��'99TT𛾠@yU�'!J�Ɛ4�G�}�;�@�a�U�n Eڇ���It�[�L7=x�[����k�_f�̩\�|q �)���FUn�U��h�G_���G���ww$p���fMX8ō�+-���
[#Z���o�4�n��o�B懾ՁZ��kI.ۘ�dvr���v�e�q�f�=��y5mK�"�*�:f�«�a�ѣ�D�w��zg�bt�?/Q���5��ww�x^�}�Ζ{�iH����t��C�taZ��l�bEv�Ŗ�{ʸs����s�f�Q��Ӏ�Rh����D��m�M��0��	��� ���*�`m����rN�dQ��ʞ��.�����B�u�-��z���$��v�c�h���}+��f
�(��3!?�ў9��S��%�ă>֒�/��Ā��39,a/.F ^��2/��j����������?ם�1������x�ph�{$.:H��ܐ��D�t��-H����A�Ҡ�>��%����ڟ'��bc!��j���_����}����fz��TN����v��az���>y���e糩-�&j�7���i�K�3����s�iW���u�Q�|,��-��J��=�v�)__����E~.R����=\ZAZ �6�~-ن'�lܢ*�>X1��.�~a�!��qj1qaݬ�����%�$�(�.�E���J���1��PRrLP�2���\��#{���`����G�=qF�.�p�q�Ҽ�[��u�(s��k�{_�yɳK��mO���h��0U�	}�K�{qc�#O����X�	�?�74.J�l��]w6�-.�~�=�C�����h|W�鷯�Ms�ζ��N���hy�J�Υ��Q��G�o0}�����*��"�E���sÅ�SI7a#�s�c�zf��Y`\�Ƌ��'k@>K�3�#�PZ���2�y�.�z<��\�d�>2��{�0%����J�Q<Yܡ ��*�R`=��Vzֺ�ܐU��	{T}b�"6]��I�
�����6����Z�F� �;��b���^u�,��ӽS��|����b����V�ˆ0ũ:JǗ)n��cUO")�t��+i��E��-�)Ex�e]��|��t�匫���q�y�8,<H��H:�
���%�-R�.��z�c��.Mgx����u%�LgH�o'j|o�q�+�ӖcА$�.V�#��4��1���b��t����9P��yS�5�e�S����*H��Dl�2lQise3aY���*���=-����+��Bts֣;��� )�C�7�a+	'+<̈́��[�ځZo2�xcF�ĶP��Q޹&1/����|$����@�L�}���mn�*�f)��s���)&���7��q�66�-��3;���W�XQ2����� ���&�N�|3=R�T��A{w�������N��U�@=@�Po�\T��Ҭ�#���W�p��Û��6���8�q�݁O+�H�C��k_�'� ݅��)F\��"� ����6�� �噀�X�q����
��]�Tc�ku�'}e�_��r�Y#E3mج�'�诒á�Ʈ�>��v�4���w��}���dI����q�ɡ���l�w_����v1e��)�����˰�r7n0TX��:"���a�@ �8	��Y�*�r���W���[��$�u�s��Q��_�����r��E���C����`�Ԙ��ֳJ���hb'hrM��-.�����z�r rC�R�)-Hp6�,rk��מ�*��>�f� m�a	C�X�_�{�2�q�z�$�R�a�Z;v=�,%|�H��{���HC��oN��|ި��6<�1�T/��+'Y8ΦJ����[��3�6�p�p&�F��J~|�ث$%%�8���ў�(�c����8��㻧C�Ҫ7�1@��O6FZ�N�A�H~����Q�r�Qc�y�-H��br,�4SX���)��(G?V��6��[�[%x�H	��Kɕ�B4�����בX)���$W�����gИ9��g��O$���ǧ�����J�1t��sޙ��!Z/G�+�K�����^�9���P�^���P����m�Ĩ:�Fc�bR��a.i(N��P$���ѡ�R#�X��B�lg�W?�=����-��2i�O��[];�b���y��>k�Q^}�Īh����;Fi)0�+�%����iH�>3)u���!:I\^�N�ц\��6��P�
f�]���8A�ڊ�0ץi���9������S�6��c:p�"]6B
��J�o%r�X)5�[�z���]�`B?��~m'\�g/���Ѯt�l���Շu~��>�0(Q3��p�᱅���m ��4�����}1MqO�{D�W�yH�|�9��6$�Չ<iP���s�����.��+P]ղG�&g�)�D���ea�vcFp���7XLJ�[{2��H�2� NRt|���G�F�T�J���W[q�W,�ڍ�Ȇ�Bs� ���2�b� z4�j�T-tث-s��r�u�ܪ��y�Ҡn�(�����B!�꾋���Ӷ(���}�s�іB��ou�Qz���O�L��f����~9� ���0���f�J�?�[��s��Oկ<���h0	d����� ����T�O�������V���Q���>�������c�5p�LY��RN���3l��5�Ԕ�������?��;x�rǠ�ӈ�0
�؞�ݙ�F�ۢ����F�$�SM����:�q��g��3!����t�c�Cr�y�F�L
)�-wX5�k������J���\�ۗ�p8�ĭ�w*_�4r�����.F=�[���Hy��gG�372��ݻ)�W	B�#�pxo\�Qf�l��q/���b��Q�<�a����(+��1)��󸑔aG���I���wU�UG��*�@sx�:� >?�dZv�o����(�QF�8�Wq$������V\I�[B(��)'�7͇�m�Yi���<F��>�@vU�y�툤*.�\|���� �� F�4�ߏ5^��KJ�>���O~�܅<GΆ��eHǬ�����|���,iB�����N
JD�|�KM�{���I�4:�P��܄��V���R��2C2�cW��U���PN%���<O׈S�K�[>o����;5�n����,�څ�\�ņ˺���.�HSՂdf$1Ȃ��V����g4�.� ж�.��A�]�%O���%�>�c��&�>au���#J�͒b�ݫ�Z�����M�1��ُ��b=�U:b�#V������uu*V�����KU�(.?AO�)��計���5�ZŃ]?L��V�&���Թ����w�A�N�鑫:T1�}|�jj\�5J���o%�D0o�t@u[Z��y~�
"G�X;~4�P5��Ӏ���q��(�MB<2���-���=/P�<�\�N0 r�+]�^���:"�d���N�ӽ�ci�A=���$�n�I#���*��������-%h�m��U�J�Q�:�����ި}%�� ��{�z���u�������u�`h��?*�Ppb.=�S� �!��.���-����%ׄCL�;��*�{|����д��w{∔�,7W��U�t�X'Z&M�Z���q�'�f��|�>!R�� >m����~�%}��O�� �bs��Frq�A�^�B�+���KK��jx�أ@������ff�۞Bo��6�yf*l�^��}�K+����eW>㝡�����tܺ0γ:f�KͲ
]��D]nB�p���zWg�LY{Ĥ��ب�y����V�w�}HwxV�xp2��N�N��E��{iv>��IZ��]�*?�V�r�i�,ך���צ��Y?Q\*��^����j8��H��p��g).�$���c�S�Yxy�~b�~H�=��\����U��ia�xNŞV
!I��Z8���L����+Py_�ө�b��km��5q�)İK���e*�y��y�*���ڲ�Ūn�ۧ|/x�|�bۜ��P{��a���d�{�сnkNrܽ8Dfy��@�zv�a��e�V8{�U���x���ݤ��Ք-��V_l�����זɢܖʮ���8:郞>���^��������L�;ZwT�ȣ����,A��Q�F**T���T��RJs���:��*C���!�[��p�*��q7	u�j,�ږT�s��ћ�k��ة�đ��ci����*�O	�cB<l��!�W	W�g��U��E��pˑ�&�#%��b��3��+�:� 6� ��}h��V1hF�r:�|�N[ƶ�b����@1i��p�+����,A��1��T��7Ép�k>�D"�k	�)�7K4��/�d��Ȫ��ev��u�C�}"dt����	;/B����% �u���?��/��֎�Βj�=1 �=BY�ץ���I�X&�����&p�� <V}5{�{Fn(0�L0J�0&:�1����C�|�${Sv3~��
�Q���= Q =���x�5�qu�hhȶ�]���#�פ<1*���$N5�-V�Pii�'x��7��u'��(B�"�!�KD�e�^\|\7j�)~ݹ}֙��wU����Q��!_a��ʽ�W�c�>:x��>J����,:�x�7Be�������Q�S���z\�j���mGP�������[f���8V�3�?P��=�./���>_�OI��:+U���7�&'��@��c���Ǿ�,~V��u Ǯ=��W��zR�T�A�ș�xEB$c�}J������$a%\��oSd�u+�������48�W����& �>c�|���y� �2�:�r��v�-a[x�(\��oi�#ڋy,�7�(w?�)/1p�;j�(�Em[93ci�
 =���2��ے<ƛv �4�8��z澫MX�e�9�� 3�.��9l:~G���y"_(�J��p�΅�[mg������6���=R ��_j�����.��A�95��O�|�2�o�D�#�S��E���>{Ô?�����.��w�|��>lr�nl��x�E�][�ω���`�Iw�ݬ�6�4K�TV\�A`^��\_!���O���&������ٴ� ��+Cb@���7ld\01ܦ�8,S�&Zo�y�D�W	�L��:B�Q��"���`��_u���kP@�'�5�Z;�U��fp�kU$V!�
�hH P���m����i&lMsR� ���zeu�E��B�%,&�/7(*�������[%��:Q�F��`�@Z)�<��汈���[���r�� ��<�e�OF˖��J����)b 4���zP��%�!���8%���m��H���<f�T�֍��͵A+��Wu8��àhP�6Ǒ(�A�͉C_�g�L�֌#����A����h\�N�4�ң���j����~C��Y=�u��
U����"g��o�˾�9�`<=�y�+���Y��vm�T@�R	3d	Ն�	ѳ��.����bi��a�Th�������?�h��KƝ�#FH��A�����*[�U˞��x�r8,�͔%n`l�1c�6���訂��ׅ�/P�:�r���`��8�%G#t Yu�l`/�O��9��1/j�d����# k8�x�4]L��"�N͡O�~/;����t��˺Ґb���0p
����bg]�k�ٲuZ�<S�]�T��t��v�_V-%]�Z��;�����=�۩���aA%E�S/�5K��d�}P�=㫽/Ζ�}1>e���$#��'�gU\��d��8���Б�&Ǿ��5����KZ���[պ�T]\��kQֹ��"g�穠��u�'����mf.�Q��y/E~�C��i�q�4�����*񦹂/+ぶ!�	@���v��� �B rg��s�U�&�f���r�|��l����:�J�vǟ((GǟH���?�L�]JT[V�W�؜�.����AD����>��}�Zw�c�XG~3!p;'�����0;Ǿ�+��Gr_CBd1_�qWǟ9EoR�z���$�i���G���.��Č)�A,�S�̈́��^�-pXGf�1S(�lz^V,���U�� ��HC��n��[h"wA�;�R P1�=�+��ܚ�'&��Ǭ�q�%�Ǔu�V�:�[�ni�[_�a��u�LE�'�gA4n�	$�)%�ʴ)��F�
�)k]��e�=� �O���v�c̰����&�?%*L��WQvqPQ�M�Y�k��EB>�"Knj�L��*]�{i���_8�X���;�|X�׻���?d8�u٬��{_�8��P.=���cc�B�����l.r���7�Q���|xib�>�����ÇN��t�xƏ���<B�ǵ��_�&����V<K�9�����t��Ŷ����k��LzQg朓컳���A��>��� m����j���wPQ�~�0=4ҵ<�+�P�`
�w��u����VV��>����p���,�ٺ���$ )oB��5��N�^'������`�T�
�פW�jWE�ն~|M~:%����H^��J�z�g�M��k{9� *��]��9钟9��RY��oh 2"����[D�i-g=�TO[�J���o�Y�$�;Y�!�ӓ�v?�����'A�Y�X�B�ռq�t9�Э4�� 7�ב����2X������� �Ȼ۸x�	�M��7�-x��-�=�M�R��Y��BN�J��>��٬�D�>ę;�}�?}��FW~��W&=d�9=�Wϙep��AT�6n��
��R�Cd}L��&~�.�˿��|W�xѭ/f�cX�Sl�µ��;��5��S�E#}�5[W)�� �;.��A�Ǩ���������	��yi��Ro@���6�&�xZ�9��?'�I�~sA��r	�ͅ׀�+��t9�����Zh����-h������=�Z����ȆQ��,FE^ �KMm__�MO.UF9hK�y!��1�.'�=���ms�	 � GJx9D��:Z�p[٣n����M���r>1^h��\�P��f��ky��-�Pہc�A�>��W��{�`;i�V%E��A�~eX�~w_����d.%e�S��G�N�;<�W����̨i'}�ygP��Ǔ���A�Q��V��.��ڳ��N�ժmm�NnN�񑶪�7�Jǖ��q{����Ǳo"4ٗ�'�5e�e��?1�p �u���Up�k��nU���i�ՋMy$i,L�JZ�C�+�MM" ā��]�H�(mgc����=1��g4 ]��"A��l�Apl���E��#f�(r$���N�f2��C�A_�F�_,�����[NT�4P��|I5��v6xS�����˯��a�{�=��S��0�F����DW���؉�� 㻮���>���k���s�=����.���D�B��On���'GQ�������)�G��E;(�qx6�u�ox�j�M��i)
_x��`4i\
-赉�Q�~�w)��Rz�R�]a�r��v�?�y�_'���
��o��7m�z�G)�ы���C{KJ^��A�LK�#�R�>&�X���Eq��˴�TnHrO���`*Ì�'�A���Ų����xe$��� @?��_�[hɝ���y�,����Y�|��gHU��uf�o�|���Y�kQA�M=A
�0����B\�}D�?ҷ�@s�W
7�})��8Ȫ:�g�o�����m����^!�l�%z��Ȅ�����۪Ү�+_=�-���Z^�l�Wt��]nK�^n`<Z r�l�p�Z�09����o����a��y��8z�h�I6�y9��7n�VC�Շ�3�I⣻}�k�q�f�$�9��$ *������F:'H�5�D������d�L�O!��T�p]��WHd�ū���~[�ip��(L��:��4*~�����b��:$��O�rkzB��d����><�#�Q!b��9�Y,'{�-N������x{���"�W����M�+�$2W4��l8�D{��p%�uJ�i#��:��G�Ͱ-Z1�
��+~N���ړ����L�0�[w��m��fq��r풚
*Pvc6@v�L�����84,>�&�C"|�����@�����ɯ%G"����M)çq
��㼉�$�K�/,�ѯ�ܵ9��%�ƣ����$#��8*�Ǌ�$����A�|�/�M:�w��F$y6-W͐�{e��ed_���2d"g��,�(�6��˞љ��9�Lz<��J�����(��E"m0\���"�`o���5�C��У�9C��z���޷:�$a������'r�'VΫ^O��"����0�l�-�0�r찫ё����~�̜�ם��(��hCuҳ�Ʒc��O��My��mh�č`fE,�/)F�8�n�UFlJ�Q;;<�dYZ)+�M��z
��fXO��o4�\������n ���笒i�Ҋ�/Y��b-��2F[cù�tR��H8�,��/��([l?�ZPM�����fi��x��
������ �D"�����l��aH��l\�1(̕/���k��d* �"(YF�㑛��r�)�fi>X�(oA����e�>�Fy�����
�q-��<E��i0!��	j�9� x�#��vu�����o�nf��cy �i{4�G��V��`um`��:<��m�8�7�|	i�S�RF?�����Р�N�����~��y���:���g�>�˓�y���NЪ�������$���C|k�xS�O����s�ĥp�>R��)ʭʑ3D�5QH�ql@�0~b��3�U@5%�eP	�(��L�ޓhԦ0�U��#mg�w'���QmΗC�,8:�)���yBea�r,�~om:��ʂ �ʋ��_f{n��Y�v�ņr-jU�@T�
,�"C���p9�^L6�t랈N�n���͠]�:�mČTZ1�D��pm�s��V��ͫ˫����`�e1� ���P�.��	�ꣿ{|���K�����-s�3?g�u�B��>�N#�K��L\"xpA����fUV�*JY��S=8�|'C�f6XYH��
u�2�	4*��Pq��nmBe����=�P�;`�>~���~��U=�s�%݌�6C��=�E��+w��9v�c.��P,��wGiQ��i$IR V9��Ԯ�g$+#����m��Qh}x�M{;~�! cC#��w�K�D��l-����E�U	�X���3ı�i��h�w�s��Y�<2�#�B���"H�mҟ���J��s}3!X��UXo�t�]'i�WZ������{�K;j�ӗ� �9�Љ�m-]�� �Lf�����xᐄ.+�s~ؽ��5!�����4��R�4C��GxG��H.��dv�Y:��*ك)u9���|�LX��4N��f5��oHnj≻9���I7�+K����-��4�]e�:Rx��qC5�8��6Ȳ4>kﳏCp�D�  ���a#u�'�h{4��������BuS�yu�(�m��t��	Sn���u_�t����O���j@L��u��A�r�v�(��'hp��%-�k�.�5�b�U�!�UCE6E�GZ޻)������
A9l��j�&T��U�R���y�v�Z���U����\���sD3}�-m	��P͜��#T�e�
2=��k��dfLʥ��D��Oew��t��Ns9��b�܉�yZ��̖LrB�
Q�U9'D��A�Ps;�i4�$<A`���y���L,���4�A3��:��C�_�d�	Q�����姴W��8;�
z8_RU�Q��Vʟt�Dv۫d����}N",:=����-�z�<��M��ߋ�Y�ɸ���0�m��7�U�.�CF-�X'� }e+�Ƴ`M�A���7p ��_�(P/~p�dKKh8���Ma~��L� &�����/���e�:E�����],����k��s�FB�3�Ul$u�B�ǃ4`�����&'�x���$!�	LV�b�JG�E��p���-���j��F����X�[uW7ຶS��ݏoW��pqVܑѐ;���'�]v�a��j�gs����W0za�������3tw*+]O� ��{������M���-���]H�A�T�Mv}��^	.v"�=�C��[i�uj�T�ma��I����������4�A{VAqV�X,�ua���X�x���u��. ��`0�6!̾MʔΎ+(H"��I�L�y��
�̡�v���Ӄ�c���*%�īʵU�>��ٮ_�u&�ǉ���-.��o��֏vo۪�II�ryp�f%�0��|�f�`�*jzЛ¬j���ւ	�~�7H#��q/�ٖ{՟����v�TZ���R����A�բ���<F+�uQs9EMkG��+k$��6l{9���F����;�lSVh�VDT�ٚ�(̺��h���um��f�/� #JT����~�ZͪK�E�%���D	=I։E>jˈ)�Z϶��v��y����2x�����#X��*$H}#>���%�+Z��V%`L;�!!�T5����'����gv$@���
��y��c���Xӽ=���iLy��_��GQ�lyI��N��+u���.m)�e}�:�+�~�|jbT�p�����,"��SH��*vq���ύ�,�%4˰�o��(I:�Z]��x��%���9�q��e�v8�^�� ��ƲdKyڧY� R��8a����LN�i��'���P���'c���4����$QUo;:Ǻ��2D�����
;��\^/�Y��sP��8���_��K9����[^��*
�Gy}���s�˟O�z�ߗ�qr����o�R�~0Q��뭶�'Q�fj'W�&���ӏQV��.!f��ijhѹ�� ��|�w�Q�=��b�Z��[��	���i�T�A�u�8�<_�6#�I��� ^�� �&MJŧOmaD<Yx�g<�x$.��V��޼<Yg��=zLU?���k�@�K���W��^Kд���KF#��a�p�~�R���?��3L�ui��:#ll%P�T!���vA�u��͵�~wⱧ*E/�����;�tE�	3�Z�����.a�~�-.;z�H�Y���}�:#�oZtYN4n���]��z~-[�R�^�L
���h>�+ۍו�PS�ۢ�y��ku�H]��䡦9����S��>vXp=U��>���sF��� ��d�Z����	�W
�N4H� zl�l��'$�]�]�A�*�G��aʋ�KV<�����7AYs@C��|��9�X WﶳLp�H��de]Y�X��$��-��9Po4c�R��|����R����ޟ�s;�2y�����4ʱ�l�T��%3gIlk"qW].��J]��b3j��O
k������w?ֽ\�(�	CTYu�uG
}��2�/�!�<�m�t{}US*oer}�q�f���\��FQ/��Tj�W��CG�L�tzECx���@ނÝ�1�'M��8>��I*�n�ѭ�
�)dϡ�1�WtO��1AL�d<��Lb�ƺ�aw�=���dL��0t��Ĭ/����0���kgM��z �v�ß����֭Ȯ6��zh��b�N{fPM���;�cI�S�N�P��Ѯ�b�VG]o\*t�X2ѩ�I�hp4=���'�y���� �十�r?�FɄ�nJ¼�*��`��Pcr���J�Dy�0 S,�{^�;��+�m��������!s��z��hY$��I��9����� ����?.H︘>ӗ��R�kh�iQmE�����
�)�'�K�`_V��L٩���I�ż5��Z����5|�ޑ4�Z-ִj	^��X�s6��F��z_>�<�N S�CB��d�7��4����ǏB{�`�á�ge<N�vWc`���NY���A?�+B������F&��l�!��u׀�NO�J����3�]�U��=�*�����d�3v����}� �Dz��z�η�nit@%�D!�����3�k8���'	�����t�,��{�~�F�{P�Ip���w��Zp1�]�3'��OW�l�a�o��Z�s��?*�z����h@'/~L�QG����Y�~����j/���ssަ�g��KG���X����P��r�q�����v�ԩr����ʣ���޻Z��8�ڎ#(!@*c�C���K�F8Ĭ#�O�����9��`�'��� *{���"�q��M���,#�ۢoVCz���?�1-yZx�w\hΫ�ģ;�m��ͥF����0��	��U�{@�wd#�x�%�w�itW
@�o(��շ����p75 �@^2�.��B*l����#�Ba�wꨌ�$�B�@�p%�r���<������2[�U'Zr�ߢg�%:qi2����-��d�����#��ڨ���#�!U��Ɖ�:�Ƨ����j^�LO���ӳ�H�{��K{H �w���Q�e�7��}x�<+�H�ox�t�7�A�m��3U���5���e����k�m	L:��nX����� w/�se���W��:VU�����Y���2V���-�`Hd^c@�����SUZo|��b���Fwr�ZQ��V^�^�7��7ˤ����m]���1��d�2O��ZU-��i��$�0���;�և�U����q��\W���r����y��R6��x����1N��U����x	Z��r�r���:+0VWG��U �t����w���)e�܆��B�fտkQ%p���
�G��L�ϟ@��x��F�Бg5Q3dWД�Lb����*��+�J���f�sQ�6	��ɽn�r*l�w"6o!b�5�!]0�����z:oP���8��������UTY�<��p-����)B|s:�>�1�K��t�SEO��(�o}D�!bЀ��]�b�]�ݓ	[�L0� �daM(%W@Ֆphz�����1N�_���h��Fxb�A���E`�vkdhWF��*�}�V*��,Y-J��+���k_�c������P�� ��
��hm��范���D,pYz��j����AB��}����q���1�E�D@5t]my�i����©���"7p����!�"S�%��7����e���i�E�<�m�^\Z��2� ޔ�	�ӣ��hɾz��v28�s>W�q�O���ͳ�����Q��;����1�hGu���څ�������]�|���"�ٮH�f���vz�O����#���=P�_��Q�I��'��/����VN�i�P�=��K��p�T��S�S��(��Ɔn)�O��.��AZ�C/�-��7����~�߁;(_Z?��ǈ�vW�~�g�x`�z_v��H��v
�J��"���*�be���]��Yռ��m̴��θ+�BK��^KyN�A�WzlE�T��L�t�-m�l��k��aL��\ΰ� J꤭��cp�NՔp����o��~�=��#��W�e���D�%�f�pOX�/G�QpC�>i��֧�����%��D�$��`U����X��6��[&z�ܰ���v�����GK���hӼZ��~�*�����m*6(b.���%Ug���辭���(��h<%ۀ��mGK�
�����l����LKķ��*!���֍,gr`�+"�)�s�3���x4H������*�0����F�)�x�PY����F��Z*�:���a2XF�� .�t�g��9U�Uz��n32�p �3Dķ�b�O��4�)��}8�LNfd�TG>8�db"�L�f�3��,7��n#�?�?�j� �x؛߁8֬��	��	r<x(Ƌ���<��)c�����c
r)|��Q�����{]x�-�2�{��QxU�N���>/y�,�yh��D����"� �e��OȿkC�џ����e��co�ݿ����Y�N�¯Zx5�y���ƮvCR�}�.�����-��Bv���p�I�ҍ�H0[��a�����_�ͥ���y�)�����%�'�#��v'(Y9��j�p�}�{\Y"�Fj�0�#��\��(��	-����*�N��w��������O:�h?/ [[���AO�g�CS�x���Xow��1g�h�]��$�Ɂ]܄�g�S$�!���w�ő�;���3�$t�y�_T�g�?���U��ns�&re�<��c9�D����ϜQ}�x|���>vG���"����N�)��N�A/Kx��"pNBs3�����(� @�	�O:o��>��Wl��9g�K��
2��B43�����Vgܞ�M2�ݫ���Faa�9�Ɉ���Lz~�q�&ho����>`��"$��D�,a*�q[9S�U�3Fm�r8��2ϵ��d��.ct�؀�X�a�Gk>`��٭:� Y���%�]�)�{�q(^z��4Nk�S!'�ϟ�%�����T%��Uy��p˂wCc0R�XR��>mo*[&Q���KZc��C���Ȧ�M�u���Z$��|xJ�� *��j\<�r+q�[cz;w���?�I+�a-�I�}�q��A6�m��o�B��8 ���<�E�-�F��`,Z���h3��V�'�O���^�[�$7�-u�I��1k��"��Gc����3X)߱J��^��G�D`ǿ;�fT���.�Y~	�>��fѼ��7e#���f�O"|��+�#�C��	�J��01{dh������[2At܆������΋�#����I}C1�5�Ml<(>�KP�e�����դ��3?i�����(T�/b����A�[�8Yx�gY���i�nG8�]�pa��|�E�W�2kɓ���!~�dC���E,��^�qQ�j&b�9,�%,��wK�!��aZ����"D�@����$���Oess.3���	ZGb�Yჵ�8�#��5"�[�b�.R�j����=l>�'>H���L��9�~�C�C��;{e�%zf���W*2_�ɣ�M1�����>���ȆY���c�;���k�:�Į�E�T]׋hu'��nS"������F�e7���,�(_^.'�r'��رF~���K��[������zY�b�����2�_�Z�`O"����5��jl���3��KG�=�q0�-�p.%��e%%��K��/�E��E`H���I��)�>�~?e�~�6�!�m���J�hB�]�% �C����}<�iQD ��(����C�/�z3��=�̰]+hq+i�c!͡^�&�ݣ5��E���q+��P#?�,Gi�;�=JH�f�=��ˊ�Qr?�H���1B��D�=�,M�`E���c!^Go��.�4=�1��l�j��4���g��IlL��6�̲��#i����C�@P�I'c���SC���4b.��@��Ná�[4�}Z�f�	��K!�c�ИÄ�`G ���UfA�bM",��N�s>��:��z�$c�:av,O�X�O�5�D�KA�ȴ�	��������qQ�����"^�;P����U�1p��;�����R�Me���$� ��C��%N��9V9�!��@�ק�)���)�k����'���}�"��%@�FC�Ң3���������u#� �4���O5ꛩ!j�@>y�,�I_�x9��VB.o[��v�꒎�U�$���]ቈ�i��l���(��7d�}�(;�����k�it�j���d�1��=��z�	�@�{墌�,�-:1u����9��}�f�f=��Y����j�����.��0�5R���@�6a�$c�Dg�K�|+p�����\�/��s���,���Ը�h��e��Ď��NE�&�L�?V�HBms~���5Z���:���J��{z�&V݋<B����tr���δ��%�Ѕ'O�P@e�^�d�u�B,X<��5�8�-�U�Ày��%������6��3\S�p�aO\��m��ag3�����̼o�]��v~fL�W���R8�~*=S�81�w�1N4Yԍ��\���>o<�LP��-�L�l��Ѳ��/�|�<S�$���ڝ���c�����!�Nj���Jm��	��)�ɪ%6�����R�u�5p1^�A�Tے#�����S�a ��՞ ����@�,���e(��C�hX�"f�2���H4<R�1�c&�}x��K�ԟC��r�N�A�&��]���J� ��)1���0�z"R�b;�2h�8�T�,$���,Fœ�����2m���$X<�-S7�#-�>mѫ#ONa��*"����W�M:��ޅ'|�0��y�R��9X�+ �Z�)��+\�LZ7��!Oޡ���oə�ȩ�+��ڍ��ɡ�uT����d��v�A�W&= �|2kĩ9_�'��
|�} G�_[!�'�x�&�(��I*��ډ��'��`,���0��}���>"LK��{����x~S<�8\��� =�|_	`}d��x���*:>���li��Br��@L5��>��F&�����ԥ?��>y��z����}ʣ�?�.�W�CP��D,&i'X�� �'bF^o��Q�����*���%�:�Q2S�7�ދ�Ἦ�"^�z�D�Y2�rA(�u�؈�n\��D�w2R�Oo�Ҟ4��7�,DΘW85x�x��L���ɒ/rbK�>U����	y��X���2��EF��d�Zw����ݣ�:����!jD Ƌ��Q~NE�=b�q��'��
P� ��+)� b���16$�Qg�{lI�C��}}nP@�@-��4�;�Nbh��f
ja�H�v�OD�Ͻ��H�F����:�dݻt!�&$�1('|����:?Rqʼ����E��S2z0� ���=䧰"��.��lUL�`D�rC���H�������w��phZ�y�����ؠ�}��
j�`&�n����&y�����׎ƊJt(���"Iec/��~2(�YҴeh��Ɍ�!e����<'5A�}��"�2��L���R3���T2]�s�q(��䊋,ir	*�-ml�gK9	+����P�����As�s<��8�j�*A���S��*�'�k����j�c&!VQ���E2.[�l���h�Xs��!(iy:j%Y�j�x�ɭ8<at9*�g��~���g[I������:1��I�eV
� 6OZ�=1o|w��M�J�yi6H�=�7|$���Y����͉��lS�ڻWg��8^��i��r��&yq�5���	�C�N�T���csV��`��y����iGuFF��s��d���I�XO��PHU ��,-��4(��b<l�6� �����"����>�Y\D��<4�+1$IU����dPŉ:��.���k��I`,��J������,���ge���<���8j��O�wCo�pQF�K��%x�ɞ���Mbì��f-ƊyfI#�DY�*���d�� N�N�أvp��\Ә�����.f�0�� �5�������8�� �2�~�D��A�qn��Nб�cZ�JTfDYI���tGnes�T�g�k}�Y��-syoW#� )I0�����Gh�j.�U[�@�.Ex�<&YY}+��7J�W���*�w!x��FX ��tf�4Ḻ�N}��?�Do��\�v��8}b�<Eq��D��?9�����8����A���C+z�M��"Z|}�?꓊&�4T�i�뜀	��l�4��%��Q�BJ�
�+؈�<膗�DML{�!�@�IKp	� �U*^��i�����0�%�( ����5l	�4\�t��c"c�߅�!O&Oh��Y�:�l��� >��@@���hu���+8`�꽫�?�����w��~��ܹ��^��NWh�L�Q��0��g�_]����S��H$7��QP��A�o��r�y~������N;�f�Vl	��H��a�֒I)k�eE�Ӣ}��",�}6�hi��"/�?Ϧ0�#��r�--���ހW��$�»� g�*�+V�$b�+�Vl�2{� G|��\,-U+�����J�̎�m�)�Mf����.�Ȉ���䚄��8�֬�7�fE���j��۾��<H���+�.������3��Ŵ���VĄ:��8�u�6���e>F*����7��M�)�N�+@&%����h�.ܤ+Â�¢Áwܿ	_#1Z=�ZC�8u���$71��9b�'�c�u�!�qױQE����^ڰ�s2(���N�����J�X���#m���Q=U�"(�
��U����YoI�#�aAkyn�~2XE��׻|��ÜAZou�˥�!�1�6�L��
±�����W!��`ku	�:�5��망�VH�aƏ?TZn���<w����� ���A�ྥ�E��*�Ps-��B[����F�6�dZ�mrwړw��
5��w�P'��-�^��T}S��� ϙ���`�16¤�E7�g�X�6H��0K��\�-<_���7��z������~�S�zl,B��/]����ӻ�i�+Ƶ�\B�Bt�~S���z<eL&P�RZ��KP�����T��=RR�*aыx�W¸�W*�&ޅ �KZC�4�Hc'[j�����~��ط��kj�+Դ�.�hj��Z���V,I\��5��s��>jj�2�Բ
AUax��"��S�6(V᫭��H��R_��Y˂@;^����XNM�h�������K�V�Z
���>S,��pw[�|��+eX��+*�+n���^�º_U���kVk��*�R��Y�:1�JG\�-�.�>��F����}jZf�9��*�#�.�0 Vh[�@���.��ێ����I'��8G+��7D�m��� z����,�{]�)�s^2��P�~�����Z�s����>��\�6k�Yt^�,T&��A�`�f(ꇳ�tΤH�{FJ�42�K��^"M/CRDd_�5�cE����:E�s�s&���F0�P�} 	��bT�:�I� ��UIo��d�F���B���9|�1aY��� [����L�B��B������ȣC�x��W�%��u\r�T����;׃��&���3v��� 8���pc	{���	�[��?��'�������y�8V����p�U� �6r9��R w�>�����֌�'�Nv!�?cS8B�b���+/o�&2t~��X d��Qxƃ�'"F�om�b�#\z����H�>@�T��{�>��v��&tė�S�(��T�ƌ�S���̗�ī���� �Fa�p����H �ir㒴����m�d���E�CQ�W��~��&F����s��!�4�jM��������\�p������BҔ*�P������99�r���Ȋt��9�7 aI��N��$��g����2�5��G@��&�YT#���$�M���y���!/�]�S��<��ၻB��i΂��Ԋ�Ң�P��­������)&j����mz�6���7�2�nKZ��b��ȲԺ1�i8�К^�����էT�VP�A�����~�q�E%J���Z-�4��FCv���˄���j�LHˎB�W���o�54�|�U��:aJG}�3���c�e?�����}����92��a�1R�sP��=H���0�D�+��j�n�ׯ5��Q_��92r�ɚL61Z����P�w�0'��E��f`1Q�j#��ɷt�-����k��d�g["�OC ;V��YI�p
�]�6�-<A�� c�j�)f4���k@$"_�Q�w-�y�"0iWm��ӠJh$�,�o%��}���j��c}�D��Mw��T���5�B�ed�����y���+*�5͢��B�4�F�N-�my	䈍@���8
��`F��D{?,��[$�]�h��Z��p����"�:�+�-U���g�~?�fy�w��^�����jK����
��Okh/OILl6�2�ay�#2u�a���;��}�k#͏E����M|9\�8n������pq�^�����wj����ӭ�	���7�g R�2�·�
Oe8;4���0��x�F���.6K��>JV#.,?ɲy�_��c!So������ZR�d-��q2U�ў���]N��c�]����('��7Z/5ݚ+�-��+4�}��Iɓĥ����->�$��)*�R�u���n��E7��Fl
@Y��O
>Zp~N�ut�X�����mh�&Eu�������,YJ��o��t��=bِ=Ee	��U�덒���A���|	6$�W��b����L��Oqrrj�ڝ�E��>l����[;��~�=Y?��xo.8����1�{�L8�vX�=wOBST!�J1$l��%��e�J�~kī�"����"X��yj	f#����~[p��������Q�f��L�ZͲ��oΖ�UƧ� �0����Qeф��p�扂n��M�jT�� �X�~��]Ů�0�2�h�Z?���u�)whu���6��?#i��󧍴��|�k껌K�m\�;c��.#V3��0�tSR�+~��i��	������(7lAճc,���+a�Z�#T��:�΀�C��͝����='MZ��1�|
\�.�u�=���k9�/���0?e;��	���r!�b��C.�E��܄Dn*�0���JHķ�9�kɅ��z2dm|؟���*�5�����7��Wu�#Š�[�5��ck��>2��3�)���dʸ/�����(~����d�r��G\�%���co�d���X��Z��-��k�r���eD�!��?s�6�0���D���\n)kIUx�%&=\࠷�"�&ʒ��"��ɪBð���'Kw5�����@=��)c3�;�D߆<Œ~�Ջ�R�8Z�rǹyƉӞ+�c�IQ�D����p;\��*�gc�a����L��3RQ[����Ą��m�p[�\q������ZXq.�h	(eQ��Ͳ�'��v[u
Q%4�W7؆���V_��Q��Q���
���DMJyv���϶瘮�Cm����'G�0,zp8끰 _��`j7��;Pú�pdtMH)Û��\gO�ޛ9��|�r��N��Z5�D�X����9$�u��gu����B.��&��K�h�����7hl(�!E#dK�K�~�Q�5�2�-�y����C�y�}��O����:h:�s�Jⳮ�Q,nc�o43��h�Wϲ����0X���[�� OA���b�h:����oXn�T��^$+� �� K���;��鈀BL�&��aWxנ/o���O���ђ��$2g���W؂���s�6�P���Lg�-�i�n�|f�l�dɵƥKE�E��>'�eo�D�WtzO6+��'zG�����������y��4���Ȩ�o.-;1>��8������}�0K##�� -�@�y�B�(w�R�:#R�g��Yo�x���MTH�5i�S����vN{@�����d��*��	��%9Ǳ�N��ת���ߧ��!���u�x�:"�{cm40C��hǚ�$X-L�^Lq����T���qd��,Eg��G�`2[�F3ıOỊ��I`+D,�-.�)*68m� ܱ���C�c�s
��6��/|?��S���i�>"���ձ�X�([*e����ڽ���g׍��F#���2m0�P���w�r%/j�o�ي���`x�h��̗��!�N3�I�=������d����1h�^i��X�2���6�7�,T�t �%~�^�)j3������hO�3�q����uE�4��Z�j�-}��-\|��Cf4�_d�⇼�7M�ݼ�2��aw��%��Z�%i!m _��ǃ������u]&KI
���A���h�	�/p��$/��b&��n�.�\z�l�\��P�8f�)�g���ȋn|�}^��m��aH#4!r�"V�ϳ?7=ED��tS���{W������A�����e�>�v��N G��2`U坥z]k���o�IJ�����4:P��4�(L�*�r#���h���Z���M,�!��� ^��ol�sURвd
dT	~�C�S1�u�����ٰ�!u���J�m�T�O�>�ԭI����f�K�����T�@��5���o���A�sf*6��-	�\�y(!�	Y�!EA��l����%Z��cd�,���{����ZA�� +c֖$̟�9C��8���R"��cmծ��2ā�2���v|r�g�z'�vOa���@�RH���c
bB��fYE���5bhV�tCQg3 K�G��Jӯ.�tź�����;���6������7����ӿ+S*BS o��;��c8�p� 5E�	�Qpz� �2��Ab���m�ș�^�k�o����	�^��z�|��RBEɫ��]+N(��ݱ'���s=�<�lƑ$�6������zb�ƣ&X���ɚ�uw���su���%�S�,�&��n����#��2��iI~�d�&�ܓE��<͋��h�g��`�ކ#S0��L���{^ge����y�9���3��`.��O_�p�(:sO-#��٨[�|~յ$��+��^Z�26|�U.X�h�C�Cw#)�Uq�S�f���4
<���1��,ʐ&y(56.������1��\�JA��2X'�}�%u'����厙�#�
ޠ��hԂ����'X�A���:��dq�P�t���㧅���UY;�Ps��ܙ~�Pxԅ���P��;y��|�v�r�+Y�DB��(�R����풭z�R[�|ۘo���� �跜p�H@x���n��u�Ǳ�/�E
�r�	�_�M��4J��A�@O�ߝ$U����4�JՂ���9��x����h�M�Bv����#�J+���J1I��/����s9;����u�����)�u�3�AB-R5���\Ҙ�ᬑ����{�nv�2���D�a�	4!$������l�:YU)�G�C��MJ��/�hjB^#�VㆼbI�����������ڸ�+�Anw=h�(�`���f������}�N�h
����X�1&*4ĥ�ƃ�Ttf�����r�dL�.V+��vpN2j�J+������O,������a�o��Hp���~u��cښ��X1��YN�A;�=I��G
�eTIp^U&=�ך=A�đq�������͘o�E{t]��H->�
�K���q�r��YaCC+R�˻D�Q��-՟Zm�M'0�@Ľ����H�e�H�>�m��)�.'�hx)�[A�>}hL|���~<J���qk�*f�%��ћ��0@\�8��	��<�*A��F#`'8|�9�T�qo���8֨��O�4]m����^��2�@��8�q��B}��W�KV����j'jk�w�u���>��$̂]U����dlj'.%�c�J*eE�������sL�T"0�| �TWM��U,�tMM�� n�ݖʤXR�AUf[St��K�O�q>���Z�k�E*@l�~Uu��q�'�4#3-̴��:^c� �6���B�D���ѵ������%-,�_�Y2nIe�����'C̨�q}�������b�l���Q(<_���~iG�����{����K�KE�#!�"B&�Tk��M�Gu����r�.:?J�Iqh>������H P�_+�ݙrl�{BV�nU�}��� z�ʲ��cX�Q^b��2�h>.���ߡ$�_�ƞ{�wLIη�Z�{	9�*4���cA�{z������3U���(_��=�R�v�v�(q�_�ɵ|0�a�8������Q�BQD����I�L�\�������JD0S�e�<�v��q�>�+�>�e��_R2��za��(X&�K�3��?�q�$��H�\���;�i�L�Z�j<�6+*܉g~�T~��HE#[ħ�o�������ԓ�_�r�,(���UGќc,�x$�X�U{r����g�e�[��2V�#�8jf_�B����fɡ��r�pY}��5>sbj��>"�|R޼���?����v�#?t:�ޑj�⭤���n�0�����+��o��Ϳ��-��]�R!:A����tCf;�:��d�����T��x.�ъ���QYR�sJ�v�G�����֍C�#��w��,Q*���z���'+�@��:h������˻w��|���U��U�<!��A&f��U���u�5�o�X#8M?OGf�T��.�����e6]��L�L�ï�_�;a���-}v�|�W&a���Rt�b贷8=^�v�����E8��7�uz��=�O��5��fz�Oc��ٜ�g:�O�`4�C>��Jzc�W�~�05�q�^�ͯ?�1h%�/������2�|���OiU84?Y��'�*,��\r��=8>U���ʐ}~���OU^aw��*��~�X����0��¡��*���������j�Ï?X����T�Oՠ;�D�>�
�q�J�WaSv�`	��?>U���~�3�L�O��y��Wx���
g?�*���_��<}�/�*�e������_�c~}\�x�����~~|�Ũ_���'��+%����?�
���TM��~J��٠����>;���O��E��j%���D~���Jѧ*�|�/_��q��ib~�ã��ec��pтS���/����jޢ��4}��]Z��~�H�%f����W0�&}8�:NO�N��¹v��j��ӽ�gF_@O��Y� �c-A�+�]���1�D'r�n��
��,B�v7��׽�K��9q���f����RѤ��;������4�|0��M�[���5?�X�^�N���s=N�_�ٯ�8mM��Ws4�O>�\�'�w[u8X�g���'}�����e��a��e�}�
dg�UH�O� �D��+|�U�*�=>�Ag2(h]�{��7���ga�l�,	����O�֧����up���𸖱ӭu��6>��^�AJ�����xvz4;=�=3�ɹ��������uq��0-��tw�L{w������������<}4���x2y��|���
g�X�T� A��]w=7K�l�Yr�ꨨ0�ZsҢ-&(W���V�v#2���	$+��QFd�B���c'�;��vk�\֚k�f��)����ɰС��|k�]�~�4�X�B~�>�-O_NMM�H�L�=������f��P�ga�l�8��I#7q)��)�0�V͠e$�Xj�rMZ[�]��2��J�L�a�$�Ի����d"t�C�%8�����ރ�qS��ǭNGT�N�:���+��\S�)6P��濇�7y@sV��t�KX$��Qh9��{R�"��6�chұ�p�����	M�-'HȒ�0����1�qI8% ���+H������n�n���w��lj}���e��߁uiˌ,�n�m�l2<�5B�5��5_K�aiL`��}h�*W���=��Y[�Vx+����qzHx����%����6�?��� S�%�i�`����SR*��m����/+�����4i�����4Jؿ.�� ސ�:R��Ntuը]*?8}�)�4aF�NY�+�� M�����hό'"
A밑��J�FҶ�7����z���8���m��y�Vn�U�8���j�D���ΥdE�r�!��b�;,��v�K��ZK�WC8N�OԊ_?cJ	��;�r�}1���b�~O�������o9u���շ�D�Ox����bw�S��z����o�}su��p���k�_��D8a���ټ�y�K}n��bw{^��D�W"l�t��^z���gU���f��J?0��9�hr�y��O���H�D�{"���&���q��54��$�i���D����R������{��$qyb�������3�VE�+)*h��B�VjF).�Ν�4A<6�~�L^f{XJEŦ"��V�����|�X��6��Y������]m���`��+�+�/y��ԥ��ylN9ˇH>�B.���[6����ج; ��5��pz�h�Q�n>]2wѦ�T{wU]իb�Z��d�44�Zj�h���]��-�Q��]�V3jZ�NA�F*�P�Jf�
�9h*AU[B�����go��Y�Y1��,��ˣ�]�\�xr� ���7=��>��6��
�\����z3�z]O�P�,�rIU�G�P��}x�K�+�Wv�~��޼��Ez�r��㯆�������&#��u��t���RoEo�i����6� ����y��N�V±��5����� �r��rO�
#�X�c��?+N� 'S��?F��[����h�tTS̋��i��G��9��V�X�ƅ�ߥ�����,���UX��+��$*�6I��k^H��Q�&Mu1�Jn��%C���gq�4^1�� u�	<J�RV�ʐ�`>���';�O��+c'C�Y�y_?��R��S?b��驒�Z��qHT�L�j
lN'�c�3�qk�{*�q����Rz���>e��ɸ4�F�C�=��*�,��@玏C��c0g�G�U'��<�ި:�q	{W�Qb�Cy�����:�<���	-�|�"�>��!��v�ԥxV�q��=�>[+8�KsT���m3�d�G�.�=�W�e�57l�Lצ�d)�{��hͣ��Z���,#�h��>�J3�S���M��'<�F��;z��]���AyH{�eT�7�
�#L���`c�A���-�ѝ��/d=x�c�\�EX[$T<ڜ8Zo�]<4���P�5}R���|ޞ	�%ՙr��d��b��Z�
��}�!�1 O7eӅ���4[̸N��P�ZU�,� v$myV �V�l���Z� ?��؋��w�9�}��x�$4��Ю��W2̀P�l_�Ս ���9�"��:i�بi	�<D��T�/�g1�������0`|[_�e�Cm�:
�-5�x���p�T��%2��L_<�J��θrC�A��(.@]�u��R�.Pa`�K��GB5�nu|[5~;j_��K�������IZ�
q&r�V����iR�XZ�D�V�\�F�%!j��~����������!ٶ^�J�儑��C�cN;}�b��/3l����z &���g���hꔯu�pL�<�g�վ���갫���iҐ��qU7����wQ�P�V���f����W.�Y�,�okL%�B=�.�H{��r�2.{�͎bm-�%,	��t��6�	�A9�V���.E/�B���P(��|���5	�����������n��y�.I��V��_\�#��������7��v�}cm�L[�'�?����w��������S�?�b�l�'�����Zgi ��,c��}�N��Vw���ѥ��{������$�7��y>[{k�������H����}���N6o���m�������W�h�M�jf�:@M��
pT"�JVç!*�gUkKrkT;$2�3��"ҭ�/T���|��6	
x�D=dB@�&0W!���]�}H	Brq�ڥ�@!ܘ@�@Gk"A����O�Z���|,K����Ƕ�yL�/$~a:��dJq�b�-&e���Øo������sM��UՁ��B4r�d�>uO����N�۩P�}����\0�2'�zW�g�S�r'��Ch:����ˁ	h(�]qP�!�z��]�%¬�XFU+?u
��A����x�N:Oi�Z�	�-�*SE�x�BZ�8�B4��#�V�<"��n)\�?�;������h��/~TTs����d�+�=�tt�����O�ݻ�-��ד��ܰ�{��&��'��l�Fv
@nd�J�ס��/��=�&x���p�'bxe|5�K�� ��ݹoӐ/�4ӪORF�)��Cd����E�פ�.]<�΂����P
Lt�����.ć$��������n�(�[�D�,>�]B+�p� a������IZ�?�����<<O�(4+� ��O�C���2�
�Jv|WZ��I�L�B��#jڝPb�.�Q�sL�zJ�S��g�0�akS��o�Sj�9��n�S�ryo�m�TM��	�/?F��������*񗭃��;)��u"��<œ� �W�Hk0T5�5|�
d�����6�Z�&�&�C�U_z-���n*P_�}�3z�P��J��A�S�H�c� z%C�G0�0��+R�%ɕ��>%�p���e����ﭬ*��Ny��������J��`���=�'ݜ�B@�14�����Ac��;�#�@'��RF�y��xkM����X"�@y"�c�#ڈ{����{r���F�SX�3�g�e����zO;\ه�9@��.��;�#�����6�ڪ�=�U�Lib��6'`^M�F������5F�g�9�V�=���#D���W��ur� �uC���� ���6J���o�Ws�7xݠ�Jŉ���BE�pɃb?���;*�<Ԍ����m�2Ⱃ�.��O�QJ��.,F�@C�l�q"����_R�>Y ��i�����»HJ���NZ�@�J�@�{��4e���\�L
���|�%
�S:}��T���&z��K0�%؁�HR^�
��׶+�J;n(�zB�C�w�¼�h���Q@����-,�e�Yc�r�(�x�EvC��_&8=$�!f��C�뢷CH< �ѰQ����89�X��0���Ӛ�Fh~�D�	������� #���h2�o�g�E1��"px |�>B�Gu�#�Ϩ9��S�.j��,`�5b��9#�v�@vX*|�=V�8���w�̙�j"��
01�H��2-���Z@�1��Vޘӳ�|�Xp!&� 1� ��u���@�a[S�LA[L/;�����y��N
�OE�bH8?���b��^�+-:Me�([�6Xf:i�Y��S�J�LY`��������{�����/O(�n�F�a:����r3�@Ar�����ȣЊ�#�D�bN�ά�O%���`J��V����\R}ߕ	�eC�xhn��ui�|$�.cï&6�lp�ms�W���7�?�|C/|�W"6������4���������aS��R��\���s�:�q����Y`bI2�"%A���I��/�$Q�Ȳ+d]�%����4�N�I�gi�g}��{��;�&��mۂ~W�!���#��)�f5+¶���_�u׹��YW3}r�n�o7���/ʋ��;����}��´L��%�hj@���~0E�6y���>T�{	
�Bm�;
��71�K6n;����v�n�wT����f�(Z���i$�
l��q�8�pY���Ɠ��Z�Nl�=���jϚ�-�;j!��X�F:͉�#'���%.������}��{����^XuZ�Vq�+�ʓ��se>�mS��i0M&�8=��89x���l]L�d�	��A$9�]��]�tx���h�Q�_p��bI/Y�ޗ�vT�_�$�J}� �*vgLS#um��x��{�>��x��Z�B��p�.���HU�j����a"�o���eB}ҴHN��q�We#R?���u˵פ�뎺�����`�\E4�c�]��ގ�k����#��#���e�iU㭭j��)�.A���-�j5�J&��
�~h9ez�
��ǩ�h'�5�����[��nk7^���֐�����|
��x��7{��4��U]�C�]�i��e����u��-=�����x #���l�h��RmQ��%՗G��M��7"�}av?@ÿ�#�d.�z��nV�=p��<�Է.�+ȓQ�-z,�Tv%����fI+��';K��������N:6vr���lr�붺߿�_�]���rl�Su��-YB�L-VI�\Eg9e��J� *�䍶g1V� Ԇ's��k�!�75%����z����F�z�N�w��Y:���3����D�9c�i���A��h�4�V�>v�>��(k[���N l��K.����!�H=�EB��ˇ�oNj�$�*����c��%ɕç����H�vk+?���nZ7��LV�	\5�Oh�Ir<�O?~�Oo0[e�[N�<V�?z!��M��Ĥ	kF%�r�>�7S���+QRr�ru���]]�nD�u��FtL&4J�W~�Mlj�H�j�h����/��ڭ��j�B����o��p�����M��DٽZq�vt�h����6�DH|�<�!��UX�~Jot�R���<���E�{�yp�q�ܭ4��N 5���G����r�1t\�O��!���Uw��T&꽪��K���;;͗��KW0~�q�,"S�\��1�J���k����������h$=��\�ruɃ���x�-�4��j-�@�H���-z��B�<������"�-G����HÈ�fD�PG��uH-mr� 畐K1�ŞXrx���S1\I"ھ ���!�����.��@���8��A]�p�����c���Np��S;a�3|^����Zu !����]�>�� 7���q��ɏB�7HW�0�'OwD7�a��K��$�'��R��z��@e��GUy�4ٴ*�L� =��RH=��J��k#b��WO������]~aȉ2�.	���/Q�&2��Ⱥ5#j^sR�^AT��]��5Z1E�u	$��slzqf�^����27f����+��P��ʉe�<j��X��="�ck(֟逯�la�՗u����{rT#;D�̀=�F9�������7z��������iM?ᖖ���Qt�K�����x&��
|:! ~�����ğQ���@Ş�8�4�>���A�q<�i����&btE��e����N��Z�N7�B�X6_���,!�,����@xZ�DtZzxOM��A����SA���5ϊIO՞�>^��aۓ��k��ִY�V��R�J�&Aio� k��g�Y}	d2�A�?����,@蕵�~b	�Xi̱e�`�6k���� 2D<��dkǰ�`�a��\���i�_b{��z���I�@N<�A�cER�ǡ��:��X��)���}t�\�R�4ӹr�z����K��=@?�l��t��*��xؑ����L6�b��Kb���B:kԫr&Qf���(�yY��lC���QZmz.S+�`pe{X��84붝�,�H�_�-���W�;�d�;Թ�B1��g��%[��s����l��(�%��0�wE�r�#�ڳK���k;�c{q">G��'=�b��oJ���ǋ����;p=�?:z�̢��g�����q�U<BZ��X�o��/w��.ڳ��\����T~և}��$�G,C���5(!�s;���>�}����C?��m��FN�yi03xT�<�t��m���4�r&6Qf]>��":C&A����Ix��A�#��EV{r�e�i c��]�������"Nx���J�;����^���Wt3@7e(�>Ǜ���{�����Ey\�?�.B�Dch,݂�^�<�	/�6OD*U�����=G��=���K޸1�(�&E�i�y�Iϩ��٢�wZs��1#��j*h0��"U���%i�����m�8�\p�U{-����6lȁo��I�t���PcƲ��cX���s����YI<�Jjm%�m�&F 6��`[�m}g��о<H�Y���.8�1�x0p�����bi�צ�^8=ԝ�oc��h��AA��O��Þ���q1���)�F������v�Eºհ�
�T;j�z�)Y��oU�
o���+`�bH3�z�DMO���2J����^��79�'y�>N_��+X�����*英��e���Á�e���,����ܐ�&r��+@�7|�6�Bߤԍ��9�A�%t��h��~����VW��^ˑV����ҕ.��B㺈oO�&:��%�/xcY���M����<����qg��Ñ?�4Brg���^�!Ed�]�a���v���H;��/l��;�z����|�P�5��\�T��z��?
;q�����:�X��lV$���3S�)���=�2� �њ��^����?�BqtIO$�ò�ѩ4(�]1��=���R$�o�y��Zr�1EJ7#�&����p1���,�Ա�J���h}��5�>l(^?0}HW��TAn*3t.�TP�z���9�ȳ03cE�Κ%FD���B$�$�#�N���v�+Ga?���l�4!	��R�C]��Ռx{�A�Ȉ�Pl���0�uZ�P�X�LSP��>�.���?������h�3ӓX� υ���P(Cyc�����ʲ!�֣�9 ����Iј�E�	b���A5����7y$f��m��^D́����Vy���< ������)�jܣ�h�Zd�z�?@�g���4
���Ne=���GG�<�"p�٬T0��@��;���#h-�_ˡs�r�eGsn!�	.�����������G�ѣ��$p .>��ٌdI�0#��JM��ߡ6V�EY2��z~��B�B���3�կ��<�9s0n����F�>1��G�L
e��y�̯�ĵ�F�F�-5�m����tu������D�c����i_�9��i{�����N��b���/8Ys}F�&��k$D��i�
zS��{�z�c��vf��[�;*r���s�%����������p�o,J%� �~v�⹲#���m�A�1��ڱ�e�����
�%�
^q�1j+Є�V����J/�0G�xP�xhw=�
G>h�C%+�xȪ�$�)���*�$��ˠ��<�z�d��?cbB��R+�m�
�q�xL�=_�"�BNGq��T��5�"��QrU�U^��UDc���}u�����=
����jF��u�<.�u�=�DRfV�^��|�P��w��+�[��ҍ���6�=[�T%:�N
����2"v8O{�0:y<�V���:N6�L��%q�5(�E�Uq�и<��Z��.��{	QI©�U=�F��Sz�K�2��b]u,h���\7G�d侙[�ؤhl��[� �k�"9�M�$�TJ&�\ƹ܇B�4L*�X��K�}`���8Y��?���^�P�=��z��+�WD�2܆ԕ�D��)����Z�-����܁7v�[���v �tkS�|��n`\[5��[�z�؊p�Љ�,	�	f����0����`	%�t?�#�B����o	ݡ�fR�+��Kj�#�tņ��jث��dK�o]��Tw\�R�[b��6��p������@�.q�n�7�������@ZN��Wy��Ѧ*f�B;������E ��t��v�ǡ/]�M��Ma���Ą��R&���j�.�L����_&];����-y(�]Ѵ�K�*yLS���j
|Rԋ:�X���י֥N㗙�GleQ΢��a"�4�-S�%�n�A؈}@O���B|E�4�"n�u��Nvf�*%�8R^�*����:߲��J��"��<N��+��V��؄������t^�]f���V�:č���zĝ/2&�&�k5���,*g�Sʇ���JI�%�{�Z�i�ߪ�X/Q��Qd���i��7�ib5,�R2����_�N�Hu'�垖���ӒiV����Q�0�3U�C�m�?Rjt�A��1���p9����k�Q�������oe]��(�-��:�嶅���X.�ʡ;T������zxW5�c����1TC��w�{J7應4 wu�<�iI����m���곆	���aE�#[6�m�}YS����S��ڬ�0y��f��򥷋�M-�;�5W��eN��ΆAX�X����]�m#�o��L�62�"����]n`T>����-M�ֲ?�\ʲV��I�H�� j*E�����U	�E��qr�����z<>�+F!����4���˹�t,�����Gڈ����9h��-�N� �HQ��P�B����{�������/R�U�gpՑPf%��.�zC;�צ�l��a[2�|�|?����G�=.��,�2\)�p���L�4C��0m�����(��iƏe�
��<�!�A-��D�_�8S�ܲv����H�1�rpAs
Ņlr��ё��R�� {4�������@�ӷ	�H�ۊT �BG9�@��-<������4�˭R�8A����`�4����|�	K�;n��!�U'�U�1���w]�@i�"�=��F���dI���`!7f�a����X��?�H �ߕuaBT<g��=q%��q��,�q@�!GQ���<i���l����]�-?Nj�����a��T܁p�`��Bfǭ�����F������]xo�6O-g?���R���:��N�k�&���v�h���izȣ���hOm �k�7�϶��9�N�����=}��Rag�<�I7IC��:�N{�����8��v�K�$�n.��+
z���#�?g���=��~��H���ED��-&X4.`�x��H {��C��`
ܙ�-&t����I�����ǥ�I�_��bb|��f'�]SQ'�ަ����f�P_H&�m�����(�r:अ��"abb���C��	Vѽ ���U}��PD˰��#��xR�f:\�;e���:U�ү�: 7s�v�?����^����r�� 	Hq�-�L����r�S����x�V�KE�?o`8�>�Vi=�
��K�������[��'q�"@^�Z�:\�#Z�Yʂ~���]�a^X����<��p&\�I�<���4���οA��s���NU�Ng-%m��� ��YT�*0H`�� �̣Qi�V|��
�|��~-��̔�Ii��L��ݝ'����w��?g���ڶf�����{Υ�;\�!#bb���EC?^o{G��+�~����"������&b2D���ݢ{mq�-�>��1�e��̱g���."hCp��~��rq�ᨒ�5�"	-V=��60��s�*�|�ۧ��c����h�����	��l�/�4[����H8~�ǋc��U��oU^�c��K�u}���!b�G��^G�
��'Ü���]K���˕���E�Cֳ����`��xc7)w�x9}�Ă}�w̲�jQO��u�H�#�R*�ǰ]i}���u��j����p|�i��l��g�iH��c��oAyWZBܰ�?[7�M�c�!��E��\P}a��d��o�2��m`����a�C���F節���Z	�SG �4�
9�^Kw�{ќ��jL�BT	3��Cw�k�)�F��)nά��E(��ŷ��E������z��]xn�Ͻ|ٸ/�E�ڌ~V�pL0@fM�pܻ�ސ�/��	K���~٠����˖�x�^����|԰�T�8E��Χ�΋_��b���I�ߣ���X$����Щ�r?R4�b�R�x$F�i�nr�uL��ё��}�����S���Rh�+�\���k���%��ځ�����v��A���ƹ9�'��2}�bN�i�E�P��ޒؓB8���1�ff�<��|��a�P[�v_�&	�\�˷��_ؤ��yU�`������QV1	�)��&��	�������0n�@e�	��Z����rD�(A����(�M]w��np����M0���̆!��\t#�8��-�ڞvUHT�PD�1nu�כ��o��*`'�t�_�s�=1�"�f4Ⱥ>�YGV�[�%�r��!�3K����
���q#��G�-D�%D�DUHʡdw��|�^ӆ���n���&��)�@[G���9Qs����vo�� ��6�*��%��z��g~ʫ����Be�������a4�9^U.E�e�˙c�(碚��	=�����y����ʃ���	���vt��/���g�GF�8q���`��i�:8E򍕙Z�Z�e�뎱v6�Tgb�0�K@�/r�PeXM.�K}���C���0��ɹ�b7��I���f��m��CO��K��ﱈ4���P�e�	M.q�²�ؾTLy�;��o�G,�}H��F]	m��pn�c_ }�Ʉ�!��e�t����֟f��G��l�X�#I	�(�Ȏ��� ����"�|� 	BF[
17�c�1���&T4��W?���j����t��\t�1q��=�G>���ÛU1���)I��9(�� �5�
��Hs'v�'�Nbd̛�e/�X����Ͷ�-x�Q��Gx�H�*z&�`a�b�:WG�6bWD�Դ �~@:v$�0�uM8}f|zo	�P
gla�5�/�,LIAl�9��P�vPJ�|Uyw$��\���/�l��ѯ H�[w����\I�%f%48(|�c)C�Q�cP�i�I��&`6�p,E��;��LЉ�bc���j�`g��� �n�	�i\�.�B�M�dS>��A����{�@r<���X�"e��F��%�ۨ�v���S<�fSXgeGRj��
��(d)�b��*rn"܍j�@xu�U�;U�I��G`���SspDx���"�(dn���k���[��S��0!�J�0�v&�-pk��vv�o�}A6�K`�g԰呿�a��zT�C�|��	��U���G�6a�t$�K����y�q��d#�VQ�x��{�q�p�7M�����4K��d��p����iXy	��2��橬�:�^+rG��T95c������Xu{�0y�%��
禩�NhF���]��z�g�|���p*�T�L!�Xm\���lfx��T�㌑�I[/�G�k�<�:��޴�Qy��������~�Bd}qFg&֑oF*!�*�8�	v��J��g��h�[�K�J)����xǂܰP8Fcn�l4j��/�
U�kgA=S�谷.IRZ��n�f�<n9/��F��]�!ыbN�A��nB~�GM�e���������Wu�Z��@.���<d�v=�GN.UH(�ه���pP'�,�d�LFi�\���KX����Z	�y�̓U�����v��$��1rW�w�/���	AL��f�1��f3�8��u���(�ϧ?�3K�'�Xw<��Sq*C�YqxG�I��n��\�+nt��t��e�C_��d܍��-���Y��������W�A���P��;6��ve����[]�T��v ��8`���ܣ�¬T�f��6��T�
TӗBk��]��PX�@�.U����Q�Fo�#_� �sl���ˀn<R�>����5_>���J�|��W=o$F�3��auh)P����jp��A�bg9o�^	o\�2�Q�dqj��͆��pZ���=A��XmBF%w:�z��!�3�|:�5�P�!�4��Pdp�)Z��rLRb�H4�4�^�m�*V}�+�y��pߜ<j���!De�%2b�'F�N^�4�ݺOVEH�J�!T�ƅ���4����J�.q��Ie�ғ �z�+��Ր:/��¿U|��G$R��\Q3��=�{���(�X��Ɇo[<Q���o����{�g:Œ$�]3��v+5���/��CϿuܸ໡GQ?�/�������D�eg�͉��얉,�&�4��m�^gf����B�����m�Yo.��O��-�P��	$I���r\�JsY8�\~��Fs�g�.�#t�3H�G�����I�%�Y=,��<Q�Qy���+�8����_�:ە�:�3v���Ҥ/�c�z����B���#6}�����A�qq��R!C�\xA�m7,K�G&9c�h��'��ZǇ?N�[�0�ӏ����eC��V�X0��F�
�-F�#*2πFF9[.x��eĵ;aȌ
P��/�����Rg��X��k[����F��~q����W�c	�U2��(C�;GIgJ�z�	�X(L����i�@�h�y�\b�m\��CLa�_�b���Չ�V��ɐHO-�|�ۮ%��QB���c{�Ce�]Yb�4�\!8�[Z}aΥ�!s��r�0��')�{ƓZf�g�ʐ,��r���n�C��̱�ߠ��Q�:Ӧ�{@��5$� ��d��J{d���2?T��[��OoB��Fd�ܚL�$�A؈j�)�[8�	3A������!�@�hT|b<�q��4q�(�um*�L��_I_�w��F���p��?��*�j8�UrlH.�s��<�}(�zbٶ_��M��,����ۯ�]�ڀc�>7�Z��-��"�g�xp�t�[��T2� nl�j
�s��ь��"H牊���ތ�M����:����WFS0Nw�A���W�y[���ʁy*�ZB�j�R�u�|��PGkB.we��+��(�,�7�\�]�|��G8�x\8��9�\��O�׺(D@Z�������Q�S�_@�ʝ4����O�g����؀r隸��7\V�>8K��כ� ��b����h�F�Ah��,�s��UX^y�V��~ŁW��R¬�ێwv=�C�v����6t� -Þ���k:�u��HGa
����F 'MR`�tZsh��5o�M)樧X��-���@�U�iYׂ���*��������A\��J�5"�!��J�bw����Q���ρV�B�6q�Y�w����7��b���^��H�C����}���8T^�EL��C�"�J9��G��h-�fi��[�Tz���7�lA%/"",�����S��js~\SϗU��_4��v��̺@�ƀ���U	=*�����Y)�zp#�%rDoYӴ^H�? ��F�V��̠�[������&�^��gд�"���,&z�f�E�8��*!b��!A҂*)סg�	'�C6K�:���ɡE���>�Ϥ�SX�1��7�9��������Ҭ[�r�JL��<���d��r5�x���	I[�T�����c��c�w%�Z�1ʳ�[�U�!��XY�Z��i���g^�'������D��:F DP���6��n�,��}�H�����pN�E�¬'hc��!#�XK��5��o\��,"|k��e�����^���%��B�R��_�Γ]g��Q[N�����V�Y6��5M���b� ���rȍ6�bYN��d�OQ]ob�Sʎ�maԃ\��d(����J�J"��[�����Ѣq>V?d���׻�^�iJ�2iJ�2m��2n��2kj�e�)�ga�c6��0&?�8&3A��+x�aL�f�0�;ԭ�=5�s�i��,��*2�����>�����b���7��7�P*0����g��]��7����d�-	�l��C���s.���9p#����/~0�������S��9�Ǜ`��y1�ŋ�LK�}�h_e�zh�g�Z��Q���Q�eЮ��a]�,�f�ܴYM�H�$,��9_%�1��^���h>�Ģz�$�ϻ
ο��kN5���R�3I��"��
>i�!X���,�S��A��� }�z�t��T%�����Mm/���w�)�������sQQ��WRO��Z�:p��6���^�>p{�����0;^�Y�����ǹ�P��>�����aus:ܽl���������>Q���a>M��4l��>�L����R��\y�=��r
6Epǭ賵�9�<�k��u'��k5crF�߻�v��b��8��f���o�?���NZ��G/9<�8�C�P�gs��q6���gs�lr6���������=�3��u6���gs�lq6�͖�V�ɻXg��q�,���s���NMf6Q��Z1�������hf�l�o��/w'�V�x�ƵZk0^Z�?�/j�f(nh���j���V|֟�J�HcR+?��\��Ԫ�Zm�[	V���^�0T�TQ���6��O���S�rz�ίU�k�O`Lk��%�VmQ{5�8URCo������|X+�ǵ�'�3&|~ת�l����t�Ȭ����ژ�*��Ӛ�������k�O�:L�,e\���$����"���5Kw�aF�P�x�hE��0~�(½�(����j��V�}"f�VO�+�j��$NU��sM��Ԋ��Zi�Y+Ϸj��v�:ߩ�滵��G���tq���^~�CB�/�p%.�0EN]���J�j����V�2ju�ϧj����T]m��rOյp7'�Ziޯ�[ߕ�Z%fת-�S�T���Z=�D��$�>���X�yp�S�����k)S��|Z�̟j�v��j���Z=L���6�{4U�BKJKS�
/�O�X��E��Э�"[�Z}�NH�%�$�˴uh��3Y+E��j�6�Y�V��j��]R�-X�z�U��L�����+���+r&k��V6_��Q�|�ժч*�ڂW�/�װ�#p��{MCI�D�VZ� �'k�HȯU�T�jao��$D�%���N����+�L֊��PmpBkO��~}N]�J�E�����"�YP���&NC�x���W��5xE_�_(�u��<T5�>)�*<=��ݪT���k�Z��M���\�%�'}a:WO����Vd�͏OW����᜶V{a4W�mv�X8ϕḻXXΕ��g-\�|�YƊ��g�5WMG��gu����Bx�c�zs�i�V�����*@;����(���輪<?35�Օ�0��l'�1�n�F]�x����}�_��������-��.��0@�5����b��蝐p�J�،���,��zq�4��,�����6�|9�ɠ?0����RH0�î��� ^	���6�(J�]�!��,H�]�؂׾;�̾��c��?B\�s�d�h[g��	m�r��R�����]�'IBZ.��;�َ�(&d(�����N!��X�MN�%��:W�ܐFUP��uh!ems�9��1�B �*ZL��4��L�4����l�8�V��~�'X� �5���@v0Λ`#��R�%��ߕ�0a��A�r�i���UNG�o�8�ri@���0�%n������6$ol���r�m��&���2`4 [�ؔ<ܭ����)EL��4#���py�ې�t�u�qO�B�	��w�ؙ$��L=���,�(&���o ���*Ė�g3,�\���~�Pa��Ǎ�-|�\�?�x���+%�_#c-.9V��å�s��d�"�w��q�nsv8�#�֯�n���=gW��_w胱b�"���sc�aB�ţ��ܕ���!�4��[��h�p�R�p)S�d7���&c�
���fF1S�t��`�V�_�6��
Ԏ�%h�� ��o�a���KiԆBb2�'	y�7�J:'�P�`0i(��N����z�X krFIY��jt�c����:����f��X����餜JJ��/��ы��Z)0�1����9��gG{}}}�F4��桵�N������L���|����Љ����b���2MU��A6®�,��3d��j�.l�C�$i��:ӱ�yj��S�g��i���L�d����͞!h�;�VK;��餷멨�O��,�l?]���F�Ӂ���>Y�ϟ�y�6��k����M�-�:W����W+"��^���h_��Ai�{�p��<�y��-�З�j�2귻�e�_�yZ�>�	r67���	3���#>���)J���{J#�B�y�$�ІO"��Nx批��ZF�tw����+
�p���B	�Z�e	3O_�Uo�^=}5��d�s7|o>�5���ww�O���Q�����=�&�ʐM�M��"C�����;!Zh��������5{����kR$�/6���M��F3��(t�
��?��G4T��d�S�c����a�Q�}Ck������n�;W9�������|���]:ee@xr|s��<_�k<�	'$/hbѡwV4ȸ�z&��)��C�I�����}��!\�wI���%�T:�#��H#l^�a ���>c�
��#��E!�����%�uA��uա<1��\��u�gt~5��@�]�F��}	�~��[�Л�Z��5��sp:Ӯ�#��(�\���.n���=aG4�a�����o�(P
\�Ԫ���@�G��l��:���݆���!��K$k�����A+�$�a��U�39���µW������0��k��9�hz�ĨRO܀�����w�g|��´GϐH�����F�e?�<$Y�qy��t�	U�1"�X���|@��g�!g�N�܇�r�~�Ro=+ɉ8��;�DgXv�\��	nG�G�E	6�#�j7�� �+�����;w_m%�d��� }����p��1��\��[q�zՔ[u�:��ntp+�Ž�C�(���D\� \��-�<�)[�hQ��]-,��$�2���X캒+S}L��$��$��1��I}̠t�~��Etl���fH��U�a�Ս���<����6�	�3�6&
��NWl��7�� �KK���i���^��R���9����t� �[�ER�XI�M�L3�]�ـ��J�Y�������)�Ⱥ�Z�v�t���%�������p��A�|��	[���d*���s�.@I��5̚��[��t�e(�$�5�)(G�z��	?��|�-��*��顔s║'�@���^�=$aS^���=����=��?�����r�<��{6�e�]����a厽tD^;�he�O�?��[dE"b�|�q���|���J��c����l��M��Nt:�
 ԫ��B���9�!�G�Q�"Q�(ds��|ӭ��G�[����6��t�)���t� ��q';A��)��D�Xަ�����W���C����}���l6R��:�C
�a8[ç������FW(�X�߂.�r����6:ӡ/ �O��1����iC'&�����!R�3]��=aw%^N,����}1�0�?��~����O�]�'���g�x��H�[�}�>&ߺ���j���7�h��cSY H��WGc뉅�p]�S'�W��ue����:���H|��Hs*x)}��'�O����	.����҆�B�<[%k,ה|`2��&�k/�߇����|�|�U�&�s&+�������$;S�z)?��(�pc�) uy�����ê�5���nVe� ��S��BK�����⇳��z=ܡt鋅�B,J���e��j��	��r4>��&w&�X"���N�|(��>�~~OTCX}�N��{��%�/pώ�C�R��{mJ�2���5���2?h����mV~�b���P�i.�J�2��������9��n*�f�n�vf�K[v�^՛��>(:GF��&��=�cl����3�g��T�����7�\O�+��_!~H��o�:�쵛l��$̺�<��D�v:���)��Z=p5ڂ����S��5����v{�>�a:�f���$����k�*߰������q����jT?��n�>�;:>�����L+�y3���������-��'����=� '�rR��p��{�~��*F��c�����J�]u�s�%�,���;�%�+��O��V���OCq�?�WN� ��6∷���K��]y�>���M�u��ǅ)lf8�S�z�Uq0{>�V������(�W�Ψ*W`��@���q^�r8�����:^�!�_�P���&)`�Q��*���0�w�^�=�H:�=A���kv��*ֿ΋�|c�s�c{��������?fq��g�g��3�[� ����<��#{Pi�c�z�îbBJ/M1ci�=j�q=C�A�Ӷ�J��Z�E�;oAA�)���	v��x�v���v:����zxH�&B	�٢Zh0&.\z~����;��2s�u�4|�K>�vg�
�1��晞��oUu���\��p�N'��.CM��`�<p�A���!7n�Yy��!���t����۰WS��o�o���Ƹ�Ѻ�I��:�I���âN�:O�U�*H=l���E]%Z��
���;�԰�Q��(OS�ᚤ�`ն�4����muLv��[�{ꔔ���LX��M}v[��7���W���R^9��U���o�`��;w�}��Nڕ�����̦�xzlIPGz_��Pul@�I��y:�78�Č���f�rq�٣j��b>v��.�'��� ��#A�&�Dڇ0}�FOh��~]��C}G>�����i��0y�9���.ru}Ɯ��tcj���<���{���[I����u�e2��2���Kܳ&���`s>�vE2#��z@�p�6�v�f.�QmH����mf��J�G���G?+�����ޠ;����}�Z0�3���Z��q��p;��{����iCro��@��L�b޵o_��]{��;_��o,��e�l���xW�H����m]��9�v��8L�>!m���b��"�	ǋ�����alo.�i�p��#h�My���%g3It��G������b.�yrw��t�қF�ܸ����Fk?�o�FIzfdh�m���ZtW<�o|�J�����2��E������l�*y��m2���+W׫[Aoi�f]2D5b�b��ś��}�c�������C����uo�ZLz�pm�4��`��4]6��#�SO��-#�Buy�Ɵ��O��(h0�q�N�R�l%�gq�OE����zb����P����z�9���[k��ѳ�1��V�EgP���% 4!�Kڊk<TzŻ�L���gd?�>�>F�$>���!���P�s�';R�p�r�� wȥ��^���o�}<>�ą[��A'��ۣ�dz�go7���<ҳK�ua�6�£�j���t������xM��x�Q~��ȳ��NޒAO�C5��A���+̂6���ir2��4Aƪ
Fq�k5V�x���̷������0���V#���[��_C
���<_�)��6��:c�l���b�
�� �̙Dܔ�O��|wΘ�0��snz�o=�&X���iKɼES�K���?���yY��ԔuI�E�����U�+cm���䙟��^�#8#6M��o3gM��d�P\��炈
�{�|��e�oME�!�O�uc��-G��[�u�І?/"t @��B'"�0]�������z��� kG=�΄���1���\D�e�~����_`��o��� J�`�m>ߚڑ��SRDsbMⒷB
O�v*Q�Y�RC^�ʢ�PՆf�����RFlؠ��׏��ֱ�n��W�D��<�6H<�E���0��-JiQjH�RCZ�ҢԐ��&���0���h6�E���x�@���8h��aÏF��Ɖ,�T���<��Wr�eN�����rm�/T8��:ڵ�81�le��І1��V�œk��<����#}Q��'C��O�W- j���������Ĕޖ+��ruQ]�/�ˍEc��h.�������r�x�-^/�FEI�Ek��h�%��Ł|[�ΑE6�b��x�\�]�_YGcI�˧�3p��}w\Ip!�����$!��߄h	󭈛Jn�x�]/>���}��[ �$�-�T[��TZ�6L[K����a
�4�2��
�]�H��@�P)����j���sk(5ՅO�Ĝ����qY[?��Xos�/�����s�g'��Gyw��4�\FU�a�1�wW�x�zS���Wh-��K¼���S僊 �!M8Л_��	���,.�s��	�b����g�;���s�W��cD�lڳ���O��C}���(M��Y)�z���/����q�#8~��W������Fo�O�!�'�>�����;�����W� Jʜ��ٿS[Z�|�!m|�ծ��6��-�D��w��'��V{�v"T7u���=��E�=o��`�C{���ʳ��|���oU��њ�D(��FQIj���p�rL��7i�Z�Yc��Pį5YL>d]'y`BQ\��V��`���y�3�Q���]�nh����jϻ��h��1Y@��Ɍ&Y)ߕ�jݕ�������1��!��VYA4�����iVF�nL��u�}F�~�Ȟߴ1�g�ܭ����˧�Kg�r�͋3eҹ;��n�P��������e����[�s6�'������>�0C\�|��rMj	@��i~:�*�bj<��Y�X��8P05�1W������$������cFh%X�!�L�
�E��IJ}"�h��Fi�=Z��:�wF�X8M��2��zŤ�sI{�C.��[j@�?vZI� H��r��O@����װ���DV6����O�E٬�,B_��<�;� %u!s0��b(��v�ـg2Q�~�aH�������H(6�6�ʊ$�0�5��V3~|��Y�ӗU�������|��GSdq,�B��b/�� ��ߢN����`=��r�x����[&nd�8��V�L����+V��S	[�bK���<�Z�m�
;���v;�&X.&������|�D1u�r��Cm�
��#�ϲ�Y�%����!��S���"b�;��0?��,�bG{��|� ��)���]�w�����zG�P�V�W�֋6�/���y5=�7f	)�J!�u{I��B�`��Y�[�SM�d��
Z�r�V��~	eS�:�	��90W��D��8�Ӊ����V�O�`����ܫ��J{~^�Ƨf��uq'~���ܵE%>����&��,��C�i2�
ZY����LץG�&�{����wk�Z�M6�p �F���!�H�mv&��qZ���Q]�AZ!/��� �-�jC�]+D������rX�b���ϒ?J���A,��N_�Sg��{dv�0	2	��LU�gޮ��p��a3��ۛL���!�s�N�}xibB�g�����s�c��j�>���xN�5�Υi;��Y�!�"~��r�א�ε�?X��L8��ȁ'�H������A���4�|>��zIL6|�P��g��i��mQOA�}>ί���վ�����;�rC��f�(Cp�i���Y�Rh��7��E����Ah�˞ͫ�0 �v���$��^�S���s����D$��uQ�yX��ey@�jlQ��.������^�0%�T��j_�}�v1/��6���4_��>
�g/.!�Z�̗���{�D��Jj}���ai�4��h�'�'��q��$�G����d��*��*z><rj]9�p~�,����ѳ��dX�!�Y�z���&En����Q�I�S���ALcL�߭�9,j�s<'z�޵s	�4GX�yר�|�2��o���Yd�z��RH(��P����b&�~\[:O1�ZﵾF v8IĹ�|r���(u�x:yQ�dW��M�����A>�;b3�{�u������1D�����چ|����A˝r|��
ǒ��/:�/!�sV��h]/q֣/2"2%f)Cm�#o>Z��l?�u!?J`ɑ�Ɏ9B��E�'/$
�,�?�0��*|�56;�+C߾��~H���eW��G�y���a�e9l���ϰ&�k.r΂vD��֕_��M(K*2|�5>��ezY6����)�vL~"�b�5Ǧ�	�}��u�Qء��l�7�\|f��a755�+99a���>�
<�>Cг!�.���P�bQ��b���>�jk����d;U>�����L٭�����υ6>���޸0F�5��J�S���e��bZ����:S�Z���4ܝV��R�P�p!�KI*��??�Y������{x�x��d��{?X�5�[F�m�K�1�
�(���(}�MV0�����r�w=��n��sTx����0�������L-��p[:��Cw�2� m3��d&��v�� +��Q��`��/T̒���=��UA�61��KiG4D�.��^��'��b�7��U��)@�+��+1p�z�W�bD4M.�!��$����;7�M<����9����9"�ABnw\Z�(c�Ϧ���?��Ȉ�D�Y�t�i�J�i��D+*G��S�3 ��亙Ai�����*�|	6נ��@����,��Em���%�z	[��M+�uPv́P"^��
WBtD�`�K'c��h��\f�r溤3�U�ͯq�����С�,�K��m�^,�P�B�z�7�M�fSPĤ��2�5�Uq��	`������y��F��r�g�����{�������*E^t�|5ua��חI��u�1li�G�
c��C�̸�Ʀ��36Ɲ�����u\����j?l;����}�5[��y�J|�)p�})o�p{->3E.�;�č���r�P�_�r'�4�r�%ө��
������A�Ȃ=�P= ��VK��fZ��5�b�����yT]r�����M,���zEE�X�3�B�¢ҟ��A���u�£͖�Fl�v���G]AH�W^'�?����&Sqb���	�������8�v!��g�H��k�~q�=� A�a������"C�:��$���X|�&B�J	m4�L�*r�8��"�^�:Ʀ���쥝�V��Ž��Xb0�ؖ
�#�/E����]&\<���ָI��]]s�q���l���` �<t��raj(dKհ����@� $G�y8��ClB!fJ4у�f;�O���6�y܏(eX����sD,o���P��d�t�ύ��q�@��3x�;h�?X}(Ͽ߼�E���`h���\j�-ꩄ��r2I0�����Ia���oe����(>!:���4�g_p���5ؾ�
jr�v�sp'0�B~��u��n�Nu���x�5�e9d)P��5���<��9ū�)Z�L`5��d��N@�Z�<0>I�Cm9�7qn`n���>����D��q�	)��AZ[��l��4/i��a�\,� ��7rpܧ�,``m�q`ɣ�̐f"���a�)9�(po�й��� j��A������Z���3��sB*�J���?����������՘�)>��/��e��O����x��[B��gd~;��@O��p�EC��o������]T����V1yp54[x�}w�=��6�>v'��N�y� !�������cJ�y'C��z���i���D@s��+�δ"z��ȁ��(��]�+�HäˑQ;�S`te���K2#�����PÍ�dШ�OO��`��2����������bܳ�]�D^*��J4�Y�k������ޣ����?<GWX��ͫ)�����\łh�(6�)<w��y_�/��|�����j\�.�k��R�ɴ-a�f�Ga�GQ��������g��W�p��G,�'�@�9�TB�/F7~(~|
$Hk��w�hX�6Ӛ�~~��V*�T.l������k�����E��4�(S���!N���ָk�> ó�s�hA��rN�&�W[�QO��7\�j�'�m�W�2�����KCO7
H����b�iv;�W��ax9w�ޓ��,Ql]�O1���7u&��zF�����`�����������j��^=��nA1f!:�p�=F�x-?���"��O=��`���=x���Bn[�K��3j���v(U
d���\��6h�f�6�̈I�����M�<���fct�|����\�Nc/iߍ����6	%MoܬF/v��N����"_Ѿ́ʃL��q�)�ـ	1��C�	�$@:�~�7�%|���\_��c�v��Yl㱺ٯ�R�rZ��kY�S�y�4d��HJ���=��������YJFZ>����cV+�G�{x�V'����Q�\#�͈�f<�r�nt&���c�e�lѺ�X������a�F�����z��P]63�8��l@��E�%_�|�5f�Fp�q����[���$��D�W��T�a&K͡Q��Wb0jYw0zX++o����A��Z֟����n��o"M?H��+g��6^���������jϘ�		�|��H�J�sG�Y���M�΀�
���!��t>�}6a���(�,jH��~�p�s7�U����(�% r
�"UE����]7$���]�+�0���I�7(F1:ZC��e�hJ�bp�(P|�z�1m����~g�?�!�A�рh�δ�}C��ɋ'�C�/�B�>��G�dC�~���a�=.�uV^´�B[=�𿁸�I|�yR�S����K�s�6��Bp"<�zl�0���]��ܳf��^H{5ʃ����D0�{P>�����S��3:?��7���{�R��~A81D��Y�]�������H�1�_�����C�f���UFCm��j"��~�vp �D�~�Y���H�>���W��(O&Vi�%p�hk<p�u�QE��xb�N���"�SgW4���t�9�VB��n��@�(�\G��2G��0�>�=�$����H"%��_8��
.��úvJ���*�;��2< �7y#��t$�-!����Z�0�IW���:�ɰ&Ω~�����ۋS�~��������q�����ݲ�':�(��w��Qa�� @�L ^�;2pt�R�p�dէ����u/"��{�ѫ�&hf����"t�}����O����};_1�\���F���Kg�?B����:oc~���:�`C�<�|�Z����� �X|n�,��F]!v��������q7�'��>�mJ�3;�OB�y(�^u�QCG��E�ø������a|�1�Z���5b� ��5�k'(D��G'u�t:�}J���D�:��>�'F*��'�(I	����Z#>M���E��0����h�̈́�x�!*�����4�>3D���4�3��}:���;���v�Z�x��o��������^�>�ߣ���Ȋg���Ց4v6>'�}��睌��K$�I(����"�z#�,A1$���t�����򻪵	�g(�F�'4��m��I��P\5n�2��{7|H��.��y�B�L��]�������F�G)�p�ޞ��n��r'�ٞݚ����S��Q}�6A�=
f������`�M�wÑO����\�hVճt���߸�m);uqɃ����lZ޼�j�jZ
�6mZ�yt�3��`2c�~�.\�o@7�z��L���H��wp�~�~���B6 �
.z��#�[]��L���HY?:��S��)�!�自#��;��x�B�ζ��s���{�o���}���e�S������J�슥%Ѳ�ÂbR5R�֎�EI�h~�;�2ɆE��"�1�ڣ'd���g�a���{�!�m^96ܛe�С�\�և �����J�8�����z�]#"6u:���twXD��� �!�a�������!8x��q����F�c=�z����>�� �ܮ���� �+�s�$+	�w�1:/�v	�iX����)����-�"�}�=�d#�;���H��7�zn�tdn�X�b�����/,������=�
�Cr�%C�Ń�Fq]��Z�3X�&��s����/��غ����o06�#��6 �w�-´�o��U��XZ��������F��k��;&;����;���p/��6e���l�6��-�E����
V�'���a��_��)+oX�xN2ݖ�|�q"t2p�Sߕ�1�>�N�<���V\�馣��`&=�*n�2��^�-5��6^y{T�)�#A�,�sS˂y��6˼�I%�R�b��~y�9�`c�E�P�s��y���Q�H��_�-��^��9} �0\��Sr�6������:S�����9#��>����M(�fq?�,޷'[����"1<G�,.�v��JLx�8�g��r$`>`δ9�Ď��+̦���7�`������7�<%�#���5
�D(q\�s�Lo�e�p�!���'!��������z��/�e��Z9�ok�������}A�M>��b�ξ�S�q�z���t�����=Ә�"����:�V9��\��<H�kȘ����H?�?����<���_����l_������&�>���3����]���:�)"�]�暶���Х.(g`,hg`.�g`�Z���^����AK\���GM�P���A�P�(�nI^ė;���m�=�U���h3��j�|��b<	�2�3cu���Y
%�$V�� �\e[���Ʉ��3�cs_�zSְɯ��R'��E��I�jh�X5<�c�]L�T%�
S�Js�nY<eV�"��ɦ��S���&�,s�?]�n>r�+����l�mj�`�Ã�a�+e���%�	�.���S]��H[n�Ԇ�V�VJr8�a73�D�ό}^�V��l|V��n�^��p��*����"9�b�ޓ�4K�m�&���sUqi����R^Eq�UԲ*2�Ju�j�W�Bz+Ko��+�U���*��'�1_iL1䷕�*�JE��x9^��.������&�5��x2W�����{s�a���0��Jss���9g���
�v�7_�k)c�%�����j�
}5�~�j�f�cY9Q3�4�E�D)���jm�IT��>h=�W����U�mlUX%�<t�2BwH�+1$i��e.��ؐ(�4�UE4�\V̰2�e3�w��D�Q�������MWA�4���QY9\��9^����t�f�Z8��-��}��I;��5ם*�5��jd̪��f6S~sH�Zo^Q�W�KM��<Ha��\q�V���+�����>�j4��;5Y��5��+M������⼆�\n*7W�*�~*�3�>GV�w�+y�AA��hhǾ�r��a���}��iy�恬�y��*W��oϯ����}�����5�lq���T�Y֭��1d��{�M`8X�#e����E��̝,#>,D����(���Y�Lڟ�m���
u���y��M�UP\��d��&I���AVcg�Y��M���-B�1�ZTYE��F�]`ȝ��~/�=6�<_
M49������~f��s��R�m�x��2��G:����3����p�`ѳ�C�"����'�&���gɑdQ�wl����eG�'�mH�t� ��I���Bh�ʬ%0
�amRٵ����^�~ěg���b��C�/�Z #'�������������Wv�X1��gXe3Mo��ø3P�tv�;�!��1k��&r��gMW���_�<L�Tr���Hoˬݦa�pYt��V�Y��Vy'�� <�S��JRR6�j��"%˧W��F�4��A!7W0P�~��������p���a��!�q�@(��[��v��EGU�c���M�	,���:�
w}��1'í���$1�LeL� �d�$%�|ˬ��Ud�w}������ѫ��䪛�N�OL�:]�g�~�V�\�ˢ|7�����L�p�����P�+��Vc:�^w�7j��H�9<�ᡬ_3	0f_'}/�2�n9���d[zp��x9��gT�r��Ӥ�� s;$İ��Lc����o���]�C�����nOTD�Xr
9T��Q���g^����"��}=���CIl���DZ�ɨ�.�sxu�2�i��NJ��{��y�!���U)ۢ9�����.�!ű2���܃���\����+:�E���>�1��#���WHl�1�?Dc�-iMqz�9e����|�(�n�^p��U�8���2 ������j��-�)gb+p �V?�^��&b;:5���^u��}�-_�8mբt{���W�}N�8^V��dj��'�Q�7#��~��A;֎���9K�{�fus7�f���w&���Vm$����qn/ł��!�e��˃�>\QZ���(7+ȹ�J.x�Fh>LP
}P�&&������0�E�2�i����Il����i��}?�����2�Ѧ��NY])��\[�cP�g
;��(U<���:,/���>���B�c8�۱`��U��>5��BM���9
�G�)�47���#�H�St�V.��D��tWl��]ii���aJ�q��7E����I��k��¢��-��������pN��.�aU -y��6��a0𭩧L!ǫ���Bwƈ;�d���w��(!G�kΝ�D�@7�~^6�yc��и.ҭ�9�b�E^m�q����Na�����I��|�Q�@܋s�9� 4Z���i!CD�T@)�9��4�nN�0���y��*l~I�*�`��V�\����Ӈ�f.
R��J���\d�\��İ���_3.�-d{�����5��QE�Gh0Ȩ�����������6�'���=�k���f���Ij���3G�,Ge�Ʋ
���:�N�t&����9c��!�g��KzS�#�~�.S�~ɇ��VH��F�/�Ie2�t��Q��CK}� n�v������ ���!��{��0�^�w���>�Gt��g�>4v��v�J�Y�'��"�z����o<}���	⟽�5��'T���kY�w��"D���C�v���w�J�"���<�l
2X�:�M_ݝ�1sv��-��;;���<�e |"W\����ɨ"aZ�G�v�H h��לҟ�6�ub)�3u�z��a¶"�Ϥ]�xKܓ> v�%YK6�Vϛ��n�sf���P��%V0M����{o���,��U�h��"��H-X�� F���]���W���.׵h�4T��P9� 
j!���P&��+��/y�P%ǒl��?�c��˛%�7�����^�A�	�(�c�������HF=S�����P��K�!4ۘ���k����9.u�_�w֡���}��N��	��U�g� OA=V�x�W�v��C�ۗt��������0]�A���	��*�WYP����W�V�P�qը��ݪh`�2n������q2�(��Y�D��Q/�7c��%��ҳ��T�y���.;��7�r���l785���+��-���r�l{0�oxN3'uqC2�iP�9��J'�~G�5F��k'~�_��
B���U��/�{b��nw֜��s���yk����I��JK��2���"�vɋ�S��9�3sv`r��f�Ӯ�.�Y{.t���v�2/�9ǤA7�3+����2���u[�j�D�NUl��R6/�lGo�K:�ea��b����M=���L��C�FO��Tz�@`�����J�K��e�Pg�n�O�j�a��?$b�.�c,��>�m`^JL,f%Gs�n	J��	x����Cnd�HG���X�H�V@��U����3�,� <�cc7��c�%H��"���Ŝ1���4^��V'��b�ƚ8���{T;n�j���U=��S%u��&��!'f�z�t���.����6P]�B��܃�|:a�߃�L��>y���~&�{$�$�~=*��`�R�C��m��!�I�1�3h�u�鿭�W����$�V���� �N� ���&��VD8���׍(��|3X��N�Y�A��lG
�! v7RP���I?[
��w�'� ϰ�	 �6� �"c�p��{d��Cҟ��s�nn���*0oS�����7D�I��K;"jP��(_�1����bйp� D��S�~:���L�ѽ�~zޭ���6�E���9W��7s�n9�WƗ��?��<��)��:�1��/_�	l�kmJE+N������;a�&#���о?i�پ�/M�.��몎j�ְ�ikZ������8����آL�,곤,�곢L��������.��(����l���޿���w_-ڜ��NK��5�u�*=�} �1����ҡ�����N�c�+�y�'r��.k�FƯ�.�U2�]WcK���*sg�F@2)9���՜zg{k�N8��m�rn�`�ʝ���%�����	�:�>�!`2��>��Nn��@����O+9�A�qu�׃��8ß��2p^c,�QH��]�q��k ;����1�oDYETG�l Ո���z�/W������ ��qp��=�$�D�CJ ��ʼwx̃Ŕkߛ�/�$�`��`f�=h�p�/�L-T?��΀�S�~�!� �>����xR�Ł "J�̩VX?��Atω|]U�������M����g�*0ϊƪ�V/V��J�U���Á�}�@g��/�wD�Q���C��$86��u�����_��gI�=Tl��yp��h��lr���F��7�W����[���s��7Z�2����S���Հ��N�C�����*/��u�VeWYՋ�ؙbP�� �\5hm�k������ل]����tǉ[���'���0x0k уP��ٙ-:h����')x��������αµ>�@ �JB���7G�@�K` ��ʋ�7(��^��WI%-]@�D�@ ��-�5���ql�o�����F���>͑�3M����z*V�J�~���3�p}&~�1�AI�K��W�(c#�c$��9��G۠1�0��v3�z��N�]�[�F�l���l" �U5�4`���	ȂR5�F�aNpp9;���.AfIE֩�&
)"�����#�G�i���E��C�q5�����yw���H,4]���\ܒ��\�m��#� �׈s��^|?��p;��&N:���$ݸpG�#��cYg���a�=*Fv����.R��Q&6�~�[�$v�<4��&9`�D�5�cǚ�������c=�}��_ef�Rbg�{�����"�Y�k6M7g�Ŏ���o�v������7�,��DLJ��zg�dV�f;'��%���J�xqC!}�\�A��ve��T�Î�����ŋ&ᶋ;��x��� �gp�/��M���؉~�
��"؝ j���Aw�˳��5Z�web~J���T�׊��Q;���?����Y-���T*��n�q�����mm|QE0�����
ʞ�So����:�Y���p��h�Eh�㴯ԕ�;\�lg3����&�ܵ��f���u�0Eλ�����@X�lD�Jl��E�� NJ��R �������n6�6�E�@P���z}�+����$��8"XE��h�RJU�U����Ƶ�j�>e]X/��|��'�:�o�g�/2$E�T����J� H"P*�V����.q�^,h��)X�6�m���|%�~�ȱCL��l�Y�9w侊�mT�֕W-�W���gJ(~Wm>�wܨ#�i�ؕ��J?/�x��`��g%�"^�!��AZ��Ly��Vh�����S ⇗�5k��:PлCbZx��Br�DJ�͇�fy�.���yGP&�>%d�3KaE�W�Ym x塰(�[���"v�Q�0��Aӗ�����5�ٕ�Qe9f�OW��J��3�搃�J5�80Iw�dm�)ay2�$뒰J�]���R��a`���D�vf��x���/�TD}�	�Q���(�0�H�fvbu�Od9��-肋�Q��a��2+u�q�H�})�h��# G��G�x���1!�[�: �ry��v�2�f�$^�.����<�t�Ԁ��f�=-��N�� v��Ҭ�Ǫ�[�'�(�2��bc���Œbln'�޺0��7�:�}���~ȩ{�Np���La�{,xA�!X)�B=�q��O��9<��?Ǉ͹���8n�09Ļ�9��{�X�ڏ���i��r+������j��,+��l+��s�bl59<�
�'E䜖	-�IS�.�Q��qt�����Oal���퀜W�^N\�O����L[텧b1� ~�{���1�%�-�*	�c@ؖ�l:죜yRL�X*���lj}�\�:�J^�Tf��H��棵��_j�/�,��ѳ�^���=�`C��}��08):�a�9= ϔ��92��Է�V�%ȧ��?���*;'�,��<*���ճ�a��/�m�M^��Y���iVE�6�M�SgJ���Sp:�u���0���f�};�GN�T����<�߁0��vv�7����<�,�E�3Ơ��t�N�15���)���[�%,����۩]�!�vQ�4���X8��8����6(w�SN������"L2�I�` �{�}�Q��Rt�$7JE�X��֔�tq~@6�Jtr4[Jy-��.ˬ��w�oY���հ�<������E�j��rV/Ud^��!���Rk�hE��wL�g�-��q�מ�1O�o� R�|@4��O�n�V�>*m�O���ϫ��V�]��}qT#�O,�JT_@��	�������]�T���(��tU��${BP�,�7Dn��1�u3�<�ţl-�\��<q5L{��{FS�� 2��U�T<�Cwl��r���C[9�5莲`o�ɒ�D��(��>�b��0,k�dbŚC:��U�RW~��̒�Pѭ�yE��N+JfN��o\��.UPO�}����ls<k�h}�I��wj�eaڃݷ��:�^�l��w�|[ݎ�)�e������&,i�$r�(�����qlL����"�ρ;��N��q�p��FB���$�V K���C�H��ɦ�r���p]��m%��@A�rAHs9^��du�A��|1.t;����Z�H���z˛�"+.s 0��{wC���F
�dN�/K䵠�s�_�
U������l�!���z��P�z���{*��=�3,�j��Nw(5����Y�'gw��G��0�F�����	�L ��$�t]�q] C����2�$w��.cΩ��4�C�V` ��� ��A԰'8����n���ৢ�s�S�ǡ�X?l�� ���6ĩ{����<l�����0�B�!5�����
g@��
	L���ܨ���.��ZD�I'��&U�J.��Fs� d ��QF{p�{������	қ�*���
�aVR��Ig�_[\Ɩ2-@'�U�i&��~n\�3�����5�����a�!���%� �\�l��)�.��&��`m�����;��=p���c��\_H�ֆ���2]QvI�y��r;!�k	V/��&�`�9�R�[b\�N�M>�����A?�EV�6$:vx&�ȴ�5���V�!��0�%�޵�ԑ��p>�o���oH)x(D.(��/��D��/֊�Ri:��a�TǰD��htN;6����x2��GhBFLji���Q���^�*�2$a�u�x��l�����/�Pl�x_��=�F$\#債.�|�n���nV�<���Tސ�C���O�hj�E�ЦH���^|�kE����(v���ؒVw0�CÁ�T���4�āV�G�̫��8�ԏڔ&��mz��:��x�[�hɌY^��f����(�a�Ħ}���{�1@��L:�I�Q��<�oZ��F�hP��)z5���gh	�R�a0*V��O��I?Y�d���
����!<��;�H2��Z&�C� |8�2���I+�K�KP:V��'aΆB����İ���^ՎI���9��P�$�*Fg���8��ТkK��د����r�T����T�v�&�-6<S��n��M�~*L�5�`f#�)iϰ$l+H%MT��짲��^ٝ��X�8ԉ�E�y�h�\Z/m��
��M�A��K&8yF����s�X�) 1̊��sm�����S	�|#���2����u�e��]��*�N]>��0*8Ve�$w���-�"��kbg��JK������&o���)-�Z,�����G~���2�j� ,��>�왙7�0`��Z+�D��7f����
��:U]''Y�!��u����6��`�hq��z��ět@��+�X��� �aB�Sy�V>#r����R�7�n�=��ڽJ���reTg����>�{���>��ڠ#������f!Y[+�&�^AEX$@��;=GA�xQ0�], E;gx�Я�\ �g�􅺾lk�Y7�̀t�>�0���X�s0��X���X���=�(�?�����^����=L���@��JQ]1 �d�}�Y��+J��N��c;�a�ͭ����{��d]S+<2@��֕������#��1
�ǻ6�I��c*�
��ѵ'����틥����׳������O�F�A��LD��t����;��+��Y���v�ĉu��}����RL��MwZņ�x6��f�o����������MA�`���pN��T������z��k0�` �#��簷�-,`+/�j
�+ya����"�|ߴ���H^�y��BH�7�H�7�O��K`��+L�_]9~�$Q���:�Eg���b�S;K��z$<������J��ы�M�+�bG����O�fG����B6��e�&SW*�ŝ�F�F^���h��%PI�8X�O�������dl�)��Mq�m������M���BZ���C�]�E�Ŕ��S����G7Ŷ��J�d�x��Q�|	A�d6(�Xݿv0�|G�ڌ�~��	 !E��m��h��2�%�Vc�	�@�,�4Zʱ����ġ�}�����d�EBGh����<��K�2xRG��{�'Z�(���jJ} �Ր��,����u�Ɣ��y.�d���#���#J�k�WUx̹��9�o_>� Jt�n$���aE��P��6ͽ��8Z�h������k}��L�A����E�a��U��@����;�P��.�[���R,�i��s�>N�5����gC�����y��d�fЁ�� @�VxP������c]��p|��஁:x,�qK�c چc��l8�N�����g����7��fQw9�#%�A5��%�ӗc+[E���Pcl��LG���e�޳B!��Ǿ��Q�%IO�GWt&;{hO�N��Dk���E���Ә��Vr 5|,[�Q4��nS����v-U��ce��˳��6������a�
��]����bzі�����Ă@5gF��[�`S���):9���Ŧؔ��0_Q��V8�m�É�P�es[�l١��gS4��=�kbe9D�uؕ��Z�[-�0�җdb��ut�?����� �H�˭��mg�iҤ����@����9'��F�����t��t|:$_���;ݩ����P��7��p�e&B�$#�����3�ǟ.+K�ƺ�JM!��$x�(I�Ɍ0�]�آ6F�¦�y���d��SmP����o)�r�������# ta(�)�<(HYN��)�kȎc�<.���ơ�(la!��	<�_o���oͫft�i�~��Y(W-��]j�}��kb$��3R�eJڤ�e$ٿ!�=󚱄�)�2���27F�j;�Epw;���iYn3��!�g'��2\1A��1Y��-@��,C�/y��`��D�uY�'N���.7^����lU]m�;���MK*K��O�?�j����;2I�.����e�N�E��_��1��Ѕ\ T������Gg�S�k�*6^��9��������*�ļ*��9�~���Ix,�2Y�֨�!C�kK��P�.�/	r�c j�,�֔��
��Ep�����]��>RGy5S��z$�9*h�>��)��T/Z�#%��j��<.5l�5���}��iT���wz\]YKa5�+��F�zG�A�q?b��F���Ky|�ڶ[�ہD�����0�z�wܔ��0�����#�E(Ҏ��"����*�,�A��)�����(@Z°[NV�dP��= Y'������������ J��RuH�W�����P�Gh���k����U�=�'�'�$D��|����S�Hy���D[&�?�ӼU����a�H�5�{�.H1?f����ǰ�����fo��̙Yw��P�=��F�;YF-^�x��)���H��׶3�{NG��O�eDe4�{�qd�)����
�:O<aώ��ӫ���PZ��B8fl���|�֍�5�OqP�@��{+��b-W2���)������ �Q� �g*X̮�S�H��:du翤��<P�"#�Nە�xq]i�����$�������(��q%�E��0HC�mP�V}�s�Z���>P��y�v1*5=N��	n��\3��q�� �1:�ڤ7G�c��rh��i�����`�j, ����{2��hCn���TH��H9��z�e2��:�aV	#'g/H� {�@rD$�7��V.��J3���1��(Q��j`�X�:�X�7k�)�P`~�h���"�4jH��z��5�����.�0�0=�F8)f�I�C9��e����U�k	'i�z@%��/B�N�B. �ϼ��̆��W��7����7��a%L�W_Ǌ{���������m����6V���m�����6V�c��L�k�Z��n�c�W88�tJ�T��'iz��y9�;�r>�z�1��C
M�B)��hS- ˫gp���[E�n�C"�Q ��Q�A��K�ĵGn�a�H��E�T�jS�ͮiOzx|0py�����_$Ƶ�K��Wb__����U��U3��5���aaf�%�bx��9 �P9�ے2u@���}�H�G�#�CV����3��:��$��Z�U�a�*�W����&�J�!�P�5��"j��Ō��b�&$4�������Ld��7ua����N�w�Խ��E/彂Uֆm��B���>�h�#/�R۵���<p�.{�aMu��͋��ht��U�o)�����we}��mTC���Ar=�yi-�t's��P��|PW�����1�H��_�I|l��	�
�f9�$k:�-��%�`�Y�;ь=c��g�`a��%7�%��a��Ի�C�D���tvWS���q��Xq�Y�q�2�^L
���<^:��Cd��̊3C�U;�Z��/qgmɂ_�H�>m[�Jd��{ZG���4
�vc��#y��}4c}.�����m�m�������%��HY�P�F�\R߷J��{2��Rg����9�[ݎ�u]!@Yl@J���͂�+`�U|�#�qM����v� Y��R���j�G$k���Z5/�F(�v}� �eb����:�XN��#�]�P'ٽD�80�7�����v�v�+�o���\��.���q;&��7�����;A���$���
ԕ���K��@Ô��Q��<ԏ�:!L�NvS��1
�c1�+��Rq�xu�] �<G*�\b�D0�=H��-=�cL�_$m
�"�/��[��Q��C��@�C)�Sם�^�d'/�?x�eZ� �>3r�!%D;�#,�x�Q�z�� ����;v�PΑG3.x���	s���j�8���牥r7%���~O�Y��®H�i�z�.?�P��@h��.�V�Yac}iaz�I�2���+�V8��;U1�'�"xA���j�0��Ώ��!�";&B�(|+��˔J��y�Pޖ�ը�;b��T߾��utc�X'�]%Qݞ�=��~MHS5$lݏ�+�
S�<����H ����[�e�Q{�nu�X%є^쫍�*�u���ZuleȀ�S 6�-�%Uޔ��>l�:L���
�ق���җp9M]S� h%�I𤇅�x����8j�0���)�T�Q�p��[�ėm��u��'̈
 �|< }`�E�*U +�@���v%��\�.q��v�@�5�(�PXǕaw�.u�c�F���Ś%���>� fT���9��Ǻ*��@,�6���!n�5�}���x�[�f���M�CN�qu�"�7��	��ĦI)�1�YBoD:��"j@b��
?�Ss����@X{ೠ�1=zB�}�EWH��8>ln�� ��.&���@�]�,�0�ӂ�yۇ����-�`ʆҼ��!,��1�[���C�|����'?f�7�%����v1JMa�"K�ȃ�v,�>�-����n�O�~��FO
%��S����E�`��w��pd�i�����0��[�p����tW��Xn[�&R���$l���	s!��s��x+���u^�]���څ��ĨW0���'��C�hA6�f#DY,�=�Zt��񱝥^���{Qp��¬Z��F@h�P^:^\�gyR-�
���81�/'�0�Vx"OɃ�B�?W�n%���n��b���`������؀U� �x��El\H�Kηв(#�}����>��v�t�/��t| $̡�$+Y�H���vwT�n*Ws�F����gĜ2�*�S�Kg� TpB�#T�c"�-�%��4nO$��!S.1Q�I� �=B|��Qvg�E\V��>b��Oa�AP��"h��l�6��B�E��»�W��2C���L�I���xW�3��J8��4�t��8S?!�$a�o,��Ƽ�Xi��V
8(��X�s=�dQ�|���5�5<��2�
<���ygk�[�j��t���oz<�
�)A�Qm$O<VݣVq��`D\W�w�\���uT@��H>}?�o?��}�L��f9l�
`����%^ef����*�Am�r��T6v<g�����M�V jZ+eS������fW�N�7`&b�H!ŗO��HqF�J��G"������''7��5�P�ظ���	κ#l��=�\2�۱�7HVt�qm�s�����xjU�N/4OD���ix�&#S�"�̓�~����\�S	���V6�cC�W�aPk��=�k�I��T0�Ω�������t�0lPXFi#�h�QʃL�����q����@�����C���B�@i�i����'��ik�)Xe_��	��}��/[��a��2k&�R0�e[�H}h�\�$�F�lv%ˆ��* l2�/����I 	�ۚ��<m�+�/���-��(��]dM�l�ȷ+�4y����d�y�""�_���%B��(ǲ.���v�jL=�/Ȼ�;n\�}"�cIFE�#w���`a@��{�-)c���J��4�UTS *[�>�O aR����!y��F7&�B�w͎o<d�AF �*f[$��V����ey C�$Xnw
D	p��,���E����;�=���d1{�8u��������؉�r�Q�ڥ�
+	1�Ѕ�&�r�����!�$� �>�̿��h?��N�F�V�?Ov��C�[�"������>��_~?�K�1>� �|�(|�1!������Ah���	��V�&�zuz"�����n(��j�'�ƥ�������@�IO;���>Nh������F	�T�	t/bE���=�t���1�H�b(t�Mi�ʂOW)s������SU�H+���O�=�ћg6?D��y�mU��=}����S�A�r��v�n�u���=�V2Z����xa�(�1�t����X��.� Y�tj9��>�%�O��T~Sxx��6¶?�N��h������.	�XiSi�ڃ��Șڐ�IG)G�
�BRɔ�SK-֑��l+a�CN�w�zj��yk�9��.�O�����	{��?�u#�Ogf��4u6q'�Ţ�����3�P!��F�[$:Kr:J�����\t[xP+�[R���ve6����i�dM��:����?*��n�<XٹV���𮟓���`�9�`��c��C�9����/�J;���u5rN�^���Z���L�?'��/��{��=[�V�gcz��_��A¬緟��;������؂��S�clr*U}9���/���]���L"��5[2;���싄�/b�
!b�iA͒�����1p����
v�u����&����<���2��Y�d�1����Ǆ9K�#Ty;Kr5H�0<|��LT*����s�#�\Cc��U���VQSϙ|!n ag�]SϨA���[[J�D�<&f{hAHޕzk&���7�K���\�9��Hi��s���@**�z�Vs�5�13��a����� *M��n��W�O��6tO���g2)����!��!��F/�$9l�����y�+�@0����!�&W��sjm�Ⱥ5�d%AΑ���z�)�t2�!6[�۟�eb���!�3=�n:�&F������<̔c?�+L�qbs,��&��?NP�*���n���e\� ��cx�°杓�l^t��}�S�u��i��tT�7d�|ֳ7En ��ϒ���x\CǮ�  ��9�L�%�r�5�xt�.�A�>������$�Q�΄s�ޥ rC#�������� �Za𪧨!�|����X��*�*��k��T�z�@P���G(�� 6X����31uctTc�5���CO [�@*j�	$��6�/NU#ӹ/��o�5 �uC� ���v�x6elK܀+E��qτ��+$�4�L@#KfŮ�W���d7�I�@�k�dj��7hR��f^�A��� ��0�%��(;��\� L/|�ÇxF��A^�$�b>h��m(��ۂC)��S1*��t)H�T�$������픕W�U%�Wo�W�8>JЖ�$ג��c�rU�4��!��I�s���(��/<偻%o�(!��^i�4�KK�h�Q��}�����;"������W6xT��0<���Hu��#�Nt�����7�
����J�5���z��q��q�_��g��2c��<�#@�Z[y��g�,�nT��L&�0s�y���lB��C��<�|��݅������y�� )����B��=x�q�ʫ�E���9��½�|�~f)��v��>��t���2�͢	Z�q�.�cj�+�E��>Lr�fXė,�rҥ�4��*� E�Ci�H�����ꈃ�h�pF��t��.u�ʬ����6p���0�"d��Q�$$#�8�p����2!�9�W��ƌ�u��{Z�i^����G�i.�n7py~'�`}�b�1��|Uq��aw��2ݨ��Zp�o�,<���r
��r�t�Aif��t�>�ǝ�a�Q��wiD{�ѺJ�Z�?�3���n��\�2�確�x���"Iy-"6q��u��K���H�0�m����j~B��vB���[,�˱����n�Z;�1�b5�Bo�ƅ&$2 .�6��IgE�%o݇��[��y��M3���w	K2T�~����(h�N`7������i����~��x���3c?���(��%�nmH��>NDm�n#C�#d�N�K��0��6�����r� hd�>�xWC6���֟D%�G���~�Jv�Y����	�,��`[���EI�F��-7�5����P�E;mk.����4��bS-�-p&�QO1�Pi��fѵ�STQ���T��τ��Ƭ�&
�g�V�K�ؙ^��S�V?!|��h���H�g`�mC�Y��]�V�,�	���3ϟ��5'���m��@ C,b��o��l	��Йb1����g�hc��x�pJr�-�Ң��<-�(#��ȩ�JY�V���Ҩ�:�#:�I���U۩1���	ѐ��恒I�%�9�+�im�[��z�Z��R��jCY]����L��؃�}i0��{/	��C$��?MJ��X�B>�cOY��ϻV���x����@�B��pZ6h|���k�|q� ވ�^�d�n
+�f&"%�
�M���C�cA�z/��?&[Ӟ$~*ͤ�j9�2�3�8�(;�B����܌�Ϧ�!��'�]s�mzt�3!Ʋ�-Z4���mA�K����^����,Uũ�^ʫO�x��0iKS���m9_*nZy� �S��c@*��B-��&.�5J��R!���XEld'���=��3�J>�J /	��K�<IQ�.]"d���?�vI���D�^����@�{�4�R7�)�+��	�Y x������ �Q����U��P���pJE@��MR�<��B��p�|-��D�3]�/;:H��jn� Ss��5K��5ON:D.��� s�� j��E4V�
梄�������'�w2l���]N  $�|��S>��HN��Nw+�Vsxp��^ca��?�T ���|�Fo�^k2��xp����&��puN�%[]%�W��#��2��3*f"��XP���{���u�4FR�N�!��N;�������T�~�\^�j >���{��"�lv.�}B�samuMrA��F��gU��ǲ���xx��i��)n5mL��P���1V�˹�d�rIr!�Q�`���-����]�q)u�)����T`�o�*��|{�zM7�'դiͦ�������,��m���Q�l��Ɯ])��`/\��S])2��j4����8�&͂6��ԟ� y�Ố��q�<36� eVu�A��d����pP�Л��I[�} �q��k�l0�׿�l��VQ6>CT��nn%fC�a�>�	��F�ڌ�s�#�_��ǫ��OJ�`-�14�-\&E��4H�Ϊ���~dػO������._��tȠu1K8H��uQ�w���i4Y����]�����>�a��J`����t��=Ͱ�\�g/M�F�}"���'�!�a:��;2���M���YG-�nA�1�YȎ�3����x�ai�8�6�|�#�l���8 �Z�he���cz�`R���+��}�S	葀�5F���,�h�Y�8����0+)�@G:	�j�Ec�ܑ�"䇽#n-�d���A_{3v�O�8*����y�֛�k�K��K�����F祴��1\��Κμ��t� �\޹�A�_\�!:8�m�� �T��;�P {u��!�a�6���OT�^������-v�8��!����T�L�.S{�L��FG�
2�Fs4�\�1�i넼�z�|ȼ��&,5�EܩY ja��"�YXj��"3���cQ}����!�O��3�(�P-��7;8"�dC��ͩ�ʤ:���o�5b�/��殄�3��28�h�{HQq*�@�l$g�#Ş����)����Kj;uL��(P��Y��cA�*��u�1�.�M-�A���=�rt��gdъe_�d�F��w��`�Dpy��!��!�[]��Q��!�3|.���v��� qsS5R��.ؾ�Fx�t_Y[�_�iUq�����K�5�(���~��֞���!�U���5��&��WǶ#��2��K�����)m�#	͎����̯�r)7��O��/G���ͧ?/�����,�v=�C�d                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
public:

	// ------------------------------------
	// Shared Resource Methods
	// ------------------------------------

	/** Loads the specified resource into the provided buffer if large enough.
	* Returns the size in bytes of the buffer required to hold the specified resource. */
	virtual uint32_t LoadSharedResource( const char *pchResourceName, char *pchBuffer, uint32_t unBufferLen ) = 0;

	/** Provides the full path to the specified resource. Resource names can include named directories for
	* drivers and other things, and this resolves all of those and returns the actual physical path. 
	* pchResourceTypeDirectory is the subdirectory of resources to look in. */
	virtual uint32_t GetResourceFullPath( const char *pchResourceName, const char *pchResourceTypeDirectory, char *pchPathBuffer, uint32_t unBufferLen ) = 0;
};

static const char * const IVRResources_Version = "IVRResources_001";


}
// ivrdrivermanager.h
namespace vr
{

class IVRDriverManager
{
public:
	virtual uint32_t GetDriverCount() const = 0;

	/** Returns the length of the number of bytes necessary to hold this string including the trailing null. */
	virtual uint32_t GetDriverName( vr::DriverId_t nDriver, VR_OUT_STRING() char *pchValue, uint32_t unBufferSize ) = 0;
};

static const char * const IVRDriverManager_Version = "IVRDriverManager_001";

} // namespace vr


// End

#endif // _OPENVR_API


namespace vr
{
	/** Finds the active installation of the VR API and initializes it. The provided path must be absolute
	* or relative to the current working directory. These are the local install versions of the equivalent
	* functions in steamvr.h and will work without a local Steam install.
	*
	* This path is to the "root" of the VR API install. That's the directory with
	* the "drivers" directory and a platform (i.e. "win32") directory in it, not the directory with the DLL itself.
	*
	* pStartupInfo is reserved for future use.
	*/
	inline IVRSystem *VR_Init( EVRInitError *peError, EVRApplicationType eApplicationType, const char *pStartupInfo = nullptr );

	/** unloads vrclient.dll. Any interface pointers from the interface are
	* invalid after this point */
	inline void VR_Shutdown();

	/** Returns true if there is an HMD attached. This check is as lightweight as possible and
	* can be called outside of VR_Init/VR_Shutdown. It should be used when an application wants
	* to know if initializing VR is a possibility but isn't ready to take that step yet.
	*/
	VR_INTERFACE bool VR_CALLTYPE VR_IsHmdPresent();

	/** Returns true if the OpenVR runtime is installed. */
	VR_INTERFACE bool VR_CALLTYPE VR_IsRuntimeInstalled();

	/** Returns where the OpenVR runtime is installed. */
	VR_INTERFACE const char *VR_CALLTYPE VR_RuntimePath();

	/** Returns the name of the enum value for an EVRInitError. This function may be called outside of VR_Init()/VR_Shutdown(). */
	VR_INTERFACE const char *VR_CALLTYPE VR_GetVRInitErrorAsSymbol( EVRInitError error );

	/** Returns an English string for an EVRInitError. Applications should call VR_GetVRInitErrorAsSymbol instead and
	* use that as a key to look up their own localized error message. This function may be called outside of VR_Init()/VR_Shutdown(). */
	VR_INTERFACE const char *VR_CALLTYPE VR_GetVRInitErrorAsEnglishDescription( EVRInitError error );

	/** Returns the interface of the specified version. This method must be called after VR_Init. The
	* pointer returned is valid until VR_Shutdown is called.
	*/
	VR_INTERFACE void *VR_CALLTYPE VR_GetGenericInterface( const char *pchInterfaceVersion, EVRInitError *peError );

	/** Returns whether the interface of the specified version exists.
	*/
	VR_INTERFACE bool VR_CALLTYPE VR_IsInterfaceVersionValid( const char *pchInterfaceVersion );

	/** Returns a token that represents whether the VR interface handles need to be reloaded */
	VR_INTERFACE uint32_t VR_CALLTYPE VR_GetInitToken();

	// These typedefs allow old enum names from SDK 0.9.11 to be used in applications.
	// They will go away in the future.
	typedef EVRInitError HmdError;
	typedef EVREye Hmd_Eye;
	typedef EColorSpace ColorSpace;
	typedef ETrackingResult HmdTrackingResult;
	typedef ETrackedDeviceClass TrackedDeviceClass;
	typedef ETrackingUniverseOrigin TrackingUniverseOrigin;
	typedef ETrackedDeviceProperty TrackedDeviceProperty;
	typedef ETrackedPropertyError TrackedPropertyError;
	typedef EVRSubmitFlags VRSubmitFlags_t;
	typedef EVRState VRState_t;
	typedef ECollisionBoundsStyle CollisionBoundsStyle_t;
	typedef EVROverlayError VROverlayError;
	typedef EVRFirmwareError VRFirmwareError;
	typedef EVRCompositorError VRCompositorError;
	typedef EVRScreenshotError VRScreenshotsError;

	inline uint32_t &VRToken()
	{
		static uint32_t token;
		return token;
	}

	class COpenVRContext
	{
	public:
		COpenVRContext() { Clear(); }
		void Clear();

		inline void CheckClear()
		{
			if ( VRToken() != VR_GetInitToken() )
			{
				Clear();
				VRToken() = VR_GetInitToken();
			}
		}

		IVRSystem *VRSystem()
		{
			CheckClear();
			if ( m_pVRSystem == nullptr )
			{
				EVRInitError eError;
				m_pVRSystem = ( IVRSystem * )VR_GetGenericInterface( IVRSystem_Version, &eError );
			}
			return m_pVRSystem;
		}
		IVRChaperone *VRChaperone()
		{
			CheckClear();
			if ( m_pVRChaperone == nullptr )
			{
				EVRInitError eError;
				m_pVRChaperone = ( IVRChaperone * )VR_GetGenericInterface( IVRChaperone_Version, &eError );
			}
			return m_pVRChaperone;
		}

		IVRChaperoneSetup *VRChaperoneSetup()
		{
			CheckClear();
			if ( m_pVRChaperoneSetup == nullptr )
			{
				EVRInitError eError;
				m_pVRChaperoneSetup = ( IVRChaperoneSetup * )VR_GetGenericInterface( IVRChaperoneSetup_Version, &eError );
			}
			return m_pVRChaperoneSetup;
		}

		IVRCompositor *VRCompositor()
		{
			CheckClear();
			if ( m_pVRCompositor == nullptr )
			{
				EVRInitError eError;
				m_pVRCompositor = ( IVRCompositor * )VR_GetGenericInterface( IVRCompositor_Version, &eError );
			}
			return m_pVRCompositor;
		}

		IVROverlay *VROverlay()
		{
			CheckClear();
			if ( m_pVROverlay == nullptr )
			{
				EVRInitError eError;
				m_pVROverlay = ( IVROverlay * )VR_GetGenericInterface( IVROverlay_Version, &eError );
			}
			return m_pVROverlay;
		}

		IVRResources *VRResources()
		{
			CheckClear();
			if ( m_pVRResources == nullptr )
			{
				EVRInitError eError;
				m_pVRResources = (IVRResources *)VR_GetGenericInterface( IVRResources_Version, &eError );
			}
			return m_pVRResources;
		}

		IVRScreenshots *VRScreenshots()
		{
			CheckClear();
			if ( m_pVRScreenshots == nullptr )
			{
				EVRInitError eError;
				m_pVRScreenshots = ( IVRScreenshots * )VR_GetGenericInterface( IVRScreenshots_Version, &eError );
			}
			return m_pVRScreenshots;
		}

		IVRRenderModels *VRRenderModels()
		{
			CheckClear();
			if ( m_pVRRenderModels == nullptr )
			{
				EVRInitError eError;
				m_pVRRenderModels = ( IVRRenderModels * )VR_GetGenericInterface( IVRRenderModels_Version, &eError );
			}
			return m_pVRRenderModels;
		}

		IVRExtendedDisplay *VRExtendedDisplay()
		{
			CheckClear();
			if ( m_pVRExtendedDisplay == nullptr )
			{
				EVRInitError eError;
				m_pVRExtendedDisplay = ( IVRExtendedDisplay * )VR_GetGenericInterface( IVRExtendedDisplay_Version, &eError );
			}
			return m_pVRExtendedDisplay;
		}

		IVRSettings *VRSettings()
		{
			CheckClear();
			if ( m_pVRSettings == nullptr )
			{
				EVRInitError eError;
				m_pVRSettings = ( IVRSettings * )VR_GetGenericInterface( IVRSettings_Version, &eError );
			}
			return m_pVRSettings;
		}

		IVRApplications *VRApplications()
		{
			CheckClear();
			if ( m_pVRApplications == nullptr )
			{
				EVRInitError eError;
				m_pVRApplications = ( IVRApplications * )VR_GetGenericInterface( IVRApplications_Version, &eError );
			}
			return m_pVRApplications;
		}

		IVRTrackedCamera *VRTrackedCamera()
		{
			CheckClear();
			if ( m_pVRTrackedCamera == nullptr )
			{
				EVRInitError eError;
				m_pVRTrackedCamera = ( IVRTrackedCamera * )VR_GetGenericInterface( IVRTrackedCamera_Version, &eError );
			}
			return m_pVRTrackedCamera;
		}

		IVRDriverManager *VRDriverManager()
		{
			CheckClear();
			if ( !m_pVRDriverManager )
			{
				EVRInitError eError;
				m_pVRDriverManager = ( IVRDriverManager * )VR_GetGenericInterface( IVRDriverManager_Version, &eError );
			}
			return m_pVRDriverManager;
		}

	private:
		IVRSystem			*m_pVRSystem;
		IVRChaperone		*m_pVRChaperone;
		IVRChaperoneSetup	*m_pVRChaperoneSetup;
		IVRCompositor		*m_pVRCompositor;
		IVROverlay			*m_pVROverlay;
		IVRResources		*m_pVRResources;
		IVRRenderModels		*m_pVRRenderModels;
		IVRExtendedDisplay	*m_pVRExtendedDisplay;
		IVRSettings			*m_pVRSettings;
		IVRApplications		*m_pVRApplications;
		IVRTrackedCamera	*m_pVRTrackedCamera;
		IVRScreenshots		*m_pVRScreenshots;
		IVRDriverManager	*m_pVRDriverManager;
	};

	inline COpenVRContext &OpenVRInternal_ModuleContext()
	{
		static void *ctx[ sizeof( COpenVRContext ) / sizeof( void * ) ];
		return *( COpenVRContext * )ctx; // bypass zero-init constructor
	}

	inline IVRSystem *VR_CALLTYPE VRSystem() { return OpenVRInternal_ModuleContext().VRSystem(); }
	inline IVRChaperone *VR_CALLTYPE VRChaperone() { return OpenVRInternal_ModuleContext().VRChaperone(); }
	inline IVRChaperoneSetup *VR_CALLTYPE VRChaperoneSetup() { return OpenVRInternal_ModuleContext().VRChaperoneSetup(); }
	inline IVRCompositor *VR_CALLTYPE VRCompositor() { return OpenVRInternal_ModuleContext().VRCompositor(); }
	inline IVROverlay *VR_CALLTYPE VROverlay() { return OpenVRInternal_ModuleContext().VROverlay(); }
	inline IVRScreenshots *VR_CALLTYPE VRScreenshots() { return OpenVRInternal_ModuleContext().VRScreenshots(); }
	inline IVRRenderModels *VR_CALLTYPE VRRenderModels() { return OpenVRInternal_ModuleContext().VRRenderModels(); }
	inline IVRApplications *VR_CALLTYPE VRApplications() { return OpenVRInternal_ModuleContext().VRApplications(); }
	inline IVRSettings *VR_CALLTYPE VRSettings() { return OpenVRInternal_ModuleContext().VRSettings(); }
	inline IVRResources *VR_CALLTYPE VRResources() { return OpenVRInternal_ModuleContext().VRResources(); }
	inline IVRExtendedDisplay *VR_CALLTYPE VRExtendedDisplay() { return OpenVRInternal_ModuleContext().VRExtendedDisplay(); }
	inline IVRTrackedCamera *VR_CALLTYPE VRTrackedCamera() { return OpenVRInternal_ModuleContext().VRTrackedCamera(); }
	inline IVRDriverManager *VR_CALLTYPE VRDriverManager() { return OpenVRInternal_ModuleContext().VRDriverManager(); }

	inline void COpenVRContext::Clear()
	{
		m_pVRSystem = nullptr;
		m_pVRChaperone = nullptr;
		m_pVRChaperoneSetup = nullptr;
		m_pVRCompositor = nullptr;
		m_pVROverlay = nullptr;
		m_pVRRenderModels = nullptr;
		m_pVRExtendedDisplay = nullptr;
		m_pVRSettings = nullptr;
		m_pVRApplications = nullptr;
		m_pVRTrackedCamera = nullptr;
		m_pVRResources = nullptr;
		m_pVRScreenshots = nullptr;
		m_pVRDriverManager = nullptr;
	}
	
	VR_INTERFACE uint32_t VR_CALLTYPE VR_InitInternal2( EVRInitError *peError, EVRApplicationType eApplicationType, const char *pStartupInfo );
	VR_INTERFACE void VR_CALLTYPE VR_ShutdownInternal();

	/** Finds the active installation of vrclient.dll and initializes it */
	inline IVRSystem *VR_Init( EVRInitError *peError, EVRApplicationType eApplicationType, const char *pStartupInfo )
	{
		IVRSystem *pVRSystem = nullptr;

		EVRInitError eError;
		VRToken() = VR_InitInternal2( &eError, eApplicationType, pStartupInfo );
		COpenVRContext &ctx = OpenVRInternal_ModuleContext();
		ctx.Clear();

		if ( eError == VRInitError_None )
		{
			if ( VR_IsInterfaceVersionValid( IVRSystem_Version ) )
			{
				pVRSystem = VRSystem();
			}
			else
			{
				VR_ShutdownInternal();
				eError = VRInitError_Init_InterfaceNotFound;
			}
		}

		if ( peError )
			*peError = eError;
		return pVRSystem;
	}

	/** unloads vrclient.dll. Any interface pointers from the interface are
	* invalid after this point */
	inline void VR_Shutdown()
	{
		VR_ShutdownInternal();
	}
}
