
#ifndef PROYECTO_H_
#define PROYECTO_H_

#include "..\inc\sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'proyecto'.
*/

/*! Define dimension of the state configuration vector for orthogonal states. */
#define PROYECTO_MAX_ORTHOGONAL_STATES 8

/*! Define maximum number of time events that can be active at once */
#define PROYECTO_MAX_PARALLEL_TIME_EVENTS 12

/*! Define indices of states in the StateConfVector */
#define SCVI_PROYECTO_TECX_DEBOUNCE 0
#define SCVI_PROYECTO_TECX_NO_OPRIMIDO 0
#define SCVI_PROYECTO_TECX_OPRIMIDO 0
#define SCVI_PROYECTO_TECX_VALIDACION 0
#define SCVI_PROYECTO_TECLAS_ESPERA 1
#define SCVI_PROYECTO_MODO_GRUPO_MANUAL 2
#define SCVI_PROYECTO_MODO_GRUPO_AUTOMATICO 2
#define SCVI_PROYECTO_MODO_GRUPO_TRANSICION_MODOS 2
#define SCVI_PROYECTO_SERVICIO_RED_HAY_LUZ 3
#define SCVI_PROYECTO_SERVICIO_RED_ESPERA 3
#define SCVI_PROYECTO_SERVICIO_RED_VALIDACION 3
#define SCVI_PROYECTO_SERVICIO_RED_NO_HAY_LUZ 3
#define SCVI_PROYECTO_GRUPO_ELECTROGENO_GRUPO_APAGADO 4
#define SCVI_PROYECTO_GRUPO_ELECTROGENO_CHEQUEO_ENCENDIDO 4
#define SCVI_PROYECTO_GRUPO_ELECTROGENO_ARRANQUE_EXITO 4
#define SCVI_PROYECTO_GRUPO_ELECTROGENO_FALLA 4
#define SCVI_PROYECTO_GRUPO_ELECTROGENO_INICIO_ARRANQUE 4
#define SCVI_PROYECTO_GRUPO_ELECTROGENO_ESTABILIZACION_GRUPO 4
#define SCVI_PROYECTO_GRUPO_ELECTROGENO_APAGANDO_GRUPO 4
#define SCVI_PROYECTO_GRUPO_ELECTROGENO_ESPERA_GRUPO 4
#define SCVI_PROYECTO_GRUPO_ELECTROGENO_CHEQUEO_APAGADO 4
#define SCVI_PROYECTO_GRUPO_ELECTROGENO_FIN_ARRANQUE 4
#define SCVI_PROYECTO_DISPLAY_IDLE 5
#define SCVI_PROYECTO_DISPLAY_MOSTRAR_VALORES 5
#define SCVI_PROYECTO_CONMUTADOR_GRUPO_CONMUTADO 6
#define SCVI_PROYECTO_CONMUTADOR_RED_CONMUTADA 6
#define SCVI_PROYECTO_CONMUTADOR_SIN_CONMUTACION 6
#define SCVI_PROYECTO_CONMUTADOR_CONMUTACION_INICIAL 6
#define SCVI_PROYECTO_SENSOR_TEMP_IDLE 7
#define SCVI_PROYECTO_SENSOR_TEMP_LEYENDO_TEMP 7

/*! Enumeration of all states */ 
typedef enum
{
	Proyecto_last_state,
	Proyecto_TECX_DEBOUNCE,
	Proyecto_TECX_NO_OPRIMIDO,
	Proyecto_TECX_OPRIMIDO,
	Proyecto_TECX_VALIDACION,
	Proyecto_Teclas_ESPERA,
	Proyecto_Modo_Grupo_MANUAL,
	Proyecto_Modo_Grupo_AUTOMATICO,
	Proyecto_Modo_Grupo_TRANSICION_MODOS,
	Proyecto_Servicio_Red_HAY_LUZ,
	Proyecto_Servicio_Red_ESPERA,
	Proyecto_Servicio_Red_VALIDACION,
	Proyecto_Servicio_Red_NO_HAY_LUZ,
	Proyecto_Grupo_Electrogeno_GRUPO_APAGADO,
	Proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO,
	Proyecto_Grupo_Electrogeno_ARRANQUE_EXITO,
	Proyecto_Grupo_Electrogeno_FALLA,
	Proyecto_Grupo_Electrogeno_INICIO_ARRANQUE,
	Proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO,
	Proyecto_Grupo_Electrogeno_APAGANDO_GRUPO,
	Proyecto_Grupo_Electrogeno_ESPERA_GRUPO,
	Proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO,
	Proyecto_Grupo_Electrogeno_FIN_ARRANQUE,
	Proyecto_Display_IDLE,
	Proyecto_Display_MOSTRAR_VALORES,
	Proyecto_Conmutador_GRUPO_CONMUTADO,
	Proyecto_Conmutador_RED_CONMUTADA,
	Proyecto_Conmutador_SIN_CONMUTACION,
	Proyecto_Conmutador_CONMUTACION_INICIAL,
	Proyecto_Sensor_Temp_IDLE,
	Proyecto_Sensor_Temp_LEYENDO_TEMP
} ProyectoStates;

