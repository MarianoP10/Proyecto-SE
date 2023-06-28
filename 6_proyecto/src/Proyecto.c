
#include "Proyecto.h"
#include "..\inc\sc_types.h"
#include "ProyectoRequired.h"

#include <stdlib.h>
#include <string.h>
/*! \file Implementation of the state machine 'proyecto'
*/

/* prototypes of all internal functions */
static sc_boolean check_TECX_DEBOUNCE_tr0_tr0(const Proyecto* handle);
static sc_boolean check_TECX_NO_OPRIMIDO_tr0_tr0(const Proyecto* handle);
static sc_boolean check_TECX_OPRIMIDO_tr0_tr0(const Proyecto* handle);
static sc_boolean check_TECX_VALIDACION_tr0_tr0(const Proyecto* handle);
static sc_boolean check_TECX_VALIDACION_tr1_tr1(const Proyecto* handle);
static sc_boolean check_Teclas_ESPERA_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Teclas_ESPERA_tr1_tr1(const Proyecto* handle);
static sc_boolean check_Teclas_ESPERA_tr2_tr2(const Proyecto* handle);
static sc_boolean check_Teclas_ESPERA_tr3_tr3(const Proyecto* handle);
static sc_boolean check_Modo_Grupo_MANUAL_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Modo_Grupo_AUTOMATICO_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Modo_Grupo_TRANSICION_MODOS_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Modo_Grupo_TRANSICION_MODOS_tr1_tr1(const Proyecto* handle);
static sc_boolean check_Servicio_Red_HAY_LUZ_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Servicio_Red_ESPERA_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Servicio_Red_VALIDACION_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Servicio_Red_VALIDACION_tr1_tr1(const Proyecto* handle);
static sc_boolean check_Servicio_Red_NO_HAY_LUZ_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_GRUPO_APAGADO_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr1_tr1(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr2_tr2(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr3_tr3(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_ARRANQUE_EXITO_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_ARRANQUE_EXITO_tr1_tr1(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_FALLA_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_FALLA_tr1_tr1(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_INICIO_ARRANQUE_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tr1_tr1(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_APAGANDO_GRUPO_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_ESPERA_GRUPO_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_ESPERA_GRUPO_tr1_tr1(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_CHEQUEO_APAGADO_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_CHEQUEO_APAGADO_tr1_tr1(const Proyecto* handle);
static sc_boolean check_Grupo_Electrogeno_FIN_ARRANQUE_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Display_IDLE_lr0_lr0(const Proyecto* handle);
static sc_boolean check_Display_IDLE_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Display_MOSTRAR_VALORES_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Conmutador_GRUPO_CONMUTADO_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Conmutador_GRUPO_CONMUTADO_tr1_tr1(const Proyecto* handle);
static sc_boolean check_Conmutador_RED_CONMUTADA_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Conmutador_RED_CONMUTADA_tr1_tr1(const Proyecto* handle);
static sc_boolean check_Conmutador_SIN_CONMUTACION_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Conmutador_SIN_CONMUTACION_tr1_tr1(const Proyecto* handle);
static sc_boolean check_Conmutador_CONMUTACION_INICIAL_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Sensor_Temp_IDLE_tr0_tr0(const Proyecto* handle);
static sc_boolean check_Sensor_Temp_LEYENDO_TEMP_tr0_tr0(const Proyecto* handle);
static void effect_TECX_DEBOUNCE_tr0(Proyecto* handle);
static void effect_TECX_NO_OPRIMIDO_tr0(Proyecto* handle);
static void effect_TECX_OPRIMIDO_tr0(Proyecto* handle);
static void effect_TECX_VALIDACION_tr0(Proyecto* handle);
static void effect_TECX_VALIDACION_tr1(Proyecto* handle);
static void effect_Teclas_ESPERA_tr0(Proyecto* handle);
static void effect_Teclas_ESPERA_tr1(Proyecto* handle);
static void effect_Teclas_ESPERA_tr2(Proyecto* handle);
static void effect_Teclas_ESPERA_tr3(Proyecto* handle);
static void effect_Modo_Grupo_MANUAL_tr0(Proyecto* handle);
static void effect_Modo_Grupo_AUTOMATICO_tr0(Proyecto* handle);
static void effect_Modo_Grupo_TRANSICION_MODOS_tr0(Proyecto* handle);
static void effect_Modo_Grupo_TRANSICION_MODOS_tr1(Proyecto* handle);
static void effect_Servicio_Red_HAY_LUZ_tr0(Proyecto* handle);
static void effect_Servicio_Red_ESPERA_tr0(Proyecto* handle);
static void effect_Servicio_Red_VALIDACION_tr0(Proyecto* handle);
static void effect_Servicio_Red_VALIDACION_tr1(Proyecto* handle);
static void effect_Servicio_Red_NO_HAY_LUZ_tr0(Proyecto* handle);
static void effect_Grupo_Electrogeno_GRUPO_APAGADO_tr0(Proyecto* handle);
static void effect_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr0(Proyecto* handle);
static void effect_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr1(Proyecto* handle);
static void effect_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr2(Proyecto* handle);
static void effect_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr3(Proyecto* handle);
static void effect_Grupo_Electrogeno_ARRANQUE_EXITO_tr0(Proyecto* handle);
static void effect_Grupo_Electrogeno_ARRANQUE_EXITO_tr1(Proyecto* handle);
static void effect_Grupo_Electrogeno_FALLA_tr0(Proyecto* handle);
static void effect_Grupo_Electrogeno_FALLA_tr1(Proyecto* handle);
static void effect_Grupo_Electrogeno_INICIO_ARRANQUE_tr0(Proyecto* handle);
static void effect_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tr0(Proyecto* handle);
static void effect_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tr1(Proyecto* handle);
static void effect_Grupo_Electrogeno_APAGANDO_GRUPO_tr0(Proyecto* handle);
static void effect_Grupo_Electrogeno_ESPERA_GRUPO_tr0(Proyecto* handle);
static void effect_Grupo_Electrogeno_ESPERA_GRUPO_tr1(Proyecto* handle);
static void effect_Grupo_Electrogeno_CHEQUEO_APAGADO_tr0(Proyecto* handle);
static void effect_Grupo_Electrogeno_CHEQUEO_APAGADO_tr1(Proyecto* handle);
static void effect_Grupo_Electrogeno_FIN_ARRANQUE_tr0(Proyecto* handle);
static void effect_Display_IDLE_lr0_lr0(Proyecto* handle);
static void effect_Display_IDLE_tr0(Proyecto* handle);
static void effect_Display_MOSTRAR_VALORES_tr0(Proyecto* handle);
static void effect_Conmutador_GRUPO_CONMUTADO_tr0(Proyecto* handle);
static void effect_Conmutador_GRUPO_CONMUTADO_tr1(Proyecto* handle);
static void effect_Conmutador_RED_CONMUTADA_tr0(Proyecto* handle);
static void effect_Conmutador_RED_CONMUTADA_tr1(Proyecto* handle);
static void effect_Conmutador_SIN_CONMUTACION_tr0(Proyecto* handle);
static void effect_Conmutador_SIN_CONMUTACION_tr1(Proyecto* handle);
static void effect_Conmutador_CONMUTACION_INICIAL_tr0(Proyecto* handle);
static void effect_Sensor_Temp_IDLE_tr0(Proyecto* handle);
static void effect_Sensor_Temp_LEYENDO_TEMP_tr0(Proyecto* handle);
static void enact_TECX_DEBOUNCE(Proyecto* handle);
static void enact_TECX_OPRIMIDO(Proyecto* handle);
static void enact_Modo_Grupo_MANUAL(Proyecto* handle);
static void enact_Modo_Grupo_AUTOMATICO(Proyecto* handle);
static void enact_Modo_Grupo_TRANSICION_MODOS(Proyecto* handle);
static void enact_Servicio_Red_HAY_LUZ(Proyecto* handle);
static void enact_Servicio_Red_ESPERA(Proyecto* handle);
static void enact_Servicio_Red_NO_HAY_LUZ(Proyecto* handle);
static void enact_Grupo_Electrogeno_GRUPO_APAGADO(Proyecto* handle);
static void enact_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(Proyecto* handle);
static void enact_Grupo_Electrogeno_ARRANQUE_EXITO(Proyecto* handle);
static void enact_Grupo_Electrogeno_FALLA(Proyecto* handle);
static void enact_Grupo_Electrogeno_INICIO_ARRANQUE(Proyecto* handle);
static void enact_Grupo_Electrogeno_ESTABILIZACION_GRUPO(Proyecto* handle);
static void enact_Grupo_Electrogeno_APAGANDO_GRUPO(Proyecto* handle);
static void enact_Grupo_Electrogeno_ESPERA_GRUPO(Proyecto* handle);
static void enact_Grupo_Electrogeno_CHEQUEO_APAGADO(Proyecto* handle);
static void enact_Grupo_Electrogeno_FIN_ARRANQUE(Proyecto* handle);
static void enact_Display_MOSTRAR_VALORES(Proyecto* handle);
static void enact_Conmutador_GRUPO_CONMUTADO(Proyecto* handle);
static void enact_Conmutador_RED_CONMUTADA(Proyecto* handle);
static void enact_Conmutador_SIN_CONMUTACION(Proyecto* handle);
static void enact_Conmutador_CONMUTACION_INICIAL(Proyecto* handle);
static void enact_Sensor_Temp_LEYENDO_TEMP(Proyecto* handle);
static void exact_TECX_DEBOUNCE(Proyecto* handle);
static void exact_Modo_Grupo_TRANSICION_MODOS(Proyecto* handle);
static void exact_Servicio_Red_ESPERA(Proyecto* handle);
static void exact_Grupo_Electrogeno_GRUPO_APAGADO(Proyecto* handle);
static void exact_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(Proyecto* handle);
static void exact_Grupo_Electrogeno_INICIO_ARRANQUE(Proyecto* handle);
static void exact_Grupo_Electrogeno_ESTABILIZACION_GRUPO(Proyecto* handle);
static void exact_Grupo_Electrogeno_APAGANDO_GRUPO(Proyecto* handle);
static void exact_Grupo_Electrogeno_CHEQUEO_APAGADO(Proyecto* handle);
static void exact_Display_MOSTRAR_VALORES(Proyecto* handle);
static void exact_Conmutador_SIN_CONMUTACION(Proyecto* handle);
static void exact_Sensor_Temp_LEYENDO_TEMP(Proyecto* handle);
static void enseq_TECX_DEBOUNCE_default(Proyecto* handle);
static void enseq_TECX_NO_OPRIMIDO_default(Proyecto* handle);
static void enseq_TECX_OPRIMIDO_default(Proyecto* handle);
static void enseq_TECX_VALIDACION_default(Proyecto* handle);
static void enseq_Teclas_ESPERA_default(Proyecto* handle);
static void enseq_Modo_Grupo_MANUAL_default(Proyecto* handle);
static void enseq_Modo_Grupo_AUTOMATICO_default(Proyecto* handle);
static void enseq_Modo_Grupo_TRANSICION_MODOS_default(Proyecto* handle);
static void enseq_Servicio_Red_HAY_LUZ_default(Proyecto* handle);
static void enseq_Servicio_Red_ESPERA_default(Proyecto* handle);
static void enseq_Servicio_Red_VALIDACION_default(Proyecto* handle);
static void enseq_Servicio_Red_NO_HAY_LUZ_default(Proyecto* handle);
static void enseq_Grupo_Electrogeno_GRUPO_APAGADO_default(Proyecto* handle);
static void enseq_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_default(Proyecto* handle);
static void enseq_Grupo_Electrogeno_ARRANQUE_EXITO_default(Proyecto* handle);
static void enseq_Grupo_Electrogeno_FALLA_default(Proyecto* handle);
static void enseq_Grupo_Electrogeno_INICIO_ARRANQUE_default(Proyecto* handle);
static void enseq_Grupo_Electrogeno_ESTABILIZACION_GRUPO_default(Proyecto* handle);
static void enseq_Grupo_Electrogeno_APAGANDO_GRUPO_default(Proyecto* handle);
static void enseq_Grupo_Electrogeno_ESPERA_GRUPO_default(Proyecto* handle);
static void enseq_Grupo_Electrogeno_CHEQUEO_APAGADO_default(Proyecto* handle);
static void enseq_Grupo_Electrogeno_FIN_ARRANQUE_default(Proyecto* handle);
static void enseq_Display_IDLE_default(Proyecto* handle);
static void enseq_Display_MOSTRAR_VALORES_default(Proyecto* handle);
static void enseq_Conmutador_GRUPO_CONMUTADO_default(Proyecto* handle);
static void enseq_Conmutador_RED_CONMUTADA_default(Proyecto* handle);
static void enseq_Conmutador_SIN_CONMUTACION_default(Proyecto* handle);
static void enseq_Conmutador_CONMUTACION_INICIAL_default(Proyecto* handle);
static void enseq_Sensor_Temp_IDLE_default(Proyecto* handle);
static void enseq_Sensor_Temp_LEYENDO_TEMP_default(Proyecto* handle);
static void enseq_TECX_default(Proyecto* handle);
static void enseq_Teclas_default(Proyecto* handle);
static void enseq_Modo_Grupo_default(Proyecto* handle);
static void enseq_Servicio_Red_default(Proyecto* handle);
static void enseq_Grupo_Electrogeno_default(Proyecto* handle);
static void enseq_Display_default(Proyecto* handle);
static void enseq_Conmutador_default(Proyecto* handle);
static void enseq_Sensor_Temp_default(Proyecto* handle);
static void exseq_TECX_DEBOUNCE(Proyecto* handle);
static void exseq_TECX_NO_OPRIMIDO(Proyecto* handle);
static void exseq_TECX_OPRIMIDO(Proyecto* handle);
static void exseq_TECX_VALIDACION(Proyecto* handle);
static void exseq_Teclas_ESPERA(Proyecto* handle);
static void exseq_Modo_Grupo_MANUAL(Proyecto* handle);
static void exseq_Modo_Grupo_AUTOMATICO(Proyecto* handle);
static void exseq_Modo_Grupo_TRANSICION_MODOS(Proyecto* handle);
static void exseq_Servicio_Red_HAY_LUZ(Proyecto* handle);
static void exseq_Servicio_Red_ESPERA(Proyecto* handle);
static void exseq_Servicio_Red_VALIDACION(Proyecto* handle);
static void exseq_Servicio_Red_NO_HAY_LUZ(Proyecto* handle);
static void exseq_Grupo_Electrogeno_GRUPO_APAGADO(Proyecto* handle);
static void exseq_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(Proyecto* handle);
static void exseq_Grupo_Electrogeno_ARRANQUE_EXITO(Proyecto* handle);
static void exseq_Grupo_Electrogeno_FALLA(Proyecto* handle);
static void exseq_Grupo_Electrogeno_INICIO_ARRANQUE(Proyecto* handle);
static void exseq_Grupo_Electrogeno_ESTABILIZACION_GRUPO(Proyecto* handle);
static void exseq_Grupo_Electrogeno_APAGANDO_GRUPO(Proyecto* handle);
static void exseq_Grupo_Electrogeno_ESPERA_GRUPO(Proyecto* handle);
static void exseq_Grupo_Electrogeno_CHEQUEO_APAGADO(Proyecto* handle);
static void exseq_Grupo_Electrogeno_FIN_ARRANQUE(Proyecto* handle);
static void exseq_Display_IDLE(Proyecto* handle);
static void exseq_Display_MOSTRAR_VALORES(Proyecto* handle);
static void exseq_Conmutador_GRUPO_CONMUTADO(Proyecto* handle);
static void exseq_Conmutador_RED_CONMUTADA(Proyecto* handle);
static void exseq_Conmutador_SIN_CONMUTACION(Proyecto* handle);
static void exseq_Conmutador_CONMUTACION_INICIAL(Proyecto* handle);
static void exseq_Sensor_Temp_IDLE(Proyecto* handle);
static void exseq_Sensor_Temp_LEYENDO_TEMP(Proyecto* handle);
static void exseq_TECX(Proyecto* handle);
static void exseq_Teclas(Proyecto* handle);
static void exseq_Modo_Grupo(Proyecto* handle);
static void exseq_Servicio_Red(Proyecto* handle);
static void exseq_Grupo_Electrogeno(Proyecto* handle);
static void exseq_Display(Proyecto* handle);
static void exseq_Conmutador(Proyecto* handle);
static void exseq_Sensor_Temp(Proyecto* handle);
static void react_TECX_DEBOUNCE(Proyecto* handle);
static void react_TECX_NO_OPRIMIDO(Proyecto* handle);
static void react_TECX_OPRIMIDO(Proyecto* handle);
static void react_TECX_VALIDACION(Proyecto* handle);
static void react_Teclas_ESPERA(Proyecto* handle);
static void react_Modo_Grupo_MANUAL(Proyecto* handle);
static void react_Modo_Grupo_AUTOMATICO(Proyecto* handle);
static void react_Modo_Grupo_TRANSICION_MODOS(Proyecto* handle);
static void react_Servicio_Red_HAY_LUZ(Proyecto* handle);
static void react_Servicio_Red_ESPERA(Proyecto* handle);
static void react_Servicio_Red_VALIDACION(Proyecto* handle);
static void react_Servicio_Red_NO_HAY_LUZ(Proyecto* handle);
static void react_Grupo_Electrogeno_GRUPO_APAGADO(Proyecto* handle);
static void react_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(Proyecto* handle);
static void react_Grupo_Electrogeno_ARRANQUE_EXITO(Proyecto* handle);
static void react_Grupo_Electrogeno_FALLA(Proyecto* handle);
static void react_Grupo_Electrogeno_INICIO_ARRANQUE(Proyecto* handle);
static void react_Grupo_Electrogeno_ESTABILIZACION_GRUPO(Proyecto* handle);
static void react_Grupo_Electrogeno_APAGANDO_GRUPO(Proyecto* handle);
static void react_Grupo_Electrogeno_ESPERA_GRUPO(Proyecto* handle);
static void react_Grupo_Electrogeno_CHEQUEO_APAGADO(Proyecto* handle);
static void react_Grupo_Electrogeno_FIN_ARRANQUE(Proyecto* handle);
static void react_Display_IDLE(Proyecto* handle);
static void react_Display_MOSTRAR_VALORES(Proyecto* handle);
static void react_Conmutador_GRUPO_CONMUTADO(Proyecto* handle);
static void react_Conmutador_RED_CONMUTADA(Proyecto* handle);
static void react_Conmutador_SIN_CONMUTACION(Proyecto* handle);
static void react_Conmutador_CONMUTACION_INICIAL(Proyecto* handle);
static void react_Sensor_Temp_IDLE(Proyecto* handle);
static void react_Sensor_Temp_LEYENDO_TEMP(Proyecto* handle);
static void react_TECX__entry_Default(Proyecto* handle);
static void react_Teclas__entry_Default(Proyecto* handle);
static void react_Modo_Grupo__entry_Default(Proyecto* handle);
static void react_Servicio_Red__entry_Default(Proyecto* handle);
static void react_Grupo_Electrogeno__entry_Default(Proyecto* handle);
static void react_Display__entry_Default(Proyecto* handle);
static void react_Conmutador__entry_Default(Proyecto* handle);
static void react_Sensor_Temp__entry_Default(Proyecto* handle);
static void clearInEvents(Proyecto* handle);
static void clearOutEvents(Proyecto* handle);

const sc_integer PROYECTO_PROYECTOIFACE_LEDG = 1;
const sc_integer PROYECTO_PROYECTOIFACE_LEDB = 2;
const sc_integer PROYECTO_PROYECTOIFACE_LED1 = 3;
const sc_integer PROYECTO_PROYECTOIFACE_LED2 = 4;
const sc_integer PROYECTO_PROYECTOIFACE_LED3 = 5;
const sc_boolean PROYECTO_PROYECTOIFACE_LED_ON = bool_true;
const sc_boolean PROYECTO_PROYECTOIFACE_LED_OFF = bool_false;
const sc_integer PROYECTO_PROYECTOIFACE_TEC1 = 1 << 0;
const sc_integer PROYECTO_PROYECTOIFACE_TEC2 = 1 << 1;
const sc_integer PROYECTO_PROYECTOIFACE_TEC3 = 1 << 2;
const sc_integer PROYECTO_PROYECTOIFACE_TEC4 = 1 << 3;
const sc_integer PROYECTO_PROYECTOIFACE_GPIO1 = 15;
const sc_integer PROYECTO_PROYECTOIFACE_GPIO2 = 31;
const sc_integer PROYECTO_PROYECTOIFACE_GPIO3 = 14;
const sc_integer PROYECTO_PROYECTOIFACE_GPIO5 = 13;
const sc_integer PROYECTO_PROYECTOIFACE_GPIO7 = 12;
const sc_integer PROYECTO_PROYECTOIFACE_MAX_ARR = 3;
const sc_boolean PROYECTO_PROYECTOIFACE_OUT_ON = bool_true;
const sc_boolean PROYECTO_PROYECTOIFACE_OUT_OFF = bool_false;

void proyecto_init(Proyecto* handle)
{
		sc_integer i;
	
		for (i = 0; i < PROYECTO_MAX_ORTHOGONAL_STATES; ++i)
		{
			handle->stateConfVector[i] = Proyecto_last_state;
		}
		
		
		handle->stateConfVectorPosition = 0;
	
		clearInEvents(handle);
		clearOutEvents(handle);
	
		/* Default init sequence for statechart proyecto */
		handle->iface.estadoLuz = 0;
		handle->iface.isGrupoOn = bool_false;
		handle->iface.isContactoOn = bool_false;
		handle->iface.modoGrupo = 1;
		handle->iface.grupoExito = bool_false;
		handle->iface.grupoFalla = bool_false;
		handle->iface.numDisplay = 0;
		handle->iface.conmutacionRed = 0;
		handle->iface.conmutacionGrupo = 0;
		handle->iface.temperatura = 0.0;
		handle->internal.viTecla = 0;
		handle->internal.intentoArranque = 0;
}

void proyecto_enter(Proyecto* handle)
{
	/* Default enter sequence for statechart proyecto */
	enseq_TECX_default(handle);
	enseq_Teclas_default(handle);
	enseq_Modo_Grupo_default(handle);
	enseq_Servicio_Red_default(handle);
	enseq_Grupo_Electrogeno_default(handle);
	enseq_Display_default(handle);
	enseq_Conmutador_default(handle);
	enseq_Sensor_Temp_default(handle);
}

void proyecto_runCycle(Proyecto* handle)
{
	clearOutEvents(handle);
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < PROYECTO_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Proyecto_TECX_DEBOUNCE:
		{
			react_TECX_DEBOUNCE(handle);
			break;
		}
		case Proyecto_TECX_NO_OPRIMIDO:
		{
			react_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Proyecto_TECX_OPRIMIDO:
		{
			react_TECX_OPRIMIDO(handle);
			break;
		}
		case Proyecto_TECX_VALIDACION:
		{
			react_TECX_VALIDACION(handle);
			break;
		}
		case Proyecto_Teclas_ESPERA:
		{
			react_Teclas_ESPERA(handle);
			break;
		}
		case Proyecto_Modo_Grupo_MANUAL:
		{
			react_Modo_Grupo_MANUAL(handle);
			break;
		}
		case Proyecto_Modo_Grupo_AUTOMATICO:
		{
			react_Modo_Grupo_AUTOMATICO(handle);
			break;
		}
		case Proyecto_Modo_Grupo_TRANSICION_MODOS:
		{
			react_Modo_Grupo_TRANSICION_MODOS(handle);
			break;
		}
		case Proyecto_Servicio_Red_HAY_LUZ:
		{
			react_Servicio_Red_HAY_LUZ(handle);
			break;
		}
		case Proyecto_Servicio_Red_ESPERA:
		{
			react_Servicio_Red_ESPERA(handle);
			break;
		}
		case Proyecto_Servicio_Red_VALIDACION:
		{
			react_Servicio_Red_VALIDACION(handle);
			break;
		}
		case Proyecto_Servicio_Red_NO_HAY_LUZ:
		{
			react_Servicio_Red_NO_HAY_LUZ(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_GRUPO_APAGADO:
		{
			react_Grupo_Electrogeno_GRUPO_APAGADO(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO:
		{
			react_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_ARRANQUE_EXITO:
		{
			react_Grupo_Electrogeno_ARRANQUE_EXITO(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_FALLA:
		{
			react_Grupo_Electrogeno_FALLA(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_INICIO_ARRANQUE:
		{
			react_Grupo_Electrogeno_INICIO_ARRANQUE(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO:
		{
			react_Grupo_Electrogeno_ESTABILIZACION_GRUPO(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_APAGANDO_GRUPO:
		{
			react_Grupo_Electrogeno_APAGANDO_GRUPO(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_ESPERA_GRUPO:
		{
			react_Grupo_Electrogeno_ESPERA_GRUPO(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO:
		{
			react_Grupo_Electrogeno_CHEQUEO_APAGADO(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_FIN_ARRANQUE:
		{
			react_Grupo_Electrogeno_FIN_ARRANQUE(handle);
			break;
		}
		case Proyecto_Display_IDLE:
		{
			react_Display_IDLE(handle);
			break;
		}
		case Proyecto_Display_MOSTRAR_VALORES:
		{
			react_Display_MOSTRAR_VALORES(handle);
			break;
		}
		case Proyecto_Conmutador_GRUPO_CONMUTADO:
		{
			react_Conmutador_GRUPO_CONMUTADO(handle);
			break;
		}
		case Proyecto_Conmutador_RED_CONMUTADA:
		{
			react_Conmutador_RED_CONMUTADA(handle);
			break;
		}
		case Proyecto_Conmutador_SIN_CONMUTACION:
		{
			react_Conmutador_SIN_CONMUTACION(handle);
			break;
		}
		case Proyecto_Conmutador_CONMUTACION_INICIAL:
		{
			react_Conmutador_CONMUTACION_INICIAL(handle);
			break;
		}
		case Proyecto_Sensor_Temp_IDLE:
		{
			react_Sensor_Temp_IDLE(handle);
			break;
		}
		case Proyecto_Sensor_Temp_LEYENDO_TEMP:
		{
			react_Sensor_Temp_LEYENDO_TEMP(handle);
			break;
		}
		default:
			break;
		}
	}
	
	clearInEvents(handle);
}

void proyecto_exit(Proyecto* handle)
{
	/* Default exit sequence for statechart proyecto */
	exseq_TECX(handle);
	exseq_Teclas(handle);
	exseq_Modo_Grupo(handle);
	exseq_Servicio_Red(handle);
	exseq_Grupo_Electrogeno(handle);
	exseq_Display(handle);
	exseq_Conmutador(handle);
	exseq_Sensor_Temp(handle);
}

sc_boolean proyecto_isActive(const Proyecto* handle)
{
	sc_boolean result = bool_false;
	int i;
	
	for(i = 0; i < PROYECTO_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != Proyecto_last_state;
	}
	
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean proyecto_isFinal(const Proyecto* handle)
{
   return bool_false;
}

void proyecto_raiseTimeEvent(Proyecto* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(ProyectoTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean proyecto_isStateActive(const Proyecto* handle, ProyectoStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Proyecto_TECX_DEBOUNCE :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_TECX_DEBOUNCE] == Proyecto_TECX_DEBOUNCE
			);
			break;
		case Proyecto_TECX_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_TECX_NO_OPRIMIDO] == Proyecto_TECX_NO_OPRIMIDO
			);
			break;
		case Proyecto_TECX_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_TECX_OPRIMIDO] == Proyecto_TECX_OPRIMIDO
			);
			break;
		case Proyecto_TECX_VALIDACION :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_TECX_VALIDACION] == Proyecto_TECX_VALIDACION
			);
			break;
		case Proyecto_Teclas_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_TECLAS_ESPERA] == Proyecto_Teclas_ESPERA
			);
			break;
		case Proyecto_Modo_Grupo_MANUAL :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_MODO_GRUPO_MANUAL] == Proyecto_Modo_Grupo_MANUAL
			);
			break;
		case Proyecto_Modo_Grupo_AUTOMATICO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_MODO_GRUPO_AUTOMATICO] == Proyecto_Modo_Grupo_AUTOMATICO
			);
			break;
		case Proyecto_Modo_Grupo_TRANSICION_MODOS :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_MODO_GRUPO_TRANSICION_MODOS] == Proyecto_Modo_Grupo_TRANSICION_MODOS
			);
			break;
		case Proyecto_Servicio_Red_HAY_LUZ :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_SERVICIO_RED_HAY_LUZ] == Proyecto_Servicio_Red_HAY_LUZ
			);
			break;
		case Proyecto_Servicio_Red_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_SERVICIO_RED_ESPERA] == Proyecto_Servicio_Red_ESPERA
			);
			break;
		case Proyecto_Servicio_Red_VALIDACION :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_SERVICIO_RED_VALIDACION] == Proyecto_Servicio_Red_VALIDACION
			);
			break;
		case Proyecto_Servicio_Red_NO_HAY_LUZ :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_SERVICIO_RED_NO_HAY_LUZ] == Proyecto_Servicio_Red_NO_HAY_LUZ
			);
			break;
		case Proyecto_Grupo_Electrogeno_GRUPO_APAGADO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_GRUPO_ELECTROGENO_GRUPO_APAGADO] == Proyecto_Grupo_Electrogeno_GRUPO_APAGADO
			);
			break;
		case Proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_GRUPO_ELECTROGENO_CHEQUEO_ENCENDIDO] == Proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO
			);
			break;
		case Proyecto_Grupo_Electrogeno_ARRANQUE_EXITO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_GRUPO_ELECTROGENO_ARRANQUE_EXITO] == Proyecto_Grupo_Electrogeno_ARRANQUE_EXITO
			);
			break;
		case Proyecto_Grupo_Electrogeno_FALLA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_GRUPO_ELECTROGENO_FALLA] == Proyecto_Grupo_Electrogeno_FALLA
			);
			break;
		case Proyecto_Grupo_Electrogeno_INICIO_ARRANQUE :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_GRUPO_ELECTROGENO_INICIO_ARRANQUE] == Proyecto_Grupo_Electrogeno_INICIO_ARRANQUE
			);
			break;
		case Proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_GRUPO_ELECTROGENO_ESTABILIZACION_GRUPO] == Proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO
			);
			break;
		case Proyecto_Grupo_Electrogeno_APAGANDO_GRUPO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_GRUPO_ELECTROGENO_APAGANDO_GRUPO] == Proyecto_Grupo_Electrogeno_APAGANDO_GRUPO
			);
			break;
		case Proyecto_Grupo_Electrogeno_ESPERA_GRUPO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_GRUPO_ELECTROGENO_ESPERA_GRUPO] == Proyecto_Grupo_Electrogeno_ESPERA_GRUPO
			);
			break;
		case Proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_GRUPO_ELECTROGENO_CHEQUEO_APAGADO] == Proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO
			);
			break;
		case Proyecto_Grupo_Electrogeno_FIN_ARRANQUE :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_GRUPO_ELECTROGENO_FIN_ARRANQUE] == Proyecto_Grupo_Electrogeno_FIN_ARRANQUE
			);
			break;
		case Proyecto_Display_IDLE :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_DISPLAY_IDLE] == Proyecto_Display_IDLE
			);
			break;
		case Proyecto_Display_MOSTRAR_VALORES :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_DISPLAY_MOSTRAR_VALORES] == Proyecto_Display_MOSTRAR_VALORES
			);
			break;
		case Proyecto_Conmutador_GRUPO_CONMUTADO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_CONMUTADOR_GRUPO_CONMUTADO] == Proyecto_Conmutador_GRUPO_CONMUTADO
			);
			break;
		case Proyecto_Conmutador_RED_CONMUTADA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_CONMUTADOR_RED_CONMUTADA] == Proyecto_Conmutador_RED_CONMUTADA
			);
			break;
		case Proyecto_Conmutador_SIN_CONMUTACION :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_CONMUTADOR_SIN_CONMUTACION] == Proyecto_Conmutador_SIN_CONMUTACION
			);
			break;
		case Proyecto_Conmutador_CONMUTACION_INICIAL :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_CONMUTADOR_CONMUTACION_INICIAL] == Proyecto_Conmutador_CONMUTACION_INICIAL
			);
			break;
		case Proyecto_Sensor_Temp_IDLE :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_SENSOR_TEMP_IDLE] == Proyecto_Sensor_Temp_IDLE
			);
			break;
		case Proyecto_Sensor_Temp_LEYENDO_TEMP :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PROYECTO_SENSOR_TEMP_LEYENDO_TEMP] == Proyecto_Sensor_Temp_LEYENDO_TEMP
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

