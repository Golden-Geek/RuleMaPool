/*
  ==============================================================================

	ScreenOutput.h
	Created: 9 Nov 2023 8:51:23pm
	Author:  rosta

  ==============================================================================
*/

#pragma once

class Screen;
class Media;

class ScreenOutput :
	public Component,
	public OpenGLRenderer,
	public KeyListener
{
public:
	ScreenOutput(Screen* parent);
	~ScreenOutput();

	Screen* parentScreen;

	Point<float> posAtMouseDown;
	Point2DParameter* closestHandle;

	Array<Point2DParameter*> overlapHandles;
	void paint(Graphics& g) override;
	void paintOverChildren(Graphics&) override;

	void mouseDown(const MouseEvent& e) override;
	void mouseMove(const MouseEvent& e) override;
	void mouseDrag(const MouseEvent& e) override;
	void mouseUp(const MouseEvent& e) override;
	void mouseExit(const MouseEvent& e) override;

	Point<float> getRelativeMousePos();

	void goLive(int screenId);
	void stopLive();

	void newOpenGLContextCreated() override;
	void renderOpenGL() override;
	void openGLContextClosing() override;

	void userTriedToCloseWindow() override;

	void createAndLoadShaders();

	bool keyPressed(const KeyPress& key, Component* originatingComponent);
	static bool intersection(Point<float> p1, Point<float> p2, Point<float> p3, Point<float> p4, Point<float>* intersect); // should be in another objet

	std::unique_ptr<OpenGLShaderProgram> shader;
	juce::OpenGLContext openGLContext;
	Point<float> mousePos;
	Component* previousParent = nullptr;
	bool isLive = false;

	HashMap<Media*, std::shared_ptr<OpenGLTexture>> textures;
	HashMap<Media*, int> texturesVersions;
};