/*! Type definition of the data structure for the ProyectoIface interface scope. */
typedef struct
{
	sc_boolean evTECXNoOprimido_raised;
	sc_boolean evTECXOprimido_raised;
	sc_integer evTECXOprimido_value;
	sc_boolean InputRedFalse_raised;
	sc_boolean InputRedTrue_raised;
	sc_boolean showDisplay_raised;
	sc_boolean leerTemp_raised;
	sc_integer estadoLuz;
	sc_boolean isGrupoOn;
	sc_boolean isContactoOn;
	sc_integer modoGrupo;
	sc_boolean grupoExito;
	sc_boolean grupoFalla;
	sc_integer numDisplay;
	sc_integer conmutacionRed;
	sc_integer conmutacionGrupo;
	sc_real temperatura;
} ProyectoIface;


/* Declaration of constants for scope ProyectoIface. */
extern const sc_integer PROYECTO_PROYECTOIFACE_LEDG;
extern const sc_integer PROYECTO_PROYECTOIFACE_LEDB;
extern const sc_integer PROYECTO_PROYECTOIFACE_LED1;
extern const sc_integer PROYECTO_PROYECTOIFACE_LED2;
extern const sc_integer PROYECTO_PROYECTOIFACE_LED3;
extern const sc_boolean PROYECTO_PROYECTOIFACE_LED_ON;
extern const sc_boolean PROYECTO_PROYECTOIFACE_LED_OFF;
extern const sc_integer PROYECTO_PROYECTOIFACE_TEC1;
extern const sc_integer PROYECTO_PROYECTOIFACE_TEC2;
extern const sc_integer PROYECTO_PROYECTOIFACE_TEC3;
extern const sc_integer PROYECTO_PROYECTOIFACE_TEC4;
extern const sc_integer PROYECTO_PROYECTOIFACE_GPIO1;
extern const sc_integer PROYECTO_PROYECTOIFACE_GPIO2;
extern const sc_integer PROYECTO_PROYECTOIFACE_GPIO3;
extern const sc_integer PROYECTO_PROYECTOIFACE_GPIO5;
extern const sc_integer PROYECTO_PROYECTOIFACE_GPIO7;
extern const sc_integer PROYECTO_PROYECTOIFACE_MAX_ARR;
extern const sc_boolean PROYECTO_PROYECTOIFACE_OUT_ON;
extern const sc_boolean PROYECTO_PROYECTOIFACE_OUT_OFF;


/*! Type definition of the data structure for the ProyectoInternal interface scope. */
typedef struct
{
	sc_boolean siTECXOK_raised;
	sc_boolean siRedOFF_raised;
	sc_boolean siRedON_raised;
	sc_boolean switchModo_raised;
	sc_boolean arranqueGrupo_raised;
	sc_boolean apagadoGrupo_raised;
	sc_boolean conmutar_raised;
	sc_boolean conmutarAuto_raised;
	sc_integer viTecla;
	sc_integer intentoArranque;
} ProyectoInternal;



/*! Type definition of the data structure for the ProyectoTimeEvents interface scope. */
typedef struct
{
	sc_boolean proyecto_TECX_DEBOUNCE_tev0_raised;
	sc_boolean proyecto_Modo_Grupo_TRANSICION_MODOS_tev0_raised;
	sc_boolean proyecto_Modo_Grupo_TRANSICION_MODOS_tev1_raised;
	sc_boolean proyecto_Servicio_Red_ESPERA_tev0_raised;
	sc_boolean proyecto_Grupo_Electrogeno_GRUPO_APAGADO_tev0_raised;
	sc_boolean proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev0_raised;
	sc_boolean proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev1_raised;
	sc_boolean proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev2_raised;
	sc_boolean proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev3_raised;
	sc_boolean proyecto_Grupo_Electrogeno_INICIO_ARRANQUE_tev0_raised;
	sc_boolean proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tev0_raised;
	sc_boolean proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tev1_raised;
	sc_boolean proyecto_Grupo_Electrogeno_APAGANDO_GRUPO_tev0_raised;
	sc_boolean proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO_tev0_raised;
	sc_boolean proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO_tev1_raised;
	sc_boolean proyecto_Display_MOSTRAR_VALORES_tev0_raised;
	sc_boolean proyecto_Conmutador_SIN_CONMUTACION_tev0_raised;
	sc_boolean proyecto_Conmutador_SIN_CONMUTACION_tev1_raised;
	sc_boolean proyecto_Sensor_Temp_LEYENDO_TEMP_tev0_raised;
} ProyectoTimeEvents;