static void clearInEvents(Proyecto* handle)
{
	handle->iface.evTECXNoOprimido_raised = bool_false;
	handle->iface.evTECXOprimido_raised = bool_false;
	handle->iface.InputRedFalse_raised = bool_false;
	handle->iface.InputRedTrue_raised = bool_false;
	handle->iface.showDisplay_raised = bool_false;
	handle->iface.leerTemp_raised = bool_false;
	handle->internal.siTECXOK_raised = bool_false;
	handle->internal.siRedOFF_raised = bool_false;
	handle->internal.siRedON_raised = bool_false;
	handle->internal.switchModo_raised = bool_false;
	handle->internal.arranqueGrupo_raised = bool_false;
	handle->internal.apagadoGrupo_raised = bool_false;
	handle->internal.conmutar_raised = bool_false;
	handle->internal.conmutarAuto_raised = bool_false;
	handle->timeEvents.proyecto_TECX_DEBOUNCE_tev0_raised = bool_false;
	handle->timeEvents.proyecto_Modo_Grupo_TRANSICION_MODOS_tev0_raised = bool_false;
	handle->timeEvents.proyecto_Modo_Grupo_TRANSICION_MODOS_tev1_raised = bool_false;
	handle->timeEvents.proyecto_Servicio_Red_ESPERA_tev0_raised = bool_false;
	handle->timeEvents.proyecto_Grupo_Electrogeno_GRUPO_APAGADO_tev0_raised = bool_false;
	handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev0_raised = bool_false;
	handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev1_raised = bool_false;
	handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev2_raised = bool_false;
	handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev3_raised = bool_false;
	handle->timeEvents.proyecto_Grupo_Electrogeno_INICIO_ARRANQUE_tev0_raised = bool_false;
	handle->timeEvents.proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tev0_raised = bool_false;
	handle->timeEvents.proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tev1_raised = bool_false;
	handle->timeEvents.proyecto_Grupo_Electrogeno_APAGANDO_GRUPO_tev0_raised = bool_false;
	handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO_tev0_raised = bool_false;
	handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO_tev1_raised = bool_false;
	handle->timeEvents.proyecto_Display_MOSTRAR_VALORES_tev0_raised = bool_false;
	handle->timeEvents.proyecto_Conmutador_SIN_CONMUTACION_tev0_raised = bool_false;
	handle->timeEvents.proyecto_Conmutador_SIN_CONMUTACION_tev1_raised = bool_false;
	handle->timeEvents.proyecto_Sensor_Temp_LEYENDO_TEMP_tev0_raised = bool_false;
}

