#include "PlayerCharacter.h"
#include "TextureManager.h"
#include "SDL.h"
#include "Input.h"
#include "CollisionHandler.h"
#include "Camera.h"


PlayerCharacter::PlayerCharacter(Properties* props) : Character(props)
{
    m_Collider = new Collider();\
    //Collider 
    m_Collider->SetBuffer(-8, -12, 0, 0);

    m_RigidBody = new RigidBody();
    
    m_Animation = new SpriteAnimation();
    m_Animation->SetProps(m_TextureID, 1, 1, 100);
}

void PlayerCharacter::Draw()
{
    m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);

    //Drawing Collider box
    Vector2D cam = Camera::GetInstance()->GetPosition();
    SDL_Rect box = m_Collider->GetBox();
    box.x -= cam.X;
    box.y -= cam.Y;
    SDL_RenderDrawRect(Engine::GetInstance()->GetRenderer(), &box);
}

void PlayerCharacter::Clean()
{
    TextureManager::GetInstance()->Clean();
}

void PlayerCharacter::Update(float dt)
{
   
   if (idle == 1)
   {
       m_Animation->SetProps("JackBack", 1, 1, 100);
   }
   else if ( idle == 2)
   {
       m_Animation->SetProps("Jack", 1, 1, 100);
   }
   else if (idle == 3)
   {
       m_Animation->SetProps("JackLeft", 1, 1, 100);
   }
   else if (idle == 4)
   {
       m_Animation->SetProps("JackRight", 1, 1, 100);
   }

   if (fishIdle >= 6)
   {
       m_Animation->SetProps("Jack_FishIdle", 1, 1, 100);
       
   }

   m_RigidBody->UnSetForce();

   //walking up
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_W) && !m_isFishing)
    {
        m_RigidBody->ApplyForceY(speed*UPWARD);
        m_Animation->SetProps("Jack_BackWalk", 1, 8, 100);
        fishIdle = 0;
        idle = 1;
    }
    //walking down
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_S) && !m_isFishing)
    {
        m_RigidBody->ApplyForceY(speed*DOWNWARD);
        m_Animation->SetProps("Jack_Walk", 1, 8, 100);
        fishIdle = 0;
        idle = 2;
    }
    //walking left
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A) && !m_isFishing)
    {
        m_RigidBody->ApplyForceX(speed*LEFTWARD);
        m_Animation->SetProps("Jack_LeftWalk", 1, 8, 100);
        fishIdle = 0;
        idle = 3;
    }
    //walking right
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D) && !m_isFishing)
    {
        m_RigidBody->ApplyForceX(speed*RIGHTWARD);
        m_Animation->SetProps("Jack_RightWalk", 1, 8, 100);
        fishIdle = 0;
        idle = 4;
    }

 

    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_F)) {
        m_isFishing = true;
        std::cout << fishIdle;
        fishIdle++;
    }
    else if (Input::GetInstance()->GetKeyUp(SDL_SCANCODE_F))
    {
        m_isFishing = false;
    }
    
   
    
    //Move on X Axis
    m_RigidBody->Update(dt);
    m_LastSafePosition.X = m_Transform->X;
    m_Transform->TranslateX(m_RigidBody->Position().X);
    m_Collider->SetBox(m_Transform->X, m_Transform->Y, 16, 16);

  if (CollisionHandler::GetInstance()->MapCollision(m_Collider->GetBox())) {
        m_Transform->X = m_LastSafePosition.X;
   }


    //Move on Y Axis
    m_RigidBody->Update(dt); 
    m_LastSafePosition.Y = m_Transform->Y;
    m_Transform->TranslateY(m_RigidBody->Position().Y);
    m_Collider->SetBox(m_Transform->X, m_Transform->Y, 16, 16);
    
    if (CollisionHandler::GetInstance()->MapCollision(m_Collider->GetBox())) {
        m_Transform->Y = m_LastSafePosition.Y;
    }

    m_Origin->X = m_Transform->X + m_Width / 2;
    m_Origin->Y = m_Transform->Y + m_Height / 2;

    AnimationState();
    m_Animation->Update(dt);
    
}

void PlayerCharacter::AnimationState()
{
    //fishing
    if (m_isFishing) {
        m_Animation->SetProps("Jack_Fishing", 1, 5, 100);   
    }
   


}