/*! 
 * Type definition of the data structure for the Proyecto state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	ProyectoStates stateConfVector[PROYECTO_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	ProyectoIface iface;
	ProyectoInternal internal;
	ProyectoTimeEvents timeEvents;
} Proyecto;



/*! Initializes the Proyecto state machine data structures. Must be called before first usage.*/
extern void proyecto_init(Proyecto* handle);

/*! Activates the state machine */
extern void proyecto_enter(Proyecto* handle);

/*! Deactivates the state machine */
extern void proyecto_exit(Proyecto* handle);

/*! Performs a 'run to completion' step. */
extern void proyecto_runCycle(Proyecto* handle);

/*! Raises a time event. */
extern void proyecto_raiseTimeEvent(Proyecto* handle, sc_eventid evid);

/*! Raises the in event 'evTECXNoOprimido' that is defined in the default interface scope. */ 
extern void proyectoIface_raise_evTECXNoOprimido(Proyecto* handle);

/*! Raises the in event 'evTECXOprimido' that is defined in the default interface scope. */ 
extern void proyectoIface_raise_evTECXOprimido(Proyecto* handle, sc_integer value);

/*! Raises the in event 'InputRedFalse' that is defined in the default interface scope. */ 
extern void proyectoIface_raise_inputRedFalse(Proyecto* handle);

/*! Raises the in event 'InputRedTrue' that is defined in the default interface scope. */ 
extern void proyectoIface_raise_inputRedTrue(Proyecto* handle);

/*! Raises the in event 'showDisplay' that is defined in the default interface scope. */ 
extern void proyectoIface_raise_showDisplay(Proyecto* handle);

/*! Raises the in event 'leerTemp' that is defined in the default interface scope. */ 
extern void proyectoIface_raise_leerTemp(Proyecto* handle);