static void clearOutEvents(Proyecto* handle)
{
}

void proyectoIface_raise_evTECXNoOprimido(Proyecto* handle)
{
	handle->iface.evTECXNoOprimido_raised = bool_true;
}
void proyectoIface_raise_evTECXOprimido(Proyecto* handle, sc_integer value)
{
	handle->iface.evTECXOprimido_value = value;
	handle->iface.evTECXOprimido_raised = bool_true;
}
void proyectoIface_raise_inputRedFalse(Proyecto* handle)
{
	handle->iface.InputRedFalse_raised = bool_true;
}
void proyectoIface_raise_inputRedTrue(Proyecto* handle)
{
	handle->iface.InputRedTrue_raised = bool_true;
}
void proyectoIface_raise_showDisplay(Proyecto* handle)
{
	handle->iface.showDisplay_raised = bool_true;
}
void proyectoIface_raise_leerTemp(Proyecto* handle)
{
	handle->iface.leerTemp_raised = bool_true;
}


sc_integer proyectoIface_get_estadoLuz(const Proyecto* handle)
{
	return handle->iface.estadoLuz;
}
void proyectoIface_set_estadoLuz(Proyecto* handle, sc_integer value)
{
	handle->iface.estadoLuz = value;
}
sc_boolean proyectoIface_get_isGrupoOn(const Proyecto* handle)
{
	return handle->iface.isGrupoOn;
}
void proyectoIface_set_isGrupoOn(Proyecto* handle, sc_boolean value)
{
	handle->iface.isGrupoOn = value;
}
sc_boolean proyectoIface_get_isContactoOn(const Proyecto* handle)
{
	return handle->iface.isContactoOn;
}
void proyectoIface_set_isContactoOn(Proyecto* handle, sc_boolean value)
{
	handle->iface.isContactoOn = value;
}
sc_integer proyectoIface_get_modoGrupo(const Proyecto* handle)
{
	return handle->iface.modoGrupo;
}
void proyectoIface_set_modoGrupo(Proyecto* handle, sc_integer value)
{
	handle->iface.modoGrupo = value;
}
sc_boolean proyectoIface_get_grupoExito(const Proyecto* handle)
{
	return handle->iface.grupoExito;
}
void proyectoIface_set_grupoExito(Proyecto* handle, sc_boolean value)
{
	handle->iface.grupoExito = value;
}
sc_boolean proyectoIface_get_grupoFalla(const Proyecto* handle)
{
	return handle->iface.grupoFalla;
}
void proyectoIface_set_grupoFalla(Proyecto* handle, sc_boolean value)
{
	handle->iface.grupoFalla = value;
}
sc_integer proyectoIface_get_numDisplay(const Proyecto* handle)
{
	return handle->iface.numDisplay;
}
void proyectoIface_set_numDisplay(Proyecto* handle, sc_integer value)
{
	handle->iface.numDisplay = value;
}
sc_integer proyectoIface_get_conmutacionRed(const Proyecto* handle)
{
	return handle->iface.conmutacionRed;
}
void proyectoIface_set_conmutacionRed(Proyecto* handle, sc_integer value)
{
	handle->iface.conmutacionRed = value;
}
sc_integer proyectoIface_get_conmutacionGrupo(const Proyecto* handle)
{
	return handle->iface.conmutacionGrupo;
}
void proyectoIface_set_conmutacionGrupo(Proyecto* handle, sc_integer value)
{
	handle->iface.conmutacionGrupo = value;
}
sc_real proyectoIface_get_temperatura(const Proyecto* handle)
{
	return handle->iface.temperatura;
}
void proyectoIface_set_temperatura(Proyecto* handle, sc_real value)
{
	handle->iface.temperatura = value;
}
const sc_integer proyectoIface_get_lEDG(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_LEDG;
}
const sc_integer proyectoIface_get_lEDB(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_LEDB;
}
const sc_integer proyectoIface_get_lED1(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_LED1;
}
const sc_integer proyectoIface_get_lED2(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_LED2;
}
const sc_integer proyectoIface_get_lED3(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_LED3;
}
const sc_boolean proyectoIface_get_lED_ON(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_LED_ON;
}
const sc_boolean proyectoIface_get_lED_OFF(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_LED_OFF;
}
const sc_integer proyectoIface_get_tEC1(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_TEC1;
}
const sc_integer proyectoIface_get_tEC2(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_TEC2;
}
const sc_integer proyectoIface_get_tEC3(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_TEC3;
}
const sc_integer proyectoIface_get_tEC4(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_TEC4;
}
const sc_integer proyectoIface_get_gPIO1(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_GPIO1;
}
const sc_integer proyectoIface_get_gPIO2(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_GPIO2;
}
const sc_integer proyectoIface_get_gPIO3(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_GPIO3;
}
const sc_integer proyectoIface_get_gPIO5(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_GPIO5;
}
const sc_integer proyectoIface_get_gPIO7(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_GPIO7;
}
const sc_integer proyectoIface_get_mAX_ARR(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_MAX_ARR;
}
const sc_boolean proyectoIface_get_oUT_ON(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_OUT_ON;
}
const sc_boolean proyectoIface_get_oUT_OFF(const Proyecto* handle)
{
	return PROYECTO_PROYECTOIFACE_OUT_OFF;
}

/* implementations of all internal functions */

static sc_boolean check_TECX_DEBOUNCE_tr0_tr0(const Proyecto* handle)
{
	return handle->timeEvents.proyecto_TECX_DEBOUNCE_tev0_raised;
}

static sc_boolean check_TECX_NO_OPRIMIDO_tr0_tr0(const Proyecto* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean check_TECX_OPRIMIDO_tr0_tr0(const Proyecto* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean check_TECX_VALIDACION_tr0_tr0(const Proyecto* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean check_TECX_VALIDACION_tr1_tr1(const Proyecto* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean check_Teclas_ESPERA_tr0_tr0(const Proyecto* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PROYECTO_PROYECTOIFACE_TEC1)) ? bool_true : bool_false;
}

static sc_boolean check_Teclas_ESPERA_tr1_tr1(const Proyecto* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PROYECTO_PROYECTOIFACE_TEC2 && handle->iface.grupoExito == bool_false && handle->iface.modoGrupo == 1)) ? bool_true : bool_false;
}

static sc_boolean check_Teclas_ESPERA_tr2_tr2(const Proyecto* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PROYECTO_PROYECTOIFACE_TEC3 && handle->iface.modoGrupo == 1)) ? bool_true : bool_false;
}

static sc_boolean check_Teclas_ESPERA_tr3_tr3(const Proyecto* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PROYECTO_PROYECTOIFACE_TEC4 && handle->iface.modoGrupo == 1)) ? bool_true : bool_false;
}

static sc_boolean check_Modo_Grupo_MANUAL_tr0_tr0(const Proyecto* handle)
{
	return handle->internal.switchModo_raised;
}

static sc_boolean check_Modo_Grupo_AUTOMATICO_tr0_tr0(const Proyecto* handle)
{
	return handle->internal.switchModo_raised;
}

static sc_boolean check_Modo_Grupo_TRANSICION_MODOS_tr0_tr0(const Proyecto* handle)
{
	return ((handle->timeEvents.proyecto_Modo_Grupo_TRANSICION_MODOS_tev0_raised) && (handle->iface.modoGrupo == 1)) ? bool_true : bool_false;
}

static sc_boolean check_Modo_Grupo_TRANSICION_MODOS_tr1_tr1(const Proyecto* handle)
{
	return ((handle->timeEvents.proyecto_Modo_Grupo_TRANSICION_MODOS_tev1_raised) && (handle->iface.modoGrupo == 0)) ? bool_true : bool_false;
}

static sc_boolean check_Servicio_Red_HAY_LUZ_tr0_tr0(const Proyecto* handle)
{
	return handle->iface.InputRedFalse_raised;
}

static sc_boolean check_Servicio_Red_ESPERA_tr0_tr0(const Proyecto* handle)
{
	return handle->timeEvents.proyecto_Servicio_Red_ESPERA_tev0_raised;
}

static sc_boolean check_Servicio_Red_VALIDACION_tr0_tr0(const Proyecto* handle)
{
	return handle->iface.InputRedTrue_raised;
}

static sc_boolean check_Servicio_Red_VALIDACION_tr1_tr1(const Proyecto* handle)
{
	return handle->iface.InputRedFalse_raised;
}

static sc_boolean check_Servicio_Red_NO_HAY_LUZ_tr0_tr0(const Proyecto* handle)
{
	return handle->iface.InputRedTrue_raised;
}

static sc_boolean check_Grupo_Electrogeno_GRUPO_APAGADO_tr0_tr0(const Proyecto* handle)
{
	return handle->timeEvents.proyecto_Grupo_Electrogeno_GRUPO_APAGADO_tev0_raised;
}

static sc_boolean check_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr0_tr0(const Proyecto* handle)
{
	return ((handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev0_raised) && (handle->iface.isGrupoOn == bool_false && handle->internal.intentoArranque < PROYECTO_PROYECTOIFACE_MAX_ARR && handle->iface.modoGrupo == 0)) ? bool_true : bool_false;
}

static sc_boolean check_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr1_tr1(const Proyecto* handle)
{
	return ((handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev1_raised) && (handle->iface.isGrupoOn == bool_true)) ? bool_true : bool_false;
}

