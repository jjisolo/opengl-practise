#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class CameraManager
{
public:
    CameraManager(glm::vec3 cameraPosition, glm::vec3 cameraVelocity)
        : m_CameraPosition(cameraPosition), m_CameraVelocity(cameraVelocity)
    {
        m_CameraUpVector    = glm::vec3(0.0f, 1.0f,  0.0f);
        m_CameraFrontVector = glm::vec3(0.0f, 0.0f, -1.0f);
    }

    const inline glm::vec3 getPosition() { return m_CameraPosition;    }

    const inline glm::vec3 getFront()    { return m_CameraFrontVector; }

    const inline glm::vec3 getUp()       { return m_CameraUpVector;    }

    inline void setFront(glm::vec3 newFront) { m_CameraFrontVector = newFront; }

    inline void setUp(glm::vec3 newUp) { m_CameraUpVector = newUp; }

    void inline moveRight(const float deltaTime) 
    {
        const float cameraSpeed = m_CameraVelocity.x * deltaTime;
        m_CameraPosition += glm::normalize(glm::cross(m_CameraFrontVector, m_CameraUpVector)) * cameraSpeed;
    }

    void inline moveLeft(const float deltaTime) 
    {
        const float cameraSpeed = m_CameraVelocity.x * deltaTime;
        m_CameraPosition -= glm::normalize(glm::cross(m_CameraFrontVector, m_CameraUpVector)) * cameraSpeed;
    }

    void inline moveUp(const float deltaTime) 
    {
        const float cameraSpeed = m_CameraVelocity.y * deltaTime;
        m_CameraPosition += cameraSpeed * m_CameraUpVector;
    }

    void inline moveDown(const float deltaTime) 
    {
        const float cameraSpeed = m_CameraVelocity.y * deltaTime;
        m_CameraPosition -= cameraSpeed * m_CameraUpVector;
    }

    void inline moveFront(const float deltaTime) 
    {
        const float cameraSpeed = m_CameraVelocity.z * deltaTime;
        m_CameraPosition += cameraSpeed * m_CameraFrontVector;
    }

    void inline moveBack(const float deltaTime) 
    {
        const float cameraSpeed = m_CameraVelocity.z * deltaTime;
        m_CameraPosition -= cameraSpeed * m_CameraFrontVector;
    }

private:
    glm::vec3 m_CameraVelocity;
    glm::vec3 m_CameraPosition;

    glm::vec3 m_CameraFrontVector;
    glm::vec3 m_CameraUpVector; 
};