/*! Gets the value of the variable 'estadoLuz' that is defined in the default interface scope. */ 
extern sc_integer proyectoIface_get_estadoLuz(const Proyecto* handle);
/*! Sets the value of the variable 'estadoLuz' that is defined in the default interface scope. */ 
extern void proyectoIface_set_estadoLuz(Proyecto* handle, sc_integer value);
/*! Gets the value of the variable 'isGrupoOn' that is defined in the default interface scope. */ 
extern sc_boolean proyectoIface_get_isGrupoOn(const Proyecto* handle);
/*! Sets the value of the variable 'isGrupoOn' that is defined in the default interface scope. */ 
extern void proyectoIface_set_isGrupoOn(Proyecto* handle, sc_boolean value);
/*! Gets the value of the variable 'isContactoOn' that is defined in the default interface scope. */ 
extern sc_boolean proyectoIface_get_isContactoOn(const Proyecto* handle);
/*! Sets the value of the variable 'isContactoOn' that is defined in the default interface scope. */ 
extern void proyectoIface_set_isContactoOn(Proyecto* handle, sc_boolean value);
/*! Gets the value of the variable 'modoGrupo' that is defined in the default interface scope. */ 
extern sc_integer proyectoIface_get_modoGrupo(const Proyecto* handle);
/*! Sets the value of the variable 'modoGrupo' that is defined in the default interface scope. */ 
extern void proyectoIface_set_modoGrupo(Proyecto* handle, sc_integer value);
/*! Gets the value of the variable 'grupoExito' that is defined in the default interface scope. */ 
extern sc_boolean proyectoIface_get_grupoExito(const Proyecto* handle);
/*! Sets the value of the variable 'grupoExito' that is defined in the default interface scope. */ 
extern void proyectoIface_set_grupoExito(Proyecto* handle, sc_boolean value);
/*! Gets the value of the variable 'grupoFalla' that is defined in the default interface scope. */ 
extern sc_boolean proyectoIface_get_grupoFalla(const Proyecto* handle);
/*! Sets the value of the variable 'grupoFalla' that is defined in the default interface scope. */ 
extern void proyectoIface_set_grupoFalla(Proyecto* handle, sc_boolean value);
/*! Gets the value of the variable 'numDisplay' that is defined in the default interface scope. */ 
extern sc_integer proyectoIface_get_numDisplay(const Proyecto* handle);
/*! Sets the value of the variable 'numDisplay' that is defined in the default interface scope. */ 
extern void proyectoIface_set_numDisplay(Proyecto* handle, sc_integer value);
/*! Gets the value of the variable 'conmutacionRed' that is defined in the default interface scope. */ 
extern sc_integer proyectoIface_get_conmutacionRed(const Proyecto* handle);
/*! Sets the value of the variable 'conmutacionRed' that is defined in the default interface scope. */ 
extern void proyectoIface_set_conmutacionRed(Proyecto* handle, sc_integer value);
/*! Gets the value of the variable 'conmutacionGrupo' that is defined in the default interface scope. */ 
extern sc_integer proyectoIface_get_conmutacionGrupo(const Proyecto* handle);
/*! Sets the value of the variable 'conmutacionGrupo' that is defined in the default interface scope. */ 
extern void proyectoIface_set_conmutacionGrupo(Proyecto* handle, sc_integer value);
/*! Gets the value of the variable 'temperatura' that is defined in the default interface scope. */ 
extern sc_real proyectoIface_get_temperatura(const Proyecto* handle);
/*! Sets the value of the variable 'temperatura' that is defined in the default interface scope. */ 
extern void proyectoIface_set_temperatura(Proyecto* handle, sc_real value);
/*! Gets the value of the variable 'LEDG' that is defined in the default interface scope. */ 
extern const sc_integer proyectoIface_get_lEDG(const Proyecto* handle);
/*! Gets the value of the variable 'LEDB' that is defined in the default interface scope. */ 
extern const sc_integer proyectoIface_get_lEDB(const Proyecto* handle);
/*! Gets the value of the variable 'LED1' that is defined in the default interface scope. */ 
extern const sc_integer proyectoIface_get_lED1(const Proyecto* handle);
/*! Gets the value of the variable 'LED2' that is defined in the default interface scope. */ 
extern const sc_integer proyectoIface_get_lED2(const Proyecto* handle);
/*! Gets the value of the variable 'LED3' that is defined in the default interface scope. */ 
extern const sc_integer proyectoIface_get_lED3(const Proyecto* handle);
/*! Gets the value of the variable 'LED_ON' that is defined in the default interface scope. */ 
extern const sc_boolean proyectoIface_get_lED_ON(const Proyecto* handle);
/*! Gets the value of the variable 'LED_OFF' that is defined in the default interface scope. */ 
extern const sc_boolean proyectoIface_get_lED_OFF(const Proyecto* handle);
/*! Gets the value of the variable 'TEC1' that is defined in the default interface scope. */ 
extern const sc_integer proyectoIface_get_tEC1(const Proyecto* handle);
/*! Gets the value of the variable 'TEC2' that is defined in the default interface scope. */ 
extern const sc_integer proyectoIface_get_tEC2(const Proyecto* handle);
/*! Gets the value of the variable 'TEC3' that is defined in the default interface scope. */ 
extern const sc_integer proyectoIface_get_tEC3(const Proyecto* handle);
/*! Gets the value of the variable 'TEC4' that is defined in the default interface scope. */ 
extern const sc_integer proyectoIface_get_tEC4(const Proyecto* handle);
/*! Gets the value of the variable 'GPIO1' that is defined in the default interface scope. */ 
extern const sc_integer proyectoIface_get_gPIO1(const Proyecto* handle);
/*! Gets the value of the variable 'GPIO2' that is defined in the default interface scope. */ 
extern const sc_integer proyectoIface_get_gPIO2(const Proyecto* handle);
/*! Gets the value of the variable 'GPIO3' that is defined in the default interface scope. */ 
extern const sc_integer proyectoIface_get_gPIO3(const Proyecto* handle);
/*! Gets the value of the variable 'GPIO5' that is defined in the default interface scope. */ 
extern const sc_integer proyectoIface_get_gPIO5(const Proyecto* handle);
/*! Gets the value of the variable 'GPIO7' that is defined in the default interface scope. */ 
extern const sc_integer proyectoIface_get_gPIO7(const Proyecto* handle);
/*! Gets the value of the variable 'MAX_ARR' that is defined in the default interface scope. */ 
extern const sc_integer proyectoIface_get_mAX_ARR(const Proyecto* handle);
/*! Gets the value of the variable 'OUT_ON' that is defined in the default interface scope. */ 
extern const sc_boolean proyectoIface_get_oUT_ON(const Proyecto* handle);
/*! Gets the value of the variable 'OUT_OFF' that is defined in the default interface scope. */ 
extern const sc_boolean proyectoIface_get_oUT_OFF(const Proyecto* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean proyecto_isActive(const Proyecto* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean proyecto_isFinal(const Proyecto* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean proyecto_isStateActive(const Proyecto* handle, ProyectoStates state);


#ifdef __cplusplus
}
#endif 

#endif /* PROYECTO_H_ */