static sc_boolean check_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr2_tr2(const Proyecto* handle)
{
	return ((handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev2_raised) && (handle->iface.isGrupoOn == bool_false && handle->internal.intentoArranque >= PROYECTO_PROYECTOIFACE_MAX_ARR)) ? bool_true : bool_false;
}

static sc_boolean check_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr3_tr3(const Proyecto* handle)
{
	return ((handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev3_raised) && (handle->iface.isGrupoOn == bool_false && handle->iface.modoGrupo == 1)) ? bool_true : bool_false;
}

static sc_boolean check_Grupo_Electrogeno_ARRANQUE_EXITO_tr0_tr0(const Proyecto* handle)
{
	return ((handle->internal.siRedON_raised) && (handle->iface.modoGrupo == 0)) ? bool_true : bool_false;
}

static sc_boolean check_Grupo_Electrogeno_ARRANQUE_EXITO_tr1_tr1(const Proyecto* handle)
{
	return handle->internal.apagadoGrupo_raised;
}

static sc_boolean check_Grupo_Electrogeno_FALLA_tr0_tr0(const Proyecto* handle)
{
	return ((handle->internal.siRedON_raised) && (handle->iface.modoGrupo == 0)) ? bool_true : bool_false;
}

static sc_boolean check_Grupo_Electrogeno_FALLA_tr1_tr1(const Proyecto* handle)
{
	return handle->internal.apagadoGrupo_raised;
}

static sc_boolean check_Grupo_Electrogeno_INICIO_ARRANQUE_tr0_tr0(const Proyecto* handle)
{
	return handle->timeEvents.proyecto_Grupo_Electrogeno_INICIO_ARRANQUE_tev0_raised;
}

static sc_boolean check_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tr0_tr0(const Proyecto* handle)
{
	return ((handle->timeEvents.proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tev0_raised) && (handle->internal.intentoArranque < PROYECTO_PROYECTOIFACE_MAX_ARR && handle->iface.modoGrupo == 0)) ? bool_true : bool_false;
}

static sc_boolean check_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tr1_tr1(const Proyecto* handle)
{
	return ((handle->timeEvents.proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tev1_raised) && (handle->iface.modoGrupo == 1)) ? bool_true : bool_false;
}

static sc_boolean check_Grupo_Electrogeno_APAGANDO_GRUPO_tr0_tr0(const Proyecto* handle)
{
	return handle->timeEvents.proyecto_Grupo_Electrogeno_APAGANDO_GRUPO_tev0_raised;
}

static sc_boolean check_Grupo_Electrogeno_ESPERA_GRUPO_tr0_tr0(const Proyecto* handle)
{
	return handle->internal.arranqueGrupo_raised;
}

static sc_boolean check_Grupo_Electrogeno_ESPERA_GRUPO_tr1_tr1(const Proyecto* handle)
{
	return ((handle->internal.siRedOFF_raised) && (handle->iface.modoGrupo == 0)) ? bool_true : bool_false;
}

static sc_boolean check_Grupo_Electrogeno_CHEQUEO_APAGADO_tr0_tr0(const Proyecto* handle)
{
	return ((handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO_tev0_raised) && (handle->iface.isGrupoOn == bool_true)) ? bool_true : bool_false;
}

static sc_boolean check_Grupo_Electrogeno_CHEQUEO_APAGADO_tr1_tr1(const Proyecto* handle)
{
	return ((handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO_tev1_raised) && (handle->iface.isGrupoOn == bool_false)) ? bool_true : bool_false;
}

static sc_boolean check_Grupo_Electrogeno_FIN_ARRANQUE_tr0_tr0(const Proyecto* handle)
{
	return bool_true;
}

static sc_boolean check_Display_IDLE_lr0_lr0(const Proyecto* handle)
{
	return (handle->iface.numDisplay == 3) ? bool_true : bool_false;
}

static sc_boolean check_Display_IDLE_tr0_tr0(const Proyecto* handle)
{
	return ((handle->iface.showDisplay_raised) && (handle->iface.numDisplay < 3)) ? bool_true : bool_false;
}

static sc_boolean check_Display_MOSTRAR_VALORES_tr0_tr0(const Proyecto* handle)
{
	return handle->timeEvents.proyecto_Display_MOSTRAR_VALORES_tev0_raised;
}

static sc_boolean check_Conmutador_GRUPO_CONMUTADO_tr0_tr0(const Proyecto* handle)
{
	return handle->internal.conmutar_raised;
}

static sc_boolean check_Conmutador_GRUPO_CONMUTADO_tr1_tr1(const Proyecto* handle)
{
	return ((handle->internal.siRedON_raised) && (handle->iface.modoGrupo == 0)) ? bool_true : bool_false;
}

static sc_boolean check_Conmutador_RED_CONMUTADA_tr0_tr0(const Proyecto* handle)
{
	return ((handle->internal.conmutar_raised) && (handle->iface.grupoExito == bool_true)) ? bool_true : bool_false;
}

static sc_boolean check_Conmutador_RED_CONMUTADA_tr1_tr1(const Proyecto* handle)
{
	return ((handle->internal.conmutarAuto_raised) && (handle->iface.modoGrupo == 0)) ? bool_true : bool_false;
}

static sc_boolean check_Conmutador_SIN_CONMUTACION_tr0_tr0(const Proyecto* handle)
{
	return ((handle->timeEvents.proyecto_Conmutador_SIN_CONMUTACION_tev0_raised) && (handle->iface.conmutacionGrupo == 0 && handle->iface.conmutacionRed == 1)) ? bool_true : bool_false;
}

static sc_boolean check_Conmutador_SIN_CONMUTACION_tr1_tr1(const Proyecto* handle)
{
	return ((handle->timeEvents.proyecto_Conmutador_SIN_CONMUTACION_tev1_raised) && (handle->iface.conmutacionGrupo == 1 && handle->iface.conmutacionRed == 0)) ? bool_true : bool_false;
}

static sc_boolean check_Conmutador_CONMUTACION_INICIAL_tr0_tr0(const Proyecto* handle)
{
	return handle->internal.siRedON_raised;
}

static sc_boolean check_Sensor_Temp_IDLE_tr0_tr0(const Proyecto* handle)
{
	return handle->iface.leerTemp_raised;
}

static sc_boolean check_Sensor_Temp_LEYENDO_TEMP_tr0_tr0(const Proyecto* handle)
{
	return handle->timeEvents.proyecto_Sensor_Temp_LEYENDO_TEMP_tev0_raised;
}

static void effect_TECX_DEBOUNCE_tr0(Proyecto* handle)
{
	exseq_TECX_DEBOUNCE(handle);
	enseq_TECX_VALIDACION_default(handle);
}

static void effect_TECX_NO_OPRIMIDO_tr0(Proyecto* handle)
{
	exseq_TECX_NO_OPRIMIDO(handle);
	enseq_TECX_DEBOUNCE_default(handle);
}

static void effect_TECX_OPRIMIDO_tr0(Proyecto* handle)
{
	exseq_TECX_OPRIMIDO(handle);
	enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void effect_TECX_VALIDACION_tr0(Proyecto* handle)
{
	exseq_TECX_VALIDACION(handle);
	enseq_TECX_OPRIMIDO_default(handle);
}

static void effect_TECX_VALIDACION_tr1(Proyecto* handle)
{
	exseq_TECX_VALIDACION(handle);
	enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void effect_Teclas_ESPERA_tr0(Proyecto* handle)
{
	exseq_Teclas_ESPERA(handle);
	handle->internal.switchModo_raised = bool_true;
	enseq_Teclas_ESPERA_default(handle);
}

static void effect_Teclas_ESPERA_tr1(Proyecto* handle)
{
	exseq_Teclas_ESPERA(handle);
	handle->internal.arranqueGrupo_raised = bool_true;
	enseq_Teclas_ESPERA_default(handle);
}

static void effect_Teclas_ESPERA_tr2(Proyecto* handle)
{
	exseq_Teclas_ESPERA(handle);
	handle->internal.apagadoGrupo_raised = bool_true;
	enseq_Teclas_ESPERA_default(handle);
}

static void effect_Teclas_ESPERA_tr3(Proyecto* handle)
{
	exseq_Teclas_ESPERA(handle);
	handle->internal.conmutar_raised = bool_true;
	enseq_Teclas_ESPERA_default(handle);
}

static void effect_Modo_Grupo_MANUAL_tr0(Proyecto* handle)
{
	exseq_Modo_Grupo_MANUAL(handle);
	handle->iface.modoGrupo = 0;
	enseq_Modo_Grupo_TRANSICION_MODOS_default(handle);
}

static void effect_Modo_Grupo_AUTOMATICO_tr0(Proyecto* handle)
{
	exseq_Modo_Grupo_AUTOMATICO(handle);
	handle->iface.modoGrupo = 1;
	enseq_Modo_Grupo_TRANSICION_MODOS_default(handle);
}

static void effect_Modo_Grupo_TRANSICION_MODOS_tr0(Proyecto* handle)
{
	exseq_Modo_Grupo_TRANSICION_MODOS(handle);
	enseq_Modo_Grupo_MANUAL_default(handle);
}

static void effect_Modo_Grupo_TRANSICION_MODOS_tr1(Proyecto* handle)
{
	exseq_Modo_Grupo_TRANSICION_MODOS(handle);
	enseq_Modo_Grupo_AUTOMATICO_default(handle);
}

static void effect_Servicio_Red_HAY_LUZ_tr0(Proyecto* handle)
{
	exseq_Servicio_Red_HAY_LUZ(handle);
	enseq_Servicio_Red_ESPERA_default(handle);
}

static void effect_Servicio_Red_ESPERA_tr0(Proyecto* handle)
{
	exseq_Servicio_Red_ESPERA(handle);
	enseq_Servicio_Red_VALIDACION_default(handle);
}

static void effect_Servicio_Red_VALIDACION_tr0(Proyecto* handle)
{
	exseq_Servicio_Red_VALIDACION(handle);
	enseq_Servicio_Red_HAY_LUZ_default(handle);
}

static void effect_Servicio_Red_VALIDACION_tr1(Proyecto* handle)
{
	exseq_Servicio_Red_VALIDACION(handle);
	enseq_Servicio_Red_NO_HAY_LUZ_default(handle);
}

static void effect_Servicio_Red_NO_HAY_LUZ_tr0(Proyecto* handle)
{
	exseq_Servicio_Red_NO_HAY_LUZ(handle);
	enseq_Servicio_Red_ESPERA_default(handle);
}

static void effect_Grupo_Electrogeno_GRUPO_APAGADO_tr0(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_GRUPO_APAGADO(handle);
	enseq_Grupo_Electrogeno_ESPERA_GRUPO_default(handle);
}

static void effect_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr0(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(handle);
	enseq_Grupo_Electrogeno_INICIO_ARRANQUE_default(handle);
}

static void effect_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr1(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(handle);
	enseq_Grupo_Electrogeno_ARRANQUE_EXITO_default(handle);
}

static void effect_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr2(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(handle);
	enseq_Grupo_Electrogeno_FALLA_default(handle);
}

static void effect_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr3(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(handle);
	enseq_Grupo_Electrogeno_ESPERA_GRUPO_default(handle);
}

static void effect_Grupo_Electrogeno_ARRANQUE_EXITO_tr0(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_ARRANQUE_EXITO(handle);
	enseq_Grupo_Electrogeno_APAGANDO_GRUPO_default(handle);
}

static void effect_Grupo_Electrogeno_ARRANQUE_EXITO_tr1(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_ARRANQUE_EXITO(handle);
	enseq_Grupo_Electrogeno_APAGANDO_GRUPO_default(handle);
}

static void effect_Grupo_Electrogeno_FALLA_tr0(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_FALLA(handle);
	enseq_Grupo_Electrogeno_GRUPO_APAGADO_default(handle);
}

static void effect_Grupo_Electrogeno_FALLA_tr1(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_FALLA(handle);
	enseq_Grupo_Electrogeno_GRUPO_APAGADO_default(handle);
}

static void effect_Grupo_Electrogeno_INICIO_ARRANQUE_tr0(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_INICIO_ARRANQUE(handle);
	enseq_Grupo_Electrogeno_FIN_ARRANQUE_default(handle);
}

static void effect_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tr0(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_ESTABILIZACION_GRUPO(handle);
	handle->internal.intentoArranque += 1;
	enseq_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_default(handle);
}

static void effect_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tr1(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_ESTABILIZACION_GRUPO(handle);
	enseq_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_default(handle);
}

static void effect_Grupo_Electrogeno_APAGANDO_GRUPO_tr0(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_APAGANDO_GRUPO(handle);
	enseq_Grupo_Electrogeno_CHEQUEO_APAGADO_default(handle);
}

static void effect_Grupo_Electrogeno_ESPERA_GRUPO_tr0(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_ESPERA_GRUPO(handle);
	enseq_Grupo_Electrogeno_INICIO_ARRANQUE_default(handle);
}

static void effect_Grupo_Electrogeno_ESPERA_GRUPO_tr1(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_ESPERA_GRUPO(handle);
	enseq_Grupo_Electrogeno_INICIO_ARRANQUE_default(handle);
}

static void effect_Grupo_Electrogeno_CHEQUEO_APAGADO_tr0(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_CHEQUEO_APAGADO(handle);
	enseq_Grupo_Electrogeno_APAGANDO_GRUPO_default(handle);
}

static void effect_Grupo_Electrogeno_CHEQUEO_APAGADO_tr1(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_CHEQUEO_APAGADO(handle);
	enseq_Grupo_Electrogeno_GRUPO_APAGADO_default(handle);
}

static void effect_Grupo_Electrogeno_FIN_ARRANQUE_tr0(Proyecto* handle)
{
	exseq_Grupo_Electrogeno_FIN_ARRANQUE(handle);
	enseq_Grupo_Electrogeno_ESTABILIZACION_GRUPO_default(handle);
}

static void effect_Display_IDLE_lr0_lr0(Proyecto* handle)
{
	handle->iface.numDisplay = 0;
}

static void effect_Display_IDLE_tr0(Proyecto* handle)
{
	exseq_Display_IDLE(handle);
	handle->iface.numDisplay += 1;
	enseq_Display_MOSTRAR_VALORES_default(handle);
}

static void effect_Display_MOSTRAR_VALORES_tr0(Proyecto* handle)
{
	exseq_Display_MOSTRAR_VALORES(handle);
	enseq_Display_IDLE_default(handle);
}

static void effect_Conmutador_GRUPO_CONMUTADO_tr0(Proyecto* handle)
{
	exseq_Conmutador_GRUPO_CONMUTADO(handle);
	handle->iface.conmutacionRed = 1;
	handle->iface.conmutacionGrupo = 0;
	enseq_Conmutador_SIN_CONMUTACION_default(handle);
}

static void effect_Conmutador_GRUPO_CONMUTADO_tr1(Proyecto* handle)
{
	exseq_Conmutador_GRUPO_CONMUTADO(handle);
	handle->iface.conmutacionRed = 1;
	handle->iface.conmutacionGrupo = 0;
	enseq_Conmutador_SIN_CONMUTACION_default(handle);
}

static void effect_Conmutador_RED_CONMUTADA_tr0(Proyecto* handle)
{
	exseq_Conmutador_RED_CONMUTADA(handle);
	handle->iface.conmutacionRed = 0;
	handle->iface.conmutacionGrupo = 1;
	enseq_Conmutador_SIN_CONMUTACION_default(handle);
}

static void effect_Conmutador_RED_CONMUTADA_tr1(Proyecto* handle)
{
	exseq_Conmutador_RED_CONMUTADA(handle);
	handle->iface.conmutacionRed = 0;
	handle->iface.conmutacionGrupo = 1;
	enseq_Conmutador_SIN_CONMUTACION_default(handle);
}

static void effect_Conmutador_SIN_CONMUTACION_tr0(Proyecto* handle)
{
	exseq_Conmutador_SIN_CONMUTACION(handle);
	enseq_Conmutador_RED_CONMUTADA_default(handle);
}

static void effect_Conmutador_SIN_CONMUTACION_tr1(Proyecto* handle)
{
	exseq_Conmutador_SIN_CONMUTACION(handle);
	enseq_Conmutador_GRUPO_CONMUTADO_default(handle);
}

static void effect_Conmutador_CONMUTACION_INICIAL_tr0(Proyecto* handle)
{
	exseq_Conmutador_CONMUTACION_INICIAL(handle);
	enseq_Conmutador_RED_CONMUTADA_default(handle);
}

static void effect_Sensor_Temp_IDLE_tr0(Proyecto* handle)
{
	exseq_Sensor_Temp_IDLE(handle);
	enseq_Sensor_Temp_LEYENDO_TEMP_default(handle);
}

static void effect_Sensor_Temp_LEYENDO_TEMP_tr0(Proyecto* handle)
{
	exseq_Sensor_Temp_LEYENDO_TEMP(handle);
	enseq_Sensor_Temp_IDLE_default(handle);
}

/* Entry action for state 'DEBOUNCE'. */
static void enact_TECX_DEBOUNCE(Proyecto* handle)
{
	/* Entry action for state 'DEBOUNCE'. */
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_TECX_DEBOUNCE_tev0_raised) , 100, bool_false);
}

