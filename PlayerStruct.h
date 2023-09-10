#pragma once

typedef void(*Il2CppMethodPointer)();

struct MethodInfo;

union Il2CppRGCTXData
{
	void* rgctxDataDummy;
	const MethodInfo* method;
	//const Il2CppType* type;
	//Il2CppClass* klass;
};

struct Il2CppClass_2
{
	//Il2CppClass** typeHierarchy;
	void* unity_user_data;
	/*uint32_t initializationExceptionGCHandle;
	uint32_t cctor_started;
	uint32_t cctor_finished;*/
	size_t cctor_thread;
	void* genericContainerHandle;
	/*uint32_t instance_size;
	uint32_t actualSize;
	uint32_t element_size;
	int32_t native_size;
	uint32_t static_fields_size;
	uint32_t thread_static_fields_size;
	int32_t thread_static_fields_offset;
	uint32_t flags;
	uint32_t token;
	uint16_t method_count;
	uint16_t property_count;
	uint16_t field_count;
	uint16_t event_count;
	uint16_t nested_type_count;
	uint16_t vtable_count;
	uint16_t interfaces_count;
	uint16_t interface_offsets_count;
	uint8_t typeHierarchyDepth;
	uint8_t genericRecursionDepth;
	uint8_t rank;
	uint8_t minimumAlignment;
	uint8_t naturalAligment;
	uint8_t packingSize;
	uint8_t bitflags1;
	uint8_t bitflags2;*/
};

struct Il2CppClass
{
	//Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	//VirtualInvokeData vtable[255];
};


struct Il2CppType
{
	void* data;
	unsigned int bits;
};

struct Il2CppRuntimeInterfaceOffsetPair
{
	Il2CppClass* interfaceType;
};

struct Il2CppClass_1
{
	void* image;
	void* gc_desc;
	const char* name;
	const char* namespaze;
	Il2CppType byval_arg;
	Il2CppType this_arg;
	Il2CppClass* element_class;
	Il2CppClass* castClass;
	Il2CppClass* declaringType;
	Il2CppClass* parent;
	void* generic_class;
	void* typeMetadataHandle;
	void* interopData;
	Il2CppClass* klass;
	void* fields;
	void* events;
	void* properties;
	void* methods;
	Il2CppClass** nestedTypes;
	Il2CppClass** implementedInterfaces;
	Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
};

struct __declspec(align(8)) UnityEngine_Object_Fields {
};

struct UnityEngine_Component_Fields : UnityEngine_Object_Fields {
};

struct UnityEngine_Behaviour_Fields : UnityEngine_Component_Fields {
};

struct UnityEngine_MonoBehaviour_Fields : UnityEngine_Behaviour_Fields {
	struct System_Threading_CancellationTokenSource_o* m_CancellationTokenSource;
};

struct Player_Fields : UnityEngine_MonoBehaviour_Fields {
	struct Photon_Pun_PhotonView_o* _________;
	bool _1__________;
	struct PlayerCharacter_o* _3__________;
	struct ClosetZone_o* _4__________;
	struct UnityEngine_GameObject_o* _5__________;
	struct UnityEngine_Transform_o* _6__________;
	struct System_Collections_Generic_List_KeyInfo__o* _7__________;
	struct UnityEngine_Camera_o* _8__________;
	struct LevelRoom_o* _9__________;
	struct UnityEngine_Transform_o* _10__________;
	struct PhotonObjectInteract_o* _11__________;
	struct PhotonObjectInteract_o* _12__________;
	struct UnityEngine_GameObject_array* _13__________;
	struct UnityEngine_GameObject_o* _14__________;
	struct HeadMountedSocket_o* _16__________;
	struct UnityEngine_Transform_o* _17__________;
	struct UnityEngine_Transform_o* _18__________;
	struct UnityEngine_GameObject_o* _19__________;
	struct DeadPlayer_o* _20__________;
	struct PlayerSanity_o* _21__________;
	struct PlayerStats_o* _22__________;
	struct FootstepController_o* _23__________;
	struct JournalController_o* _24__________;
	struct UnityEngine_Renderer_array* _25__________;
	bool _26__________;
	struct PlayerAudio_o* _27__________;
	struct PlayerGraphics_o* _28__________;
	struct PlayerStamina_o* _29__________;
	float _30__________;
	bool _31__________;
	struct UnityEngine_CharacterController_o* _32__________;
	struct UnityEngine_AudioListener_o* _33__________;
	struct FirstPersonController_o* _34__________;
	struct PCPropGrab_o* _35__________;
	struct DragRigidbodyUse_o* _36__________;
	struct PCCanvas_o* _37__________;
	struct PCCrouch_o* _38__________;
	struct PCMenu_o* _39__________;
	struct PCControls_o* _40__________;
	struct PCFlashlight_o* _41__________;
	struct UnityEngine_Animator_o* _42__________;
	struct UnityEngine_InputSystem_PlayerInput_o* _43__________;
	struct PCItemSway_o* _44__________;
	struct PCItemSway_o* _45__________;
	struct UnityEngine_Transform_o* _46__________;
	struct UnityEngine_XR_Interaction_Toolkit_XRBaseInteractor_o* _47__________;
	struct UnityEngine_XR_Interaction_Toolkit_XRBaseInteractor_o* _48__________;
	struct UnityEngine_Transform_o* _49__________;
	struct VRMovementSettings_o* _50__________;
	struct VRBelt_o* _51__________;
	struct UnityEngine_XR_Interaction_Toolkit_XRSocketInteractor_o* _52__________;
	struct UnityEngine_XR_Interaction_Toolkit_XRSocketInteractor_o* _53__________;
	struct TrailerCamera_o* _54__________;
	struct VRLoading_o* _55__________;
};

struct VirtualInvokeData
{
	Il2CppMethodPointer methodPtr;
	const MethodInfo* method;
};

struct Player_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};

struct Player_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Player_VTable vtable;
};


struct Player_o {
	Player_c* klass;
	void* monitor;
	Player_Fields fields;

	void RevivePlayer();
};