/* Entry action for state 'OPRIMIDO'. */
static void enact_TECX_OPRIMIDO(Proyecto* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siTECXOK_raised = bool_true;
	handle->internal.viTecla = handle->iface.evTECXOprimido_value;
}

/* Entry action for state 'MANUAL'. */
static void enact_Modo_Grupo_MANUAL(Proyecto* handle)
{
	/* Entry action for state 'MANUAL'. */
	proyectoIface_opLED(handle, PROYECTO_PROYECTOIFACE_LEDB, PROYECTO_PROYECTOIFACE_LED_OFF);
}

/* Entry action for state 'AUTOMATICO'. */
static void enact_Modo_Grupo_AUTOMATICO(Proyecto* handle)
{
	/* Entry action for state 'AUTOMATICO'. */
	proyectoIface_opLED(handle, PROYECTO_PROYECTOIFACE_LEDB, PROYECTO_PROYECTOIFACE_LED_ON);
}

/* Entry action for state 'TRANSICION_MODOS'. */
static void enact_Modo_Grupo_TRANSICION_MODOS(Proyecto* handle)
{
	/* Entry action for state 'TRANSICION_MODOS'. */
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Modo_Grupo_TRANSICION_MODOS_tev0_raised) , 1000, bool_false);
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Modo_Grupo_TRANSICION_MODOS_tev1_raised) , 1000, bool_false);
}

/* Entry action for state 'HAY_LUZ'. */
static void enact_Servicio_Red_HAY_LUZ(Proyecto* handle)
{
	/* Entry action for state 'HAY_LUZ'. */
	handle->internal.siRedON_raised = bool_true;
	proyectoIface_opLED(handle, PROYECTO_PROYECTOIFACE_LED1, PROYECTO_PROYECTOIFACE_LED_OFF);
	handle->iface.estadoLuz = 0;
}

/* Entry action for state 'ESPERA'. */
static void enact_Servicio_Red_ESPERA(Proyecto* handle)
{
	/* Entry action for state 'ESPERA'. */
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Servicio_Red_ESPERA_tev0_raised) , 1000, bool_false);
}

/* Entry action for state 'NO_HAY_LUZ'. */
static void enact_Servicio_Red_NO_HAY_LUZ(Proyecto* handle)
{
	/* Entry action for state 'NO_HAY_LUZ'. */
	handle->internal.siRedOFF_raised = bool_true;
	proyectoIface_opLED(handle, PROYECTO_PROYECTOIFACE_LED1, PROYECTO_PROYECTOIFACE_LED_ON);
	handle->iface.estadoLuz = 1;
}

/* Entry action for state 'GRUPO_APAGADO'. */
static void enact_Grupo_Electrogeno_GRUPO_APAGADO(Proyecto* handle)
{
	/* Entry action for state 'GRUPO_APAGADO'. */
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_GRUPO_APAGADO_tev0_raised) , 500, bool_false);
	proyectoIface_switchSalida(handle, PROYECTO_PROYECTOIFACE_GPIO1, PROYECTO_PROYECTOIFACE_OUT_OFF);
	proyectoIface_opLED(handle, PROYECTO_PROYECTOIFACE_LED2, PROYECTO_PROYECTOIFACE_LED_OFF);
	proyectoIface_opLED(handle, PROYECTO_PROYECTOIFACE_LEDG, PROYECTO_PROYECTOIFACE_LED_OFF);
	handle->iface.grupoExito = bool_false;
	handle->iface.grupoFalla = bool_false;
	handle->internal.intentoArranque = 0;
}

/* Entry action for state 'CHEQUEO_ENCENDIDO'. */
static void enact_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(Proyecto* handle)
{
	/* Entry action for state 'CHEQUEO_ENCENDIDO'. */
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev0_raised) , 1000, bool_false);
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev1_raised) , 1000, bool_false);
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev2_raised) , 1000, bool_false);
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev3_raised) , 1000, bool_false);
	handle->iface.isGrupoOn = proyectoIface_grupoStatus(handle, PROYECTO_PROYECTOIFACE_GPIO2);
}

/* Entry action for state 'ARRANQUE_EXITO'. */
static void enact_Grupo_Electrogeno_ARRANQUE_EXITO(Proyecto* handle)
{
	/* Entry action for state 'ARRANQUE_EXITO'. */
	handle->internal.conmutarAuto_raised = bool_true;
	handle->iface.grupoExito = bool_true;
}

/* Entry action for state 'FALLA'. */
static void enact_Grupo_Electrogeno_FALLA(Proyecto* handle)
{
	/* Entry action for state 'FALLA'. */
	handle->iface.grupoFalla = bool_true;
	proyectoIface_opLED(handle, PROYECTO_PROYECTOIFACE_LEDG, PROYECTO_PROYECTOIFACE_LED_ON);
}

/* Entry action for state 'INICIO_ARRANQUE'. */
static void enact_Grupo_Electrogeno_INICIO_ARRANQUE(Proyecto* handle)
{
	/* Entry action for state 'INICIO_ARRANQUE'. */
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_INICIO_ARRANQUE_tev0_raised) , 950, bool_false);
	proyectoIface_switchSalida(handle, PROYECTO_PROYECTOIFACE_GPIO1, PROYECTO_PROYECTOIFACE_OUT_ON);
	proyectoIface_opLED(handle, PROYECTO_PROYECTOIFACE_LED2, PROYECTO_PROYECTOIFACE_LED_ON);
}

/* Entry action for state 'ESTABILIZACION_GRUPO'. */
static void enact_Grupo_Electrogeno_ESTABILIZACION_GRUPO(Proyecto* handle)
{
	/* Entry action for state 'ESTABILIZACION_GRUPO'. */
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tev0_raised) , 5000, bool_false);
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tev1_raised) , 5000, bool_false);
}

/* Entry action for state 'APAGANDO_GRUPO'. */
static void enact_Grupo_Electrogeno_APAGANDO_GRUPO(Proyecto* handle)
{
	/* Entry action for state 'APAGANDO_GRUPO'. */
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_APAGANDO_GRUPO_tev0_raised) , 5000, bool_false);
	proyectoIface_switchSalida(handle, PROYECTO_PROYECTOIFACE_GPIO3, PROYECTO_PROYECTOIFACE_OUT_ON);
}

/* Entry action for state 'ESPERA_GRUPO'. */
static void enact_Grupo_Electrogeno_ESPERA_GRUPO(Proyecto* handle)
{
	/* Entry action for state 'ESPERA_GRUPO'. */
	proyectoIface_opLED(handle, PROYECTO_PROYECTOIFACE_LED2, PROYECTO_PROYECTOIFACE_LED_OFF);
}

/* Entry action for state 'CHEQUEO_APAGADO'. */
static void enact_Grupo_Electrogeno_CHEQUEO_APAGADO(Proyecto* handle)
{
	/* Entry action for state 'CHEQUEO_APAGADO'. */
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO_tev0_raised) , 500, bool_false);
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO_tev1_raised) , 1000, bool_false);
	handle->iface.isGrupoOn = proyectoIface_grupoStatus(handle, PROYECTO_PROYECTOIFACE_GPIO2);
	proyectoIface_switchSalida(handle, PROYECTO_PROYECTOIFACE_GPIO3, PROYECTO_PROYECTOIFACE_OUT_OFF);
}

/* Entry action for state 'FIN_ARRANQUE'. */
static void enact_Grupo_Electrogeno_FIN_ARRANQUE(Proyecto* handle)
{
	/* Entry action for state 'FIN_ARRANQUE'. */
	proyectoIface_switchSalida(handle, PROYECTO_PROYECTOIFACE_GPIO1, PROYECTO_PROYECTOIFACE_OUT_OFF);
}

/* Entry action for state 'MOSTRAR_VALORES'. */
static void enact_Display_MOSTRAR_VALORES(Proyecto* handle)
{
	/* Entry action for state 'MOSTRAR_VALORES'. */
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Display_MOSTRAR_VALORES_tev0_raised) , 1200, bool_false);
	proyectoIface_displayValores(handle);
}

/* Entry action for state 'GRUPO_CONMUTADO'. */
static void enact_Conmutador_GRUPO_CONMUTADO(Proyecto* handle)
{
	/* Entry action for state 'GRUPO_CONMUTADO'. */
	proyectoIface_opLED(handle, PROYECTO_PROYECTOIFACE_LED3, PROYECTO_PROYECTOIFACE_LED_ON);
	proyectoIface_switchSalida(handle, PROYECTO_PROYECTOIFACE_GPIO7, PROYECTO_PROYECTOIFACE_OUT_ON);
	handle->iface.conmutacionGrupo = 1;
}

/* Entry action for state 'RED_CONMUTADA'. */
static void enact_Conmutador_RED_CONMUTADA(Proyecto* handle)
{
	/* Entry action for state 'RED_CONMUTADA'. */
	proyectoIface_switchSalida(handle, PROYECTO_PROYECTOIFACE_GPIO5, PROYECTO_PROYECTOIFACE_OUT_ON);
	handle->iface.conmutacionRed = 1;
}

/* Entry action for state 'SIN_CONMUTACION'. */
static void enact_Conmutador_SIN_CONMUTACION(Proyecto* handle)
{
	/* Entry action for state 'SIN_CONMUTACION'. */
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Conmutador_SIN_CONMUTACION_tev0_raised) , 2000, bool_false);
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Conmutador_SIN_CONMUTACION_tev1_raised) , 2000, bool_false);
	proyectoIface_opLED(handle, PROYECTO_PROYECTOIFACE_LED3, PROYECTO_PROYECTOIFACE_LED_OFF);
	proyectoIface_switchSalida(handle, PROYECTO_PROYECTOIFACE_GPIO5, PROYECTO_PROYECTOIFACE_OUT_OFF);
	proyectoIface_switchSalida(handle, PROYECTO_PROYECTOIFACE_GPIO7, PROYECTO_PROYECTOIFACE_OUT_OFF);
}

/* Entry action for state 'CONMUTACION_INICIAL'. */
static void enact_Conmutador_CONMUTACION_INICIAL(Proyecto* handle)
{
	/* Entry action for state 'CONMUTACION_INICIAL'. */
	handle->iface.conmutacionRed = 0;
	handle->iface.conmutacionGrupo = 0;
	proyectoIface_switchSalida(handle, PROYECTO_PROYECTOIFACE_GPIO5, PROYECTO_PROYECTOIFACE_OUT_OFF);
	proyectoIface_switchSalida(handle, PROYECTO_PROYECTOIFACE_GPIO7, PROYECTO_PROYECTOIFACE_OUT_OFF);
}

/* Entry action for state 'LEYENDO_TEMP'. */
static void enact_Sensor_Temp_LEYENDO_TEMP(Proyecto* handle)
{
	/* Entry action for state 'LEYENDO_TEMP'. */
	proyecto_setTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Sensor_Temp_LEYENDO_TEMP_tev0_raised) , 500, bool_false);
	proyectoIface_guardarTemp(handle);
}

/* Exit action for state 'DEBOUNCE'. */
static void exact_TECX_DEBOUNCE(Proyecto* handle)
{
	/* Exit action for state 'DEBOUNCE'. */
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_TECX_DEBOUNCE_tev0_raised) );		
}

/* Exit action for state 'TRANSICION_MODOS'. */
static void exact_Modo_Grupo_TRANSICION_MODOS(Proyecto* handle)
{
	/* Exit action for state 'TRANSICION_MODOS'. */
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Modo_Grupo_TRANSICION_MODOS_tev0_raised) );		
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Modo_Grupo_TRANSICION_MODOS_tev1_raised) );		
}

/* Exit action for state 'ESPERA'. */
static void exact_Servicio_Red_ESPERA(Proyecto* handle)
{
	/* Exit action for state 'ESPERA'. */
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Servicio_Red_ESPERA_tev0_raised) );		
}

/* Exit action for state 'GRUPO_APAGADO'. */
static void exact_Grupo_Electrogeno_GRUPO_APAGADO(Proyecto* handle)
{
	/* Exit action for state 'GRUPO_APAGADO'. */
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_GRUPO_APAGADO_tev0_raised) );		
}

/* Exit action for state 'CHEQUEO_ENCENDIDO'. */
static void exact_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(Proyecto* handle)
{
	/* Exit action for state 'CHEQUEO_ENCENDIDO'. */
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev0_raised) );		
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev1_raised) );		
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev2_raised) );		
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tev3_raised) );		
}

/* Exit action for state 'INICIO_ARRANQUE'. */
static void exact_Grupo_Electrogeno_INICIO_ARRANQUE(Proyecto* handle)
{
	/* Exit action for state 'INICIO_ARRANQUE'. */
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_INICIO_ARRANQUE_tev0_raised) );		
}

/* Exit action for state 'ESTABILIZACION_GRUPO'. */
static void exact_Grupo_Electrogeno_ESTABILIZACION_GRUPO(Proyecto* handle)
{
	/* Exit action for state 'ESTABILIZACION_GRUPO'. */
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tev0_raised) );		
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tev1_raised) );		
}

/* Exit action for state 'APAGANDO_GRUPO'. */
static void exact_Grupo_Electrogeno_APAGANDO_GRUPO(Proyecto* handle)
{
	/* Exit action for state 'APAGANDO_GRUPO'. */
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_APAGANDO_GRUPO_tev0_raised) );		
}

/* Exit action for state 'CHEQUEO_APAGADO'. */
static void exact_Grupo_Electrogeno_CHEQUEO_APAGADO(Proyecto* handle)
{
	/* Exit action for state 'CHEQUEO_APAGADO'. */
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO_tev0_raised) );		
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO_tev1_raised) );		
}

/* Exit action for state 'MOSTRAR_VALORES'. */
static void exact_Display_MOSTRAR_VALORES(Proyecto* handle)
{
	/* Exit action for state 'MOSTRAR_VALORES'. */
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Display_MOSTRAR_VALORES_tev0_raised) );		
}

/* Exit action for state 'SIN_CONMUTACION'. */
static void exact_Conmutador_SIN_CONMUTACION(Proyecto* handle)
{
	/* Exit action for state 'SIN_CONMUTACION'. */
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Conmutador_SIN_CONMUTACION_tev0_raised) );		
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Conmutador_SIN_CONMUTACION_tev1_raised) );		
}

/* Exit action for state 'LEYENDO_TEMP'. */
static void exact_Sensor_Temp_LEYENDO_TEMP(Proyecto* handle)
{
	/* Exit action for state 'LEYENDO_TEMP'. */
	proyecto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.proyecto_Sensor_Temp_LEYENDO_TEMP_tev0_raised) );		
}

/* 'default' enter sequence for state DEBOUNCE */
static void enseq_TECX_DEBOUNCE_default(Proyecto* handle)
{
	/* 'default' enter sequence for state DEBOUNCE */
	enact_TECX_DEBOUNCE(handle);
	handle->stateConfVector[0] = Proyecto_TECX_DEBOUNCE;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void enseq_TECX_NO_OPRIMIDO_default(Proyecto* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Proyecto_TECX_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OPRIMIDO */
static void enseq_TECX_OPRIMIDO_default(Proyecto* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	enact_TECX_OPRIMIDO(handle);
	handle->stateConfVector[0] = Proyecto_TECX_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state VALIDACION */
static void enseq_TECX_VALIDACION_default(Proyecto* handle)
{
	/* 'default' enter sequence for state VALIDACION */
	handle->stateConfVector[0] = Proyecto_TECX_VALIDACION;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ESPERA */
static void enseq_Teclas_ESPERA_default(Proyecto* handle)
{
	/* 'default' enter sequence for state ESPERA */
	handle->stateConfVector[1] = Proyecto_Teclas_ESPERA;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state MANUAL */
static void enseq_Modo_Grupo_MANUAL_default(Proyecto* handle)
{
	/* 'default' enter sequence for state MANUAL */
	enact_Modo_Grupo_MANUAL(handle);
	handle->stateConfVector[2] = Proyecto_Modo_Grupo_MANUAL;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state AUTOMATICO */
static void enseq_Modo_Grupo_AUTOMATICO_default(Proyecto* handle)
{
	/* 'default' enter sequence for state AUTOMATICO */
	enact_Modo_Grupo_AUTOMATICO(handle);
	handle->stateConfVector[2] = Proyecto_Modo_Grupo_AUTOMATICO;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state TRANSICION_MODOS */
static void enseq_Modo_Grupo_TRANSICION_MODOS_default(Proyecto* handle)
{
	/* 'default' enter sequence for state TRANSICION_MODOS */
	enact_Modo_Grupo_TRANSICION_MODOS(handle);
	handle->stateConfVector[2] = Proyecto_Modo_Grupo_TRANSICION_MODOS;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state HAY_LUZ */
static void enseq_Servicio_Red_HAY_LUZ_default(Proyecto* handle)
{
	/* 'default' enter sequence for state HAY_LUZ */
	enact_Servicio_Red_HAY_LUZ(handle);
	handle->stateConfVector[3] = Proyecto_Servicio_Red_HAY_LUZ;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state ESPERA */
static void enseq_Servicio_Red_ESPERA_default(Proyecto* handle)
{
	/* 'default' enter sequence for state ESPERA */
	enact_Servicio_Red_ESPERA(handle);
	handle->stateConfVector[3] = Proyecto_Servicio_Red_ESPERA;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state VALIDACION */
static void enseq_Servicio_Red_VALIDACION_default(Proyecto* handle)
{
	/* 'default' enter sequence for state VALIDACION */
	handle->stateConfVector[3] = Proyecto_Servicio_Red_VALIDACION;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state NO_HAY_LUZ */
static void enseq_Servicio_Red_NO_HAY_LUZ_default(Proyecto* handle)
{
	/* 'default' enter sequence for state NO_HAY_LUZ */
	enact_Servicio_Red_NO_HAY_LUZ(handle);
	handle->stateConfVector[3] = Proyecto_Servicio_Red_NO_HAY_LUZ;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state GRUPO_APAGADO */
static void enseq_Grupo_Electrogeno_GRUPO_APAGADO_default(Proyecto* handle)
{
	/* 'default' enter sequence for state GRUPO_APAGADO */
	enact_Grupo_Electrogeno_GRUPO_APAGADO(handle);
	handle->stateConfVector[4] = Proyecto_Grupo_Electrogeno_GRUPO_APAGADO;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state CHEQUEO_ENCENDIDO */
static void enseq_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_default(Proyecto* handle)
{
	/* 'default' enter sequence for state CHEQUEO_ENCENDIDO */
	enact_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(handle);
	handle->stateConfVector[4] = Proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state ARRANQUE_EXITO */
static void enseq_Grupo_Electrogeno_ARRANQUE_EXITO_default(Proyecto* handle)
{
	/* 'default' enter sequence for state ARRANQUE_EXITO */
	enact_Grupo_Electrogeno_ARRANQUE_EXITO(handle);
	handle->stateConfVector[4] = Proyecto_Grupo_Electrogeno_ARRANQUE_EXITO;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state FALLA */
static void enseq_Grupo_Electrogeno_FALLA_default(Proyecto* handle)
{
	/* 'default' enter sequence for state FALLA */
	enact_Grupo_Electrogeno_FALLA(handle);
	handle->stateConfVector[4] = Proyecto_Grupo_Electrogeno_FALLA;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state INICIO_ARRANQUE */
static void enseq_Grupo_Electrogeno_INICIO_ARRANQUE_default(Proyecto* handle)
{
	/* 'default' enter sequence for state INICIO_ARRANQUE */
	enact_Grupo_Electrogeno_INICIO_ARRANQUE(handle);
	handle->stateConfVector[4] = Proyecto_Grupo_Electrogeno_INICIO_ARRANQUE;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state ESTABILIZACION_GRUPO */
static void enseq_Grupo_Electrogeno_ESTABILIZACION_GRUPO_default(Proyecto* handle)
{
	/* 'default' enter sequence for state ESTABILIZACION_GRUPO */
	enact_Grupo_Electrogeno_ESTABILIZACION_GRUPO(handle);
	handle->stateConfVector[4] = Proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state APAGANDO_GRUPO */
static void enseq_Grupo_Electrogeno_APAGANDO_GRUPO_default(Proyecto* handle)
{
	/* 'default' enter sequence for state APAGANDO_GRUPO */
	enact_Grupo_Electrogeno_APAGANDO_GRUPO(handle);
	handle->stateConfVector[4] = Proyecto_Grupo_Electrogeno_APAGANDO_GRUPO;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state ESPERA_GRUPO */
static void enseq_Grupo_Electrogeno_ESPERA_GRUPO_default(Proyecto* handle)
{
	/* 'default' enter sequence for state ESPERA_GRUPO */
	enact_Grupo_Electrogeno_ESPERA_GRUPO(handle);
	handle->stateConfVector[4] = Proyecto_Grupo_Electrogeno_ESPERA_GRUPO;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state CHEQUEO_APAGADO */
static void enseq_Grupo_Electrogeno_CHEQUEO_APAGADO_default(Proyecto* handle)
{
	/* 'default' enter sequence for state CHEQUEO_APAGADO */
	enact_Grupo_Electrogeno_CHEQUEO_APAGADO(handle);
	handle->stateConfVector[4] = Proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state FIN_ARRANQUE */
static void enseq_Grupo_Electrogeno_FIN_ARRANQUE_default(Proyecto* handle)
{
	/* 'default' enter sequence for state FIN_ARRANQUE */
	enact_Grupo_Electrogeno_FIN_ARRANQUE(handle);
	handle->stateConfVector[4] = Proyecto_Grupo_Electrogeno_FIN_ARRANQUE;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state IDLE */
static void enseq_Display_IDLE_default(Proyecto* handle)
{
	/* 'default' enter sequence for state IDLE */
	handle->stateConfVector[5] = Proyecto_Display_IDLE;
	handle->stateConfVectorPosition = 5;
}

/* 'default' enter sequence for state MOSTRAR_VALORES */
static void enseq_Display_MOSTRAR_VALORES_default(Proyecto* handle)
{
	/* 'default' enter sequence for state MOSTRAR_VALORES */
	enact_Display_MOSTRAR_VALORES(handle);
	handle->stateConfVector[5] = Proyecto_Display_MOSTRAR_VALORES;
	handle->stateConfVectorPosition = 5;
}

/* 'default' enter sequence for state GRUPO_CONMUTADO */
static void enseq_Conmutador_GRUPO_CONMUTADO_default(Proyecto* handle)
{
	/* 'default' enter sequence for state GRUPO_CONMUTADO */
	enact_Conmutador_GRUPO_CONMUTADO(handle);
	handle->stateConfVector[6] = Proyecto_Conmutador_GRUPO_CONMUTADO;
	handle->stateConfVectorPosition = 6;
}

/* 'default' enter sequence for state RED_CONMUTADA */
static void enseq_Conmutador_RED_CONMUTADA_default(Proyecto* handle)
{
	/* 'default' enter sequence for state RED_CONMUTADA */
	enact_Conmutador_RED_CONMUTADA(handle);
	handle->stateConfVector[6] = Proyecto_Conmutador_RED_CONMUTADA;
	handle->stateConfVectorPosition = 6;
}

/* 'default' enter sequence for state SIN_CONMUTACION */
static void enseq_Conmutador_SIN_CONMUTACION_default(Proyecto* handle)
{
	/* 'default' enter sequence for state SIN_CONMUTACION */
	enact_Conmutador_SIN_CONMUTACION(handle);
	handle->stateConfVector[6] = Proyecto_Conmutador_SIN_CONMUTACION;
	handle->stateConfVectorPosition = 6;
}

/* 'default' enter sequence for state CONMUTACION_INICIAL */
static void enseq_Conmutador_CONMUTACION_INICIAL_default(Proyecto* handle)
{
	/* 'default' enter sequence for state CONMUTACION_INICIAL */
	enact_Conmutador_CONMUTACION_INICIAL(handle);
	handle->stateConfVector[6] = Proyecto_Conmutador_CONMUTACION_INICIAL;
	handle->stateConfVectorPosition = 6;
}

/* 'default' enter sequence for state IDLE */
static void enseq_Sensor_Temp_IDLE_default(Proyecto* handle)
{
	/* 'default' enter sequence for state IDLE */
	handle->stateConfVector[7] = Proyecto_Sensor_Temp_IDLE;
	handle->stateConfVectorPosition = 7;
}

/* 'default' enter sequence for state LEYENDO_TEMP */
static void enseq_Sensor_Temp_LEYENDO_TEMP_default(Proyecto* handle)
{
	/* 'default' enter sequence for state LEYENDO_TEMP */
	enact_Sensor_Temp_LEYENDO_TEMP(handle);
	handle->stateConfVector[7] = Proyecto_Sensor_Temp_LEYENDO_TEMP;
	handle->stateConfVectorPosition = 7;
}

/* 'default' enter sequence for region TECX */
static void enseq_TECX_default(Proyecto* handle)
{
	/* 'default' enter sequence for region TECX */
	react_TECX__entry_Default(handle);
}

/* 'default' enter sequence for region Teclas */
static void enseq_Teclas_default(Proyecto* handle)
{
	/* 'default' enter sequence for region Teclas */
	react_Teclas__entry_Default(handle);
}

/* 'default' enter sequence for region Modo_Grupo */
static void enseq_Modo_Grupo_default(Proyecto* handle)
{
	/* 'default' enter sequence for region Modo_Grupo */
	react_Modo_Grupo__entry_Default(handle);
}

/* 'default' enter sequence for region Servicio_Red */
static void enseq_Servicio_Red_default(Proyecto* handle)
{
	/* 'default' enter sequence for region Servicio_Red */
	react_Servicio_Red__entry_Default(handle);
}

/* 'default' enter sequence for region Grupo_Electrogeno */
static void enseq_Grupo_Electrogeno_default(Proyecto* handle)
{
	/* 'default' enter sequence for region Grupo_Electrogeno */
	react_Grupo_Electrogeno__entry_Default(handle);
}

/* 'default' enter sequence for region Display */
static void enseq_Display_default(Proyecto* handle)
{
	/* 'default' enter sequence for region Display */
	react_Display__entry_Default(handle);
}

/* 'default' enter sequence for region Conmutador */
static void enseq_Conmutador_default(Proyecto* handle)
{
	/* 'default' enter sequence for region Conmutador */
	react_Conmutador__entry_Default(handle);
}

/* 'default' enter sequence for region Sensor_Temp */
static void enseq_Sensor_Temp_default(Proyecto* handle)
{
	/* 'default' enter sequence for region Sensor_Temp */
	react_Sensor_Temp__entry_Default(handle);
}

/* Default exit sequence for state DEBOUNCE */
static void exseq_TECX_DEBOUNCE(Proyecto* handle)
{
	/* Default exit sequence for state DEBOUNCE */
	handle->stateConfVector[0] = Proyecto_last_state;
	handle->stateConfVectorPosition = 0;
	exact_TECX_DEBOUNCE(handle);
}

/* Default exit sequence for state NO_OPRIMIDO */
static void exseq_TECX_NO_OPRIMIDO(Proyecto* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Proyecto_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state OPRIMIDO */
static void exseq_TECX_OPRIMIDO(Proyecto* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[0] = Proyecto_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state VALIDACION */
static void exseq_TECX_VALIDACION(Proyecto* handle)
{
	/* Default exit sequence for state VALIDACION */
	handle->stateConfVector[0] = Proyecto_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state ESPERA */
static void exseq_Teclas_ESPERA(Proyecto* handle)
{
	/* Default exit sequence for state ESPERA */
	handle->stateConfVector[1] = Proyecto_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state MANUAL */
static void exseq_Modo_Grupo_MANUAL(Proyecto* handle)
{
	/* Default exit sequence for state MANUAL */
	handle->stateConfVector[2] = Proyecto_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state AUTOMATICO */
static void exseq_Modo_Grupo_AUTOMATICO(Proyecto* handle)
{
	/* Default exit sequence for state AUTOMATICO */
	handle->stateConfVector[2] = Proyecto_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state TRANSICION_MODOS */
static void exseq_Modo_Grupo_TRANSICION_MODOS(Proyecto* handle)
{
	/* Default exit sequence for state TRANSICION_MODOS */
	handle->stateConfVector[2] = Proyecto_last_state;
	handle->stateConfVectorPosition = 2;
	exact_Modo_Grupo_TRANSICION_MODOS(handle);
}

/* Default exit sequence for state HAY_LUZ */
static void exseq_Servicio_Red_HAY_LUZ(Proyecto* handle)
{
	/* Default exit sequence for state HAY_LUZ */
	handle->stateConfVector[3] = Proyecto_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state ESPERA */
static void exseq_Servicio_Red_ESPERA(Proyecto* handle)
{
	/* Default exit sequence for state ESPERA */
	handle->stateConfVector[3] = Proyecto_last_state;
	handle->stateConfVectorPosition = 3;
	exact_Servicio_Red_ESPERA(handle);
}

/* Default exit sequence for state VALIDACION */
static void exseq_Servicio_Red_VALIDACION(Proyecto* handle)
{
	/* Default exit sequence for state VALIDACION */
	handle->stateConfVector[3] = Proyecto_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state NO_HAY_LUZ */
static void exseq_Servicio_Red_NO_HAY_LUZ(Proyecto* handle)
{
	/* Default exit sequence for state NO_HAY_LUZ */
	handle->stateConfVector[3] = Proyecto_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state GRUPO_APAGADO */
static void exseq_Grupo_Electrogeno_GRUPO_APAGADO(Proyecto* handle)
{
	/* Default exit sequence for state GRUPO_APAGADO */
	handle->stateConfVector[4] = Proyecto_last_state;
	handle->stateConfVectorPosition = 4;
	exact_Grupo_Electrogeno_GRUPO_APAGADO(handle);
}

/* Default exit sequence for state CHEQUEO_ENCENDIDO */
static void exseq_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(Proyecto* handle)
{
	/* Default exit sequence for state CHEQUEO_ENCENDIDO */
	handle->stateConfVector[4] = Proyecto_last_state;
	handle->stateConfVectorPosition = 4;
	exact_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(handle);
}

/* Default exit sequence for state ARRANQUE_EXITO */
static void exseq_Grupo_Electrogeno_ARRANQUE_EXITO(Proyecto* handle)
{
	/* Default exit sequence for state ARRANQUE_EXITO */
	handle->stateConfVector[4] = Proyecto_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for state FALLA */
static void exseq_Grupo_Electrogeno_FALLA(Proyecto* handle)
{
	/* Default exit sequence for state FALLA */
	handle->stateConfVector[4] = Proyecto_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for state INICIO_ARRANQUE */
static void exseq_Grupo_Electrogeno_INICIO_ARRANQUE(Proyecto* handle)
{
	/* Default exit sequence for state INICIO_ARRANQUE */
	handle->stateConfVector[4] = Proyecto_last_state;
	handle->stateConfVectorPosition = 4;
	exact_Grupo_Electrogeno_INICIO_ARRANQUE(handle);
}

/* Default exit sequence for state ESTABILIZACION_GRUPO */
static void exseq_Grupo_Electrogeno_ESTABILIZACION_GRUPO(Proyecto* handle)
{
	/* Default exit sequence for state ESTABILIZACION_GRUPO */
	handle->stateConfVector[4] = Proyecto_last_state;
	handle->stateConfVectorPosition = 4;
	exact_Grupo_Electrogeno_ESTABILIZACION_GRUPO(handle);
}

/* Default exit sequence for state APAGANDO_GRUPO */
static void exseq_Grupo_Electrogeno_APAGANDO_GRUPO(Proyecto* handle)
{
	/* Default exit sequence for state APAGANDO_GRUPO */
	handle->stateConfVector[4] = Proyecto_last_state;
	handle->stateConfVectorPosition = 4;
	exact_Grupo_Electrogeno_APAGANDO_GRUPO(handle);
}

/* Default exit sequence for state ESPERA_GRUPO */
static void exseq_Grupo_Electrogeno_ESPERA_GRUPO(Proyecto* handle)
{
	/* Default exit sequence for state ESPERA_GRUPO */
	handle->stateConfVector[4] = Proyecto_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for state CHEQUEO_APAGADO */
static void exseq_Grupo_Electrogeno_CHEQUEO_APAGADO(Proyecto* handle)
{
	/* Default exit sequence for state CHEQUEO_APAGADO */
	handle->stateConfVector[4] = Proyecto_last_state;
	handle->stateConfVectorPosition = 4;
	exact_Grupo_Electrogeno_CHEQUEO_APAGADO(handle);
}

/* Default exit sequence for state FIN_ARRANQUE */
static void exseq_Grupo_Electrogeno_FIN_ARRANQUE(Proyecto* handle)
{
	/* Default exit sequence for state FIN_ARRANQUE */
	handle->stateConfVector[4] = Proyecto_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for state IDLE */
static void exseq_Display_IDLE(Proyecto* handle)
{
	/* Default exit sequence for state IDLE */
	handle->stateConfVector[5] = Proyecto_last_state;
	handle->stateConfVectorPosition = 5;
}

/* Default exit sequence for state MOSTRAR_VALORES */
static void exseq_Display_MOSTRAR_VALORES(Proyecto* handle)
{
	/* Default exit sequence for state MOSTRAR_VALORES */
	handle->stateConfVector[5] = Proyecto_last_state;
	handle->stateConfVectorPosition = 5;
	exact_Display_MOSTRAR_VALORES(handle);
}

/* Default exit sequence for state GRUPO_CONMUTADO */
static void exseq_Conmutador_GRUPO_CONMUTADO(Proyecto* handle)
{
	/* Default exit sequence for state GRUPO_CONMUTADO */
	handle->stateConfVector[6] = Proyecto_last_state;
	handle->stateConfVectorPosition = 6;
}

/* Default exit sequence for state RED_CONMUTADA */
static void exseq_Conmutador_RED_CONMUTADA(Proyecto* handle)
{
	/* Default exit sequence for state RED_CONMUTADA */
	handle->stateConfVector[6] = Proyecto_last_state;
	handle->stateConfVectorPosition = 6;
}

/* Default exit sequence for state SIN_CONMUTACION */
static void exseq_Conmutador_SIN_CONMUTACION(Proyecto* handle)
{
	/* Default exit sequence for state SIN_CONMUTACION */
	handle->stateConfVector[6] = Proyecto_last_state;
	handle->stateConfVectorPosition = 6;
	exact_Conmutador_SIN_CONMUTACION(handle);
}

/* Default exit sequence for state CONMUTACION_INICIAL */
static void exseq_Conmutador_CONMUTACION_INICIAL(Proyecto* handle)
{
	/* Default exit sequence for state CONMUTACION_INICIAL */
	handle->stateConfVector[6] = Proyecto_last_state;
	handle->stateConfVectorPosition = 6;
}

/* Default exit sequence for state IDLE */
static void exseq_Sensor_Temp_IDLE(Proyecto* handle)
{
	/* Default exit sequence for state IDLE */
	handle->stateConfVector[7] = Proyecto_last_state;
	handle->stateConfVectorPosition = 7;
}

/* Default exit sequence for state LEYENDO_TEMP */
static void exseq_Sensor_Temp_LEYENDO_TEMP(Proyecto* handle)
{
	/* Default exit sequence for state LEYENDO_TEMP */
	handle->stateConfVector[7] = Proyecto_last_state;
	handle->stateConfVectorPosition = 7;
	exact_Sensor_Temp_LEYENDO_TEMP(handle);
}

/* Default exit sequence for region TECX */
static void exseq_TECX(Proyecto* handle)
{
	/* Default exit sequence for region TECX */
	/* Handle exit of all possible states (of proyecto.TECX) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Proyecto_TECX_DEBOUNCE :
		{
			exseq_TECX_DEBOUNCE(handle);
			break;
		}
		case Proyecto_TECX_NO_OPRIMIDO :
		{
			exseq_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Proyecto_TECX_OPRIMIDO :
		{
			exseq_TECX_OPRIMIDO(handle);
			break;
		}
		case Proyecto_TECX_VALIDACION :
		{
			exseq_TECX_VALIDACION(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Teclas */
static void exseq_Teclas(Proyecto* handle)
{
	/* Default exit sequence for region Teclas */
	/* Handle exit of all possible states (of proyecto.Teclas) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Proyecto_Teclas_ESPERA :
		{
			exseq_Teclas_ESPERA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Modo_Grupo */
static void exseq_Modo_Grupo(Proyecto* handle)
{
	/* Default exit sequence for region Modo_Grupo */
	/* Handle exit of all possible states (of proyecto.Modo_Grupo) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Proyecto_Modo_Grupo_MANUAL :
		{
			exseq_Modo_Grupo_MANUAL(handle);
			break;
		}
		case Proyecto_Modo_Grupo_AUTOMATICO :
		{
			exseq_Modo_Grupo_AUTOMATICO(handle);
			break;
		}
		case Proyecto_Modo_Grupo_TRANSICION_MODOS :
		{
			exseq_Modo_Grupo_TRANSICION_MODOS(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Servicio_Red */
static void exseq_Servicio_Red(Proyecto* handle)
{
	/* Default exit sequence for region Servicio_Red */
	/* Handle exit of all possible states (of proyecto.Servicio_Red) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Proyecto_Servicio_Red_HAY_LUZ :
		{
			exseq_Servicio_Red_HAY_LUZ(handle);
			break;
		}
		case Proyecto_Servicio_Red_ESPERA :
		{
			exseq_Servicio_Red_ESPERA(handle);
			break;
		}
		case Proyecto_Servicio_Red_VALIDACION :
		{
			exseq_Servicio_Red_VALIDACION(handle);
			break;
		}
		case Proyecto_Servicio_Red_NO_HAY_LUZ :
		{
			exseq_Servicio_Red_NO_HAY_LUZ(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Grupo_Electrogeno */
static void exseq_Grupo_Electrogeno(Proyecto* handle)
{
	/* Default exit sequence for region Grupo_Electrogeno */
	/* Handle exit of all possible states (of proyecto.Grupo_Electrogeno) at position 4... */
	switch(handle->stateConfVector[ 4 ])
	{
		case Proyecto_Grupo_Electrogeno_GRUPO_APAGADO :
		{
			exseq_Grupo_Electrogeno_GRUPO_APAGADO(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_CHEQUEO_ENCENDIDO :
		{
			exseq_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_ARRANQUE_EXITO :
		{
			exseq_Grupo_Electrogeno_ARRANQUE_EXITO(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_FALLA :
		{
			exseq_Grupo_Electrogeno_FALLA(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_INICIO_ARRANQUE :
		{
			exseq_Grupo_Electrogeno_INICIO_ARRANQUE(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_ESTABILIZACION_GRUPO :
		{
			exseq_Grupo_Electrogeno_ESTABILIZACION_GRUPO(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_APAGANDO_GRUPO :
		{
			exseq_Grupo_Electrogeno_APAGANDO_GRUPO(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_ESPERA_GRUPO :
		{
			exseq_Grupo_Electrogeno_ESPERA_GRUPO(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_CHEQUEO_APAGADO :
		{
			exseq_Grupo_Electrogeno_CHEQUEO_APAGADO(handle);
			break;
		}
		case Proyecto_Grupo_Electrogeno_FIN_ARRANQUE :
		{
			exseq_Grupo_Electrogeno_FIN_ARRANQUE(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Display */
static void exseq_Display(Proyecto* handle)
{
	/* Default exit sequence for region Display */
	/* Handle exit of all possible states (of proyecto.Display) at position 5... */
	switch(handle->stateConfVector[ 5 ])
	{
		case Proyecto_Display_IDLE :
		{
			exseq_Display_IDLE(handle);
			break;
		}
		case Proyecto_Display_MOSTRAR_VALORES :
		{
			exseq_Display_MOSTRAR_VALORES(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Conmutador */
static void exseq_Conmutador(Proyecto* handle)
{
	/* Default exit sequence for region Conmutador */
	/* Handle exit of all possible states (of proyecto.Conmutador) at position 6... */
	switch(handle->stateConfVector[ 6 ])
	{
		case Proyecto_Conmutador_GRUPO_CONMUTADO :
		{
			exseq_Conmutador_GRUPO_CONMUTADO(handle);
			break;
		}
		case Proyecto_Conmutador_RED_CONMUTADA :
		{
			exseq_Conmutador_RED_CONMUTADA(handle);
			break;
		}
		case Proyecto_Conmutador_SIN_CONMUTACION :
		{
			exseq_Conmutador_SIN_CONMUTACION(handle);
			break;
		}
		case Proyecto_Conmutador_CONMUTACION_INICIAL :
		{
			exseq_Conmutador_CONMUTACION_INICIAL(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Sensor_Temp */
static void exseq_Sensor_Temp(Proyecto* handle)
{
	/* Default exit sequence for region Sensor_Temp */
	/* Handle exit of all possible states (of proyecto.Sensor_Temp) at position 7... */
	switch(handle->stateConfVector[ 7 ])
	{
		case Proyecto_Sensor_Temp_IDLE :
		{
			exseq_Sensor_Temp_IDLE(handle);
			break;
		}
		case Proyecto_Sensor_Temp_LEYENDO_TEMP :
		{
			exseq_Sensor_Temp_LEYENDO_TEMP(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state DEBOUNCE. */
static void react_TECX_DEBOUNCE(Proyecto* handle)
{
	/* The reactions of state DEBOUNCE. */
	if (check_TECX_DEBOUNCE_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_DEBOUNCE_tr0(handle);
	} 
}

/* The reactions of state NO_OPRIMIDO. */
static void react_TECX_NO_OPRIMIDO(Proyecto* handle)
{
	/* The reactions of state NO_OPRIMIDO. */
	if (check_TECX_NO_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_NO_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state OPRIMIDO. */
static void react_TECX_OPRIMIDO(Proyecto* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (check_TECX_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state VALIDACION. */
static void react_TECX_VALIDACION(Proyecto* handle)
{
	/* The reactions of state VALIDACION. */
	if (check_TECX_VALIDACION_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_VALIDACION_tr0(handle);
	}  else
	{
		if (check_TECX_VALIDACION_tr1_tr1(handle) == bool_true)
		{ 
			effect_TECX_VALIDACION_tr1(handle);
		} 
	}
}

/* The reactions of state ESPERA. */
static void react_Teclas_ESPERA(Proyecto* handle)
{
	/* The reactions of state ESPERA. */
	if (check_Teclas_ESPERA_tr0_tr0(handle) == bool_true)
	{ 
		effect_Teclas_ESPERA_tr0(handle);
	}  else
	{
		if (check_Teclas_ESPERA_tr1_tr1(handle) == bool_true)
		{ 
			effect_Teclas_ESPERA_tr1(handle);
		}  else
		{
			if (check_Teclas_ESPERA_tr2_tr2(handle) == bool_true)
			{ 
				effect_Teclas_ESPERA_tr2(handle);
			}  else
			{
				if (check_Teclas_ESPERA_tr3_tr3(handle) == bool_true)
				{ 
					effect_Teclas_ESPERA_tr3(handle);
				} 
			}
		}
	}
}

/* The reactions of state MANUAL. */
static void react_Modo_Grupo_MANUAL(Proyecto* handle)
{
	/* The reactions of state MANUAL. */
	if (check_Modo_Grupo_MANUAL_tr0_tr0(handle) == bool_true)
	{ 
		effect_Modo_Grupo_MANUAL_tr0(handle);
	} 
}

/* The reactions of state AUTOMATICO. */
static void react_Modo_Grupo_AUTOMATICO(Proyecto* handle)
{
	/* The reactions of state AUTOMATICO. */
	if (check_Modo_Grupo_AUTOMATICO_tr0_tr0(handle) == bool_true)
	{ 
		effect_Modo_Grupo_AUTOMATICO_tr0(handle);
	} 
}

/* The reactions of state TRANSICION_MODOS. */
static void react_Modo_Grupo_TRANSICION_MODOS(Proyecto* handle)
{
	/* The reactions of state TRANSICION_MODOS. */
	if (check_Modo_Grupo_TRANSICION_MODOS_tr0_tr0(handle) == bool_true)
	{ 
		effect_Modo_Grupo_TRANSICION_MODOS_tr0(handle);
	}  else
	{
		if (check_Modo_Grupo_TRANSICION_MODOS_tr1_tr1(handle) == bool_true)
		{ 
			effect_Modo_Grupo_TRANSICION_MODOS_tr1(handle);
		} 
	}
}

/* The reactions of state HAY_LUZ. */
static void react_Servicio_Red_HAY_LUZ(Proyecto* handle)
{
	/* The reactions of state HAY_LUZ. */
	if (check_Servicio_Red_HAY_LUZ_tr0_tr0(handle) == bool_true)
	{ 
		effect_Servicio_Red_HAY_LUZ_tr0(handle);
	} 
}

/* The reactions of state ESPERA. */
static void react_Servicio_Red_ESPERA(Proyecto* handle)
{
	/* The reactions of state ESPERA. */
	if (check_Servicio_Red_ESPERA_tr0_tr0(handle) == bool_true)
	{ 
		effect_Servicio_Red_ESPERA_tr0(handle);
	} 
}

/* The reactions of state VALIDACION. */
static void react_Servicio_Red_VALIDACION(Proyecto* handle)
{
	/* The reactions of state VALIDACION. */
	if (check_Servicio_Red_VALIDACION_tr0_tr0(handle) == bool_true)
	{ 
		effect_Servicio_Red_VALIDACION_tr0(handle);
	}  else
	{
		if (check_Servicio_Red_VALIDACION_tr1_tr1(handle) == bool_true)
		{ 
			effect_Servicio_Red_VALIDACION_tr1(handle);
		} 
	}
}

/* The reactions of state NO_HAY_LUZ. */
static void react_Servicio_Red_NO_HAY_LUZ(Proyecto* handle)
{
	/* The reactions of state NO_HAY_LUZ. */
	if (check_Servicio_Red_NO_HAY_LUZ_tr0_tr0(handle) == bool_true)
	{ 
		effect_Servicio_Red_NO_HAY_LUZ_tr0(handle);
	} 
}

/* The reactions of state GRUPO_APAGADO. */
static void react_Grupo_Electrogeno_GRUPO_APAGADO(Proyecto* handle)
{
	/* The reactions of state GRUPO_APAGADO. */
	if (check_Grupo_Electrogeno_GRUPO_APAGADO_tr0_tr0(handle) == bool_true)
	{ 
		effect_Grupo_Electrogeno_GRUPO_APAGADO_tr0(handle);
	} 
}

/* The reactions of state CHEQUEO_ENCENDIDO. */
static void react_Grupo_Electrogeno_CHEQUEO_ENCENDIDO(Proyecto* handle)
{
	/* The reactions of state CHEQUEO_ENCENDIDO. */
	if (check_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr0(handle);
	}  else
	{
		if (check_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr1_tr1(handle) == bool_true)
		{ 
			effect_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr1(handle);
		}  else
		{
			if (check_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr2_tr2(handle) == bool_true)
			{ 
				effect_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr2(handle);
			}  else
			{
				if (check_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr3_tr3(handle) == bool_true)
				{ 
					effect_Grupo_Electrogeno_CHEQUEO_ENCENDIDO_tr3(handle);
				} 
			}
		}
	}
}

/* The reactions of state ARRANQUE_EXITO. */
static void react_Grupo_Electrogeno_ARRANQUE_EXITO(Proyecto* handle)
{
	/* The reactions of state ARRANQUE_EXITO. */
	if (check_Grupo_Electrogeno_ARRANQUE_EXITO_tr0_tr0(handle) == bool_true)
	{ 
		effect_Grupo_Electrogeno_ARRANQUE_EXITO_tr0(handle);
	}  else
	{
		if (check_Grupo_Electrogeno_ARRANQUE_EXITO_tr1_tr1(handle) == bool_true)
		{ 
			effect_Grupo_Electrogeno_ARRANQUE_EXITO_tr1(handle);
		} 
	}
}

/* The reactions of state FALLA. */
static void react_Grupo_Electrogeno_FALLA(Proyecto* handle)
{
	/* The reactions of state FALLA. */
	if (check_Grupo_Electrogeno_FALLA_tr0_tr0(handle) == bool_true)
	{ 
		effect_Grupo_Electrogeno_FALLA_tr0(handle);
	}  else
	{
		if (check_Grupo_Electrogeno_FALLA_tr1_tr1(handle) == bool_true)
		{ 
			effect_Grupo_Electrogeno_FALLA_tr1(handle);
		} 
	}
}

/* The reactions of state INICIO_ARRANQUE. */
static void react_Grupo_Electrogeno_INICIO_ARRANQUE(Proyecto* handle)
{
	/* The reactions of state INICIO_ARRANQUE. */
	if (check_Grupo_Electrogeno_INICIO_ARRANQUE_tr0_tr0(handle) == bool_true)
	{ 
		effect_Grupo_Electrogeno_INICIO_ARRANQUE_tr0(handle);
	} 
}

/* The reactions of state ESTABILIZACION_GRUPO. */
static void react_Grupo_Electrogeno_ESTABILIZACION_GRUPO(Proyecto* handle)
{
	/* The reactions of state ESTABILIZACION_GRUPO. */
	if (check_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tr0_tr0(handle) == bool_true)
	{ 
		effect_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tr0(handle);
	}  else
	{
		if (check_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tr1_tr1(handle) == bool_true)
		{ 
			effect_Grupo_Electrogeno_ESTABILIZACION_GRUPO_tr1(handle);
		} 
	}
}

/* The reactions of state APAGANDO_GRUPO. */
static void react_Grupo_Electrogeno_APAGANDO_GRUPO(Proyecto* handle)
{
	/* The reactions of state APAGANDO_GRUPO. */
	if (check_Grupo_Electrogeno_APAGANDO_GRUPO_tr0_tr0(handle) == bool_true)
	{ 
		effect_Grupo_Electrogeno_APAGANDO_GRUPO_tr0(handle);
	} 
}

/* The reactions of state ESPERA_GRUPO. */
static void react_Grupo_Electrogeno_ESPERA_GRUPO(Proyecto* handle)
{
	/* The reactions of state ESPERA_GRUPO. */
	if (check_Grupo_Electrogeno_ESPERA_GRUPO_tr0_tr0(handle) == bool_true)
	{ 
		effect_Grupo_Electrogeno_ESPERA_GRUPO_tr0(handle);
	}  else
	{
		if (check_Grupo_Electrogeno_ESPERA_GRUPO_tr1_tr1(handle) == bool_true)
		{ 
			effect_Grupo_Electrogeno_ESPERA_GRUPO_tr1(handle);
		} 
	}
}

/* The reactions of state CHEQUEO_APAGADO. */
static void react_Grupo_Electrogeno_CHEQUEO_APAGADO(Proyecto* handle)
{
	/* The reactions of state CHEQUEO_APAGADO. */
	if (check_Grupo_Electrogeno_CHEQUEO_APAGADO_tr0_tr0(handle) == bool_true)
	{ 
		effect_Grupo_Electrogeno_CHEQUEO_APAGADO_tr0(handle);
	}  else
	{
		if (check_Grupo_Electrogeno_CHEQUEO_APAGADO_tr1_tr1(handle) == bool_true)
		{ 
			effect_Grupo_Electrogeno_CHEQUEO_APAGADO_tr1(handle);
		} 
	}
}

/* The reactions of state FIN_ARRANQUE. */
static void react_Grupo_Electrogeno_FIN_ARRANQUE(Proyecto* handle)
{
	/* The reactions of state FIN_ARRANQUE. */
	effect_Grupo_Electrogeno_FIN_ARRANQUE_tr0(handle);
}

/* The reactions of state IDLE. */
static void react_Display_IDLE(Proyecto* handle)
{
	/* The reactions of state IDLE. */
	if (check_Display_IDLE_tr0_tr0(handle) == bool_true)
	{ 
		effect_Display_IDLE_tr0(handle);
	}  else
	{
		if (check_Display_IDLE_lr0_lr0(handle) == bool_true)
		{ 
			effect_Display_IDLE_lr0_lr0(handle);
		} 
	}
}

/* The reactions of state MOSTRAR_VALORES. */
static void react_Display_MOSTRAR_VALORES(Proyecto* handle)
{
	/* The reactions of state MOSTRAR_VALORES. */
	if (check_Display_MOSTRAR_VALORES_tr0_tr0(handle) == bool_true)
	{ 
		effect_Display_MOSTRAR_VALORES_tr0(handle);
	} 
}

/* The reactions of state GRUPO_CONMUTADO. */
static void react_Conmutador_GRUPO_CONMUTADO(Proyecto* handle)
{
	/* The reactions of state GRUPO_CONMUTADO. */
	if (check_Conmutador_GRUPO_CONMUTADO_tr0_tr0(handle) == bool_true)
	{ 
		effect_Conmutador_GRUPO_CONMUTADO_tr0(handle);
	}  else
	{
		if (check_Conmutador_GRUPO_CONMUTADO_tr1_tr1(handle) == bool_true)
		{ 
			effect_Conmutador_GRUPO_CONMUTADO_tr1(handle);
		} 
	}
}

/* The reactions of state RED_CONMUTADA. */
static void react_Conmutador_RED_CONMUTADA(Proyecto* handle)
{
	/* The reactions of state RED_CONMUTADA. */
	if (check_Conmutador_RED_CONMUTADA_tr0_tr0(handle) == bool_true)
	{ 
		effect_Conmutador_RED_CONMUTADA_tr0(handle);
	}  else
	{
		if (check_Conmutador_RED_CONMUTADA_tr1_tr1(handle) == bool_true)
		{ 
			effect_Conmutador_RED_CONMUTADA_tr1(handle);
		} 
	}
}

/* The reactions of state SIN_CONMUTACION. */
static void react_Conmutador_SIN_CONMUTACION(Proyecto* handle)
{
	/* The reactions of state SIN_CONMUTACION. */
	if (check_Conmutador_SIN_CONMUTACION_tr0_tr0(handle) == bool_true)
	{ 
		effect_Conmutador_SIN_CONMUTACION_tr0(handle);
	}  else
	{
		if (check_Conmutador_SIN_CONMUTACION_tr1_tr1(handle) == bool_true)
		{ 
			effect_Conmutador_SIN_CONMUTACION_tr1(handle);
		} 
	}
}

/* The reactions of state CONMUTACION_INICIAL. */
static void react_Conmutador_CONMUTACION_INICIAL(Proyecto* handle)
{
	/* The reactions of state CONMUTACION_INICIAL. */
	if (check_Conmutador_CONMUTACION_INICIAL_tr0_tr0(handle) == bool_true)
	{ 
		effect_Conmutador_CONMUTACION_INICIAL_tr0(handle);
	} 
}

/* The reactions of state IDLE. */
static void react_Sensor_Temp_IDLE(Proyecto* handle)
{
	/* The reactions of state IDLE. */
	if (check_Sensor_Temp_IDLE_tr0_tr0(handle) == bool_true)
	{ 
		effect_Sensor_Temp_IDLE_tr0(handle);
	} 
}

/* The reactions of state LEYENDO_TEMP. */
static void react_Sensor_Temp_LEYENDO_TEMP(Proyecto* handle)
{
	/* The reactions of state LEYENDO_TEMP. */
	if (check_Sensor_Temp_LEYENDO_TEMP_tr0_tr0(handle) == bool_true)
	{ 
		effect_Sensor_Temp_LEYENDO_TEMP_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void react_TECX__entry_Default(Proyecto* handle)
{
	/* Default react sequence for initial entry  */
	enseq_TECX_NO_OPRIMIDO_default(handle);
}

/* Default react sequence for initial entry  */
static void react_Teclas__entry_Default(Proyecto* handle)
{
	/* Default react sequence for initial entry  */
	enseq_Teclas_ESPERA_default(handle);
}

/* Default react sequence for initial entry  */
static void react_Modo_Grupo__entry_Default(Proyecto* handle)
{
	/* Default react sequence for initial entry  */
	enseq_Modo_Grupo_MANUAL_default(handle);
}

/* Default react sequence for initial entry  */
static void react_Servicio_Red__entry_Default(Proyecto* handle)
{
	/* Default react sequence for initial entry  */
	enseq_Servicio_Red_HAY_LUZ_default(handle);
}

/* Default react sequence for initial entry  */
static void react_Grupo_Electrogeno__entry_Default(Proyecto* handle)
{
	/* Default react sequence for initial entry  */
	enseq_Grupo_Electrogeno_ESPERA_GRUPO_default(handle);
}

/* Default react sequence for initial entry  */
static void react_Display__entry_Default(Proyecto* handle)
{
	/* Default react sequence for initial entry  */
	enseq_Display_IDLE_default(handle);
}

/* Default react sequence for initial entry  */
static void react_Conmutador__entry_Default(Proyecto* handle)
{
	/* Default react sequence for initial entry  */
	enseq_Conmutador_CONMUTACION_INICIAL_default(handle);
}

/* Default react sequence for initial entry  */
static void react_Sensor_Temp__entry_Default(Proyecto* handle)
{
	/* Default react sequence for initial entry  */
	enseq_Sensor_Temp_IDLE_default(handle);